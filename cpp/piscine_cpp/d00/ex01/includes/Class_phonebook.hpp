/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_phonebook.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 09:23:32 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/06 16:14:53 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASS_PHONEBOOK_HPP
# define CLASS_PHONEBOOK_HPP

# include <iostream>

class		Class_phonebook
{
	public:
		Class_phonebook(void);
		Class_phonebook(Class_phonebook const &src);
		virtual ~Class_phonebook(void);

		void			ft_set_first_name(std::string line);
		std::string		ft_get_first_name(void);

		void			ft_set_last_name(std::string line);
		std::string		ft_get_last_name(void);

		void			ft_set_nickname(std::string line);
		std::string		ft_get_nickname(void);

		void			ft_set_login(std::string line);
		std::string		ft_get_login(void);

		void			ft_set_postal_address(std::string line);
		std::string		ft_get_postal_address(void);

		void			ft_set_email_address(std::string line);
		std::string		ft_get_email_address(void);

		void			ft_set_phone_number(std::string line);
		std::string		ft_get_phone_number(void);

		void			ft_set_birthday_date(std::string line);
		std::string		ft_get_birthday_date(void);

		void			ft_set_favorite_meal(std::string line);
		std::string		ft_get_favorite_meal(void);

		void			ft_set_underwear_color(std::string line);
		std::string		ft_get_underwear_color(void);

		void			ft_set_darkest_secret(std::string line);
		std::string		ft_get_darkest_secret(void);

		Class_phonebook&			operator=(Class_phonebook const &src);
	private:
		std::string			_first_name;
		std::string			_last_name;
		std::string			_nickname;
		std::string			_login;
		std::string			_postal_address;
		std::string			_email_address;
		std::string			_phone_number;
		std::string			_birthday_date;
		std::string			_favorite_meal;
		std::string			_underwear_color;
		std::string			_darkest_secret;
};

#endif
