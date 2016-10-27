/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Class_network.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbougrin <mbougrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 03:57:55 by mbougrin          #+#    #+#             */
/*   Updated: 2015/04/19 10:13:47 by mbougrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Class_network.hpp"

Class_network::Class_network(void)
{
	return ;
}

Class_network::Class_network(Class_network const &src) { if (this != &src) { *this = src ; } return ; }

Class_network::~Class_network(void) { return ; }

long long		Class_network::ft_get_network(void) { return (this->_result); }

void			Class_network::ft_set_network(void)
{
	short 				network_layer;
	short 				link_layer;
	int 				mib[6];
	char 				*buf = NULL, *lim, *next;
	size_t 				len;
	struct if_msghdr 	*ifm;
	static int64_t 		prev_ipackets;
	static int64_t		prev_opackets;
	static int64_t		prev_ibytes;
	static int64_t		prev_obytes;
	int64_t				ipackets = 0;
	int64_t				opackets = 0;
	int64_t				ibytes = 0;
	int64_t				obytes = 0;
	std::string			str;

	mib[0] = CTL_NET;
	mib[1] = PF_ROUTE;
	mib[2] = 0;
	mib[3] = 0;
	mib[4] = NET_RT_IFLIST2;
	mib[5] = 0;
	if (sysctl(mib, 6, NULL, &len, NULL, 0) < 0)
	{
		this->_result = 0.0;
		return ;
	}
	str.resize(len);
	buf = const_cast<char*>(str.c_str());
	if (sysctl(mib, 6, buf, &len, NULL, 0) < 0)
	{
		if (buf) free(buf);
			this->_result = 0.0;
		return ;
	}
	lim = buf + len;
	for (next = buf; next < lim; )
	{
		network_layer = link_layer = 0;
		ifm = (struct if_msghdr *)next;
		next += ifm->ifm_msglen;
		if (ifm->ifm_type == RTM_IFINFO2)
		{
			struct if_msghdr2 *if2m = (struct if_msghdr2 *)ifm;
			if (if2m->ifm_data.ifi_type != 18)
			{
				opackets += if2m->ifm_data.ifi_opackets;
				ipackets += if2m->ifm_data.ifi_ipackets;
				obytes   += if2m->ifm_data.ifi_obytes;
				ibytes   += if2m->ifm_data.ifi_ibytes;
			}
		}
	}
	int64_t delta_obytes = obytes - prev_obytes;
	int64_t delta_ibytes = ibytes - prev_ibytes;
	prev_ipackets = ipackets;
	prev_opackets = opackets;
	prev_ibytes = ibytes;
	prev_obytes = obytes;
	this->_result = static_cast<long long>(delta_obytes + delta_ibytes);
}

Class_network&		Class_network::operator=(Class_network const &src) { if (this != &src) { } return *this; }
