/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 17:13:05 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/18 17:13:05 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

template<typename T>
class	IMonitorDisplay
{
	public:
		IMonitorDisplay<T>() {}
		IMonitorDisplay<T>(IMonitorDisplay<T> const&) {}
		virtual ~IMonitorDisplay<T>() {}

		virtual int				accPosX() const = 0;
		virtual int				accPosY() const = 0;
		virtual int				accTailleX() const = 0;
		virtual int				accTailleY() const = 0;
		virtual unsigned int	accContenance() const = 0;
		virtual T				accValMin() const = 0;
		virtual T				accValMax() const = 0;
		virtual void			mutPos(int, int) = 0;
		virtual void			mutTaille(int, int) = 0;
		virtual void			mutValMin(T) = 0;
		virtual void			mutValMax(T) = 0;

		virtual IMonitorDisplay<T>&	operator=(IMonitorDisplay<T> const&) { return (*this); }
};

#endif
