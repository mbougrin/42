/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tintin_reporter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 09:10:15 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/30 11:27:48 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Tintin_reporter.hpp>

Tintin_reporter::Tintin_reporter(void)
{
	struct stat		st;
	fstream			fs;
	char			str[128];

	if (stat(LOGPATH, &st) == -1)
	   	mkdir(LOGPATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	if (stat(LOCKPATH, &st) == -1)
	   	mkdir(LOCKPATH, S_IRWXU | S_IRWXG | S_IROTH | S_IXOTH);
	strcat(str, LOCKPATH);
	strcat(str, LOCKNAME);
	fs.open(str, fstream::out);
	bzero(str, 128);
	fs.close();
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

	strcat(str, LOCKPATH);
	strcat(str, LOCKNAME);
	if (remove(str) != 0)
	{
		std::cout << "remove error" << std::endl;
		exit(-1);
	}
	bzero(str, 128);
	return ;
}

Tintin_reporter			&Tintin_reporter::operator=(Tintin_reporter const &src)
{
	if (this != &src)
	{

	}
	return (*this);
}

void				Tintin_reporter::writelog(string filename, string info, string str)
{
	fstream		fs;
	time_t 		now = time(0);
	tm 			*ltm = localtime(&now);

	fs.open(LOGPATH + filename, fstream::out | fstream::app);
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
