/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_parse.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/31 13:46:43 by mbougrin          #+#    #+#             */
/*   Updated: 2015/02/09 11:20:51 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PARSE_HPP
# define CLASS_PARSE_HPP

# include <IOperand.hpp>
# include <list>

class		Class_parse
{
	public:
		Class_parse(void);
		Class_parse(Class_parse const &src);
		~Class_parse(void);

		IOperand const *createOperand(eOperandType type, std::string const &value) const;

		IOperand const *createInt8(std::string const &value) const;
		IOperand const *createInt16(std::string const &value) const;
		IOperand const *createInt32(std::string const &value) const;
		IOperand const *createFloat(std::string const &value) const;
		IOperand const *createDouble(std::string const &value) const;

		int						getNb(void);
		void					setNb(unsigned int nb);
		eOperandType			ft_type(char *type);
		void					ft_push(char *type, char *nb);
		void					ft_add(void);
		void					ft_sub(void);
		void					ft_mul(void);
		void					ft_div(void);
		void					ft_mod(void);
		void					ft_assert(char *type, char *nb);
		void					ft_pop(void);
		void					ft_dump(void);
		void					ft_print(void);
		void					ft_parse(std::string const &line);
		Class_parse&			operator=(Class_parse const &src);
		typedef IOperand const 	*(Class_parse::*fptr)(std::string const &) const;
	private:
		fptr							_ptr_function[6];
		std::list<IOperand const *>		_lst;
		int								_nb;
};

#endif
