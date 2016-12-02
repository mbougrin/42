/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tintin_reporter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:10:15 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/02 13:05:34 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Tintin_reporter.hpp>

int is_locked_socket ( int fd )
{
	static struct flock lock;
	lock.l_type = F_WRLCK;
	lock.l_whence = SEEK_SET;
	lock.l_start = 0;
	lock.l_len = 0;
	if ( fcntl ( fd , F_GETLK , &lock ) == -1 )
		 return -1;
	if ( lock.l_type == F_UNLCK )
		 return 0;
	else
		 return lock.l_pid;
}

Tintin_reporter::Tintin_reporter(void)
{
	struct stat		st;
//	fstream			fs;
	char			str[128];

	bzero(str, 128);
	if (stat(LOGPATH, &st) == -1)
	   	mkdir(LOGPATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (stat(LOCKPATH, &st) == -1)
	   	mkdir(LOCKPATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	strcat(str, LOCKPATH);
	strcat(str, LOCKNAME);
	writelog("INFO", "Started.");
//	fs.open(str, fstream::out);
//	fs.close();
//	close(_fd);
	if ((_fd = open(str, O_RDONLY | O_CREAT, 0640)) < 0)
	{
		std::cout << "open error" << std::endl;
		exit(-1);
	}	
//	close(_fd);
//	if ((_fd = open(str, O_RDONLY)) == -1)
//	{
//		std::cout << "open error" << std::endl;
//		exit(-1);
//	}

	if (is_locked_socket(_fd) != 0)
	{
		std::cout << "file is locked" << std::endl;
		exit(-1);
	}
//	if (flock(_fd, LOCK_SH | LOCK_NB) < 0)
//	{
//		std::cout << "file is locked" << std::endl;
//		close(_fd);
//		exit(-1);
//	}
	memset (&_lock, 0, sizeof(_lock));
	_lock.l_type = F_RDLCK;
	_lock.l_start = 0;
	_lock.l_whence = SEEK_SET;
	_lock.l_len = 0;
//	_lock.l_pid = getpid();
	fcntl (_fd, F_GETLK, &_lock);
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

	_lock.l_type = F_UNLCK;
	_lock.l_whence = SEEK_SET;
	_lock.l_start = 0;
	_lock.l_len = 0;
	fcntl (_fd, F_SETLKW, &_lock);
//	 if (flock(_fd, LOCK_UN) == -1)
//	 {
//		std::cout << "flock error" << std::endl;
//		exit(-1);
//	 }
	close(_fd);
	bzero(str, 128);
	strcat(str, LOCKPATH);
	strcat(str, LOCKNAME);
	writelog("INFO", "Quitting.");
	if (remove(str) != 0)
	{
		std::cout << "remove error" << std::endl;
		exit(-1);
	}
	return ;
}

Tintin_reporter			&Tintin_reporter::operator=(Tintin_reporter const &src)
{
	if (this != &src)
	{

	}
	return (*this);
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
		std::cout << "open error" <<std::endl;
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
