/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyNcurse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:32:19 by mbougrin          #+#    #+#             */
/*   Updated: 2016/10/10 15:52:59 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <main.h>

// 'p' key break time

static void	timeBreakKey(void)
{
	t_stc	*stc = singleton(NULL);

	stc->notWorkBool = !stc->notWorkBool;
	if (stc->notWorkBool == true)
		stc->clockBreak = clock();
	if (stc->notWorkBool == false)
		stc->notWorkTime += ((stc->clock / CLOCKS_PER_SEC) \
							- (stc->clockBreak / CLOCKS_PER_SEC));
}

//check key ncurse

void		checkKey(void)
{
	t_stc	*stc = singleton(NULL);

	if (stc->key == 112)
		timeBreakKey();
	if (stc->key == 115)
		save();
}
