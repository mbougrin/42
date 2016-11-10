/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/01 10:16:59 by mbougrin          #+#    #+#             */
/*   Updated: 2016/11/09 23:29:10 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include <libft.h>

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/ioctl.h>
# include <sys/time.h>

# include <signal.h>
# include <stdbool.h>
# include <fcntl.h>
# include <time.h>
# include <termios.h>

void						father(int pid_child);
void						child(void);

void						createptyandtty(void);
void						script(void);

void						sigchild(int sig);
void						sigwinch(int sig);
void						sigusr1(int sig);
void						ft_signal(int s, void (*func)(int));

void						initterm(void);
void						resetterm(void);

void						freeopt(void);
void						checkend(int pid);

void						gettimeerror(void);
void						openerror(void);
void						staterror(void);
void						ioctlerror(void);
void						forkerror(void);

void						writebegin(void);
void						writeend(void);

char						*ft_getenv(char *env);
void						ft_execve(void);

void						argparse(int ac, char **av, char **env);

typedef struct				s_opt
{
	bool					q;
	bool					initterm;
	int						pid;
	int						master;
	int						slave;
	int						fd;
	char					*filename;
	char					*path;
	char					*shell;
	char					**env;
	struct termios			term;
}							t_opt;

t_opt						*singleton(t_opt *opt);

#endif
