/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_phonebook.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/06 09:23:32 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/07 12:36:13 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <Class_phonebook.hpp>

Class_phonebook::Class_phonebook(void) { return ; }

Class_phonebook::Class_phonebook(Class_phonebook const &src) { if (this != &src) { } return ; }

Class_phonebook::~Class_phonebook(void) { return ; }

Class_phonebook&		Class_phonebook::operator=(Class_phonebook const &src) { if (this != &src) { } return *this; }

void					Class_phonebook::ft_set_first_name(std::string line) { this->_first_name = line; }
std::string				Class_phonebook::ft_get_first_name(void) { return this->_first_name; }

void					Class_phonebook::ft_set_last_name(std::string line) { this->_last_name = line; }
std::string				Class_phonebook::ft_get_last_name(void) { return this->_last_name; }

void					Class_phonebook::ft_set_nickname(std::string line) { this->_nickname = line; }
std::string				Class_phonebook::ft_get_nickname(void) { return this->_nickname; }

void					Class_phonebook::ft_set_login(std::string line) { this->_login = line; }
std::string				Class_phonebook::ft_get_login(void) { return this->_login; }

void					Class_phonebook::ft_set_postal_address(std::string line) { this->_postal_address = line; }
std::string				Class_phonebook::ft_get_postal_address(void) { return this->_postal_address; }

void					Class_phonebook::ft_set_email_address(std::string line) { this->_email_address = line; }
std::string				Class_phonebook::ft_get_email_address(void) { return this->_email_address; }

void					Class_phonebook::ft_set_phone_number(std::string line) { this->_phone_number = line; }
std::string				Class_phonebook::ft_get_phone_number(void) { return this->_phone_number; }

void					Class_phonebook::ft_set_birthday_date(std::string line) { this->_birthday_date = line; }
std::string				Class_phonebook::ft_get_birthday_date(void) { return this->_birthday_date; }

void					Class_phonebook::ft_set_favorite_meal(std::string line) { this->_favorite_meal = line; }
std::string				Class_phonebook::ft_get_favorite_meal(void) { return this->_favorite_meal; }

void					Class_phonebook::ft_set_underwear_color(std::string line) { this->_underwear_color = line; }
std::string				Class_phonebook::ft_get_underwear_color(void) { return this->_underwear_color; }

void					Class_phonebook::ft_set_darkest_secret(std::string line) { this->_darkest_secret = line; }
std::string				Class_phonebook::ft_get_darkest_secret(void) { return this->_darkest_secret; }

void			ft_add(Class_phonebook tab[8], int count)
{
	std::string		line;

	std::cout << "Enter First Name:";
	std::getline (std::cin, line);
	if (std::cin.eof())
		exit(0);
	tab[count].ft_set_first_name(line);

	std::cout << "Enter Last Name:";
	std::getline (std::cin, line);
	if (std::cin.eof())
		exit(0);
	tab[count].ft_set_last_name(line);

	std::cout << "Enter Nickname:";
	std::getline (std::cin, line);
	if (std::cin.eof())
		exit(0);
	tab[count].ft_set_nickname(line);

	std::cout << "Enter Login:";
	std::getline (std::cin, line);
	if (std::cin.eof())
		exit(0);
	tab[count].ft_set_login(line);

	std::cout << "Enter Postal Address:";
	std::getline (std::cin, line);
	if (std::cin.eof())
		exit(0);
	tab[count].ft_set_postal_address(line);

	std::cout << "Enter Email Address:";
	std::getline (std::cin, line);
	if (std::cin.eof())
		exit(0);
	tab[count].ft_set_email_address(line);

	std::cout << "Enter Phone Number:";
	std::getline (std::cin, line);
	if (std::cin.eof())
		exit(0);
	tab[count].ft_set_phone_number(line);

	std::cout << "Enter Birthday Date:";
	std::getline (std::cin, line);
	if (std::cin.eof())
		exit(0);
	tab[count].ft_set_birthday_date(line);

	std::cout << "Enter Favorite Meal:";
	std::getline (std::cin, line);
	if (std::cin.eof())
		exit(0);
	tab[count].ft_set_favorite_meal(line);

	std::cout << "Enter Underwear Color:";
	std::getline (std::cin, line);
	if (std::cin.eof())
		exit(0);
	tab[count].ft_set_underwear_color(line);

	std::cout << "Enter Darkest Secret:";
	std::getline (std::cin, line);
	if (std::cin.eof())
		exit(0);
	tab[count].ft_set_darkest_secret(line);
}

void			ft_print(const char *str)
{
	int			len;
	int			i;

	if (strlen(str) > 10)
	{
		i = 0;
		while (str[i])
		{
			if (i == 9)
				break ;
			std::cout << str[i];
			i++;
		}
		std::cout << ".";
	}
	else
	{
		len = 10 - strlen(str);
		while (len > 0)
		{
			std::cout << " ";
			len--;
		}
		std::cout << str;	
	}
}

void			ft_search(Class_phonebook *tab, int count)
{
	int					i;
	std::string			line;
	int					nb;

	i = 0;
	nb = 0;
	if (count == 0)
	{
		std::cout << "Empty phonebook" << std::endl;
		return ;
	}
	while (i < count)
	{
		std::cout << "         " << i << "|";
		ft_print(tab[i].ft_get_first_name().c_str());
		std::cout << "|";
		ft_print(tab[i].ft_get_last_name().c_str());
		std::cout << "|";
		ft_print(tab[i].ft_get_nickname().c_str());
		std::cout << "|";
		std::cout << std::endl;
		i++;
	}
	while (1)
	{
		std::cout << "Enter index:";
		std::getline (std::cin, line);
		if (std::cin.eof())
			exit(0);
		nb = atoi(line.c_str());
		if (line == "")
			std::cout << "Line empty" << std::endl;
		else if (nb >= 0 && nb <= 7 && nb < count)
			break ;
		else
			std::cout << "Not a good index" << std::endl;
	}
	std::cout << "First Name:";
	std::cout << tab[nb].ft_get_first_name() << std::endl;
	std::cout << "Last Name:";
	std::cout << tab[nb].ft_get_last_name() << std::endl;
	std::cout << "Nickname:";
	std::cout << tab[nb].ft_get_nickname() << std::endl;
	std::cout << "Login:";
	std::cout << tab[nb].ft_get_login() << std::endl;
	std::cout << "Postal Address:";
	std::cout << tab[nb].ft_get_postal_address() << std::endl;
	std::cout << "Email Address:";
	std::cout << tab[nb].ft_get_email_address() << std::endl;
	std::cout << "Phone Number:";
	std::cout << tab[nb].ft_get_phone_number() << std::endl;
	std::cout << "Birthday Date:";
	std::cout << tab[nb].ft_get_birthday_date() << std::endl;
	std::cout << "Favorite Meal:";
	std::cout << tab[nb].ft_get_favorite_meal() << std::endl;
	std::cout << "Underwear Color:";
	std::cout << tab[nb].ft_get_underwear_color() << std::endl;
	std::cout << "Darkest Secret:";
	std::cout << tab[nb].ft_get_darkest_secret() << std::endl;
}

int				main(void)
{
	std::string					line;
	Class_phonebook				tab[8];
	static int					count;

	while (1)
	{
		std::getline (std::cin, line);
		if (line == "exit" || line == "EXIT" || std::cin.eof())
			break ;
		else if (count > 7 && (line == "ADD" || line == "add"))
			std::cout << "Full contact" << std::endl;
		else if (line == "ADD" || line == "add")
		{
			ft_add(tab, count);
			count++;
		}
		else if (line == "SEARCH" || line == "search")
			ft_search(tab, count);
		else
			std::cout << "bad command" << std::endl;
	}
	return (0);
}
