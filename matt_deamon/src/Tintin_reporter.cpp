/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tintin_reporter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:10:15 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/02 17:10:58 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Tintin_reporter.hpp>

Tintin_reporter::Tintin_reporter(void)
{
	struct stat		st;
	char			str[128];

	bzero(str, 128);
	if (stat(LOGPATH, &st) == -1)
	   	mkdir(LOGPATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (stat(LOCKPATH, &st) == -1)
	   	mkdir(LOCKPATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	strcat(str, LOCKPATH);
	strcat(str, LOCKNAME);
	writelog("INFO", "Started.");
	if ((_fd = open(str, O_RDONLY | O_CREAT)) < 0)
	{
		writelog("ERROR", "Error open fail.");
		exit(-1);
	}	
	if (flock(_fd, LOCK_EX | LOCK_NB))
	{
		writelog("ERROR", "Error file is locked.");
		exit(-1);
	}

	pid_t 				child;

	child = fork();
	if (child < 0)
		exit(1);
	if (child > 0)
		exit(0);
	freopen( "/dev/null", "r", stdin);
	freopen( "/dev/null", "w", stdout);
	freopen( "/dev/null", "w", stderr);
	return ;
}

Tintin_reporter::Tintin_reporter(Tintin_reporter const &src)
{
	if (this != &src)
	{

	}
	return ;
}

Tintin_reporter::~Tintin_reporter(void)
{
	char			str[128];

	flock(_fd, LOCK_UN);
	close(_fd);
	bzero(str, 128);
	strcat(str, LOCKPATH);
	strcat(str, LOCKNAME);
	if (remove(str) != 0)
	{
		writelog("ERROR", "Error remove fail.");
		exit(-1);
	}
	writelog("INFO", "Quitting.");
	return ;
}

Tintin_reporter			&Tintin_reporter::operator=(Tintin_reporter const &src)
{
	if (this != &src)
	{	

	}
	return (*this);
}

const char *sigs[32] =
{
	NULL,
	"SIGHUP",
	"SIGINT",
	"SIGQUIT",
	"SIGILL",
	"SIGTRAP",
	"SIGABRT",
	"SIGBUS",
	"SIGFPE",
	"SIGKILL",
	"SIGUSR1",
	"SIGSEGV",
	"SIGUSR2",
	"SIGPIPE",
	"SIGALRM",
	"SIGTERM",
	"SIGSTKFLT",
	"SIGCHLD",
	"SIGCONT",
	"SIGSTOP",
	"SIGTSTP",
	"SIGTTIN",
	"SIGTTOU",
	"SIGURG",
	"SIGXCPU",
	"SIGXFSZ",
	"SIGVTALRM",
	"SIGPROF",
	"SIGWINCH",
	"SIGPWR",
	"SIGSYS",
};

void 					Tintin_reporter::sighandler(int nb)
{
	string		str;

	str = "Received a ";
   	str	+= sigs[nb];

	fstream		fs;
	time_t 		now = time(0);
	tm 			*ltm = localtime(&now);
	char		ptr[128];

	bzero(ptr, 128);
	strcat(ptr, LOGPATH);
	strcat(ptr, FILENAME);
	fs.open(ptr, fstream::out | fstream::app);
	if (!fs.is_open())
	{
		writelog("ERROR", "Error open fail.")
		exit(-1);
	}
	fs << "[" << ltm->tm_mday << "/" << ltm->tm_mon << "/" << 1900 + ltm->tm_year
		<< "-" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec
		<< "] [ " << "LOG" << " ] - " << NAME << ": " << str << "\n";
	fs.close();
	exit(-1);
}

void				Tintin_reporter::writelog(string info, string str)
{
	fstream		fs;
	time_t 		now = time(0);
	tm 			*ltm = localtime(&now);
	char		ptr[128];

	bzero(ptr, 128);
	strcat(ptr, LOGPATH);
	strcat(ptr, FILENAME);
	fs.open(ptr, fstream::out | fstream::app);
	if (!fs.is_open())
	{
		writelog("ERROR", "Error open fail.")
		exit(-1);
	}
	if (info == "INFO")
	{
		fs << "[" << ltm->tm_mday << "/" << ltm->tm_mon << "/" << 1900 + ltm->tm_year
			<< "-" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec
			<< "] [ " << info << " ] - " << NAME << ": " << str << "\n";
	}
	else if (info == "LOG")
	{
		fs << "[" << ltm->tm_mday << "/" << ltm->tm_mon << "/" << 1900 + ltm->tm_year
			<< "-" << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec
			<< "] [ " << info << " ] - " << NAME << ": " << str;
	}
	fs.close();
}
