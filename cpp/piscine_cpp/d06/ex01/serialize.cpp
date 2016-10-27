/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/01/13 19:33:05 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/15 21:56:36 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fstream>
#include <iostream>
#include <cstdlib>
#include <cstring>

struct        Data
{
	std::string str;
	int n;
	std::string ptr;
};

void *        serialize(void)
{
	int len = 8;
	std::string name = "";
	char range[255] = "qwertyuiopasdfghjklzxcvbnm1234567890QWERTYUIOPASDFGHJKLZXCVBNM";


	std::srand(time(0));
	while (len)
	{
		name += range[std::rand() % 62];
		len--;
	}
	len = 8;
	name += rand();
	while (len)
	{
		name += range[std::rand() % 62];
		len--;
	}
	name += '\0';
	return static_cast<void *>(const_cast<char *>(name.data()));
}

Data*        deserialize(void * raw)
{
	Data *data  = new Data;
	std::string raw_string(static_cast<char *>(raw));
	char * tmp = static_cast<char *>(raw);
	std::cout << "raw data : " << raw_string << std::endl;
	data->str = raw_string.substr(0, 8);
	data->n = tmp[9] << 24;
	data->n += tmp[10] << 16;
	data->n += tmp[11] << 8;
	data->n += tmp[12];
	data->ptr = raw_string.substr(9, 17);
	data->ptr[8] = '\0';
	return data;
}

int            main(void)
{
	Data * data = deserialize(serialize());
	std::cout << data->str << std::endl << data->n << std::endl << data->ptr << std::endl;
	delete(data);
	return 0;
}
