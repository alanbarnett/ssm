/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:03:32 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 07:22:50 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostnameModule.h"
#include "IMonitorDisplay.h"
#include <iostream>

// Constructors

HostnameModule::HostnameModule(const std::string &title)
{
	std::cout << "Hostname constructor called for " << title << std::endl;
	this->set_title(title);
}

HostnameModule::~HostnameModule(void)
{
	std::cout << "Hostname destructor called for " << this->get_title() \
		<< std::endl;
}

HostnameModule::HostnameModule(const HostnameModule& other)
{
	std::cout << "Hostname copy constructor called" << std::endl;
	*this = other;
}

HostnameModule&	HostnameModule::operator = (const HostnameModule& other)
{
	std::cout << "Hostname assignment operator called" << std::endl;
	this->set_title(other.get_title());
	return (*this);
}

// Other

void			HostnameModule::display(const IMonitorDisplay &display) const
{
	display.draw_line_2("hostname", "e1z2r3p10");
}
