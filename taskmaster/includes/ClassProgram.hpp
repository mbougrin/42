/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassProgram.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:42:48 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/16 16:09:08 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSPROGRAM_HPP
# define CLASSPROGRAM_HPP

# include <iostream>
# include <list>

using namespace 			std;

class						ClassProgram
{
	public:
		ClassProgram(void);
		ClassProgram(ClassProgram const &src);
		ClassProgram &operator=(ClassProgram const &src);
		~ClassProgram(void);

		void				setName(const string &name);
		const string		&getName(void) const;
		void				setCmd(const string &cmd);
		const string		&getCmd(void) const;
		void				setProc(int nb);
		int					getProc(void) const;
		void				setUmask(mode_t mask);
		mode_t				getUmask(void) const;
		void				setWorkingdir(const string &str);
		const string		&getWorkingdir(void) const;
		void				setAutostart(bool autostart);
		bool				getAutostart(void) const;
		void				setExitcode(int nb);
		const list<int>		&getExitcode(void) const;
		void				setStartretry(int nb);
		int					getStartretry(void) const;
		void				setStarttime(int nb);
		int					getStarttime(void) const;
		void				setStoptime(int nb);
		int					getStoptime(void) const;
		void				setStopsignal(const string &str);
		const string		&getStopsignal(void) const;
		void				setStdin(const string &str);
		const string		&getStdin(void) const;
		void				setStderr(const string &str);
		const string		&getStderr(void) const;
		void				setEnv(const string &str);
		const list<string>	&getEnv(void) const;

		void				noleaks(void);
	private:
		string				*_name;
		string				*_cmd;
		int					_proc;
		mode_t				_umask;
		string				*_workingdir;
		bool				_autostart;
		std::list<int>		_exitcode;
		int					_startretry;
		int					_starttime;
		int					_stoptime;
		string				*_stopsignal;
		string				*_stdin;
		string				*_stderr;
		std::list<string>	_env;
};

#endif
