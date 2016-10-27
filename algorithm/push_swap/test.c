/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/29 01:36:22 by mbougrin          #+#    #+#             */
/*   Updated: 2015/03/29 15:25:50 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "libft/includes/libft.h"
# include <limits.h>
# include <time.h>
 
# define NB 5000
# define NB_RAND INT_MAX

int				main(int ac, char **av, char **env)
{
	char	**tab;
	int		i;
	char	*tmp;
	int		j;

	i = 1;
	av = av;
	srand(time(NULL));
	if (ac > 1)
		return (0);
	tab = (char **)malloc(sizeof(char *) * (NB + 2));
	tab[0] = ft_strdup("push_swap");
	while (i < NB + 1)
	{
		tmp = ft_itoa(rand() % NB_RAND);
		if (i > 2)
		{
			j = 0;
			while (tab[j])
			{
				if (ft_strcmp(tab[j], tmp) == 0)
				{
					j = 0;
					ft_strdel(&tmp);
					tmp = ft_itoa(rand() % NB_RAND);
				}
				j++;
			}
			tab[i] = tmp;
		}
		else
			tab[i] = tmp;
		i++;
		tab[i] = NULL;
	}
	tab[i] = NULL;
	execve("./push_swap", tab, env);
	return (0);
}
