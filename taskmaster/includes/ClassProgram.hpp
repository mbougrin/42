/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClassProgram.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 11:42:48 by mbougrin          #+#    #+#             */
/*   Updated: 2016/12/15 15:29:41 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSPROGRAM_HPP
# define CLASSPROGRAM_HPP

# include <iostream>

class				ClassProgram
{
	public:
		ClassProgram();
		ClassProgram(ClassProgram const &src);
		ClassProgram &operator=(ClassProgram const &src);
		~ClassProgram();

	private:
};

#endif
