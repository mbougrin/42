/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prot.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/12 14:26:26 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/09 16:06:31 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

static char			ft_prot_first(struct stat stt)
{
	if ((stt.st_mode & S_IFMT) == S_IFLNK)
		return ('l');
	if ((stt.st_mode & S_IFMT) == S_IFBLK)
		return ('b');
	if ((stt.st_mode & S_IFMT) == S_IFCHR)
		return ('c');
	if ((stt.st_mode & S_IFMT) == S_IFDIR)
		return ('d');
	if ((stt.st_mode & S_IFMT) == S_IFIFO)
		return ('p');
	if ((stt.st_mode & S_IFMT) == S_IFREG)
		return ('-');
	if ((stt.st_mode & S_IFMT) == S_IFSOCK)
		return ('s');
	return ('-');
}

static void			ft_prot_user(char **result, struct stat stt)
{
	if (stt.st_mode & S_IRUSR)
		result[0][1] = 'r';
	else
		result[0][1] = '-';
	if (stt.st_mode & S_IWUSR)
		result[0][2] = 'w';
	else
		result[0][2] = '-';
	if (stt.st_mode & S_IXUSR)
		result[0][3] = 'x';
	else
		result[0][3] = '-';
	if (stt.st_mode & S_ISUID)
		result[0][3] = (stt.st_mode & S_IXUSR) ? 's' : 'S';
}

static void			ft_prot_group(char **result, struct stat stt)
{
	if (stt.st_mode & S_IRGRP)
		result[0][4] = 'r';
	else
		result[0][4] = '-';
	if (stt.st_mode & S_IWGRP)
		result[0][5] = 'w';
	else
		result[0][5] = '-';
	if (stt.st_mode & S_IXGRP)
		result[0][6] = 'x';
	else
		result[0][6] = '-';
	if (stt.st_mode & S_ISGID)
		result[0][6] = (stt.st_mode & S_IXGRP) ? 's' : 'S';
}

static void			ft_prot_other(char **result, struct stat stt)
{
	if (stt.st_mode & S_IROTH)
		result[0][7] = 'r';
	else
		result[0][7] = '-';
	if (stt.st_mode & S_IWOTH)
		result[0][8] = 'w';
	else
		result[0][8] = '-';
	if (stt.st_mode & S_IXOTH)
		result[0][9] = 'x';
	else
		result[0][9] = '-';
	if (stt.st_mode & S_ISVTX)
		result[0][9] = (stt.st_mode & S_IXUSR) ? 't' : 'T';
}

char				*ft_prot(struct stat stt)
{
	char	*result;

	if ((result = (char *)malloc(sizeof(char) * 10)) == NULL)
		return (NULL);
	result[0] = ft_prot_first(stt);
	ft_prot_user(&result, stt);
	ft_prot_group(&result, stt);
	ft_prot_other(&result, stt);
	result[10] = '\0';
	return (result);
}
