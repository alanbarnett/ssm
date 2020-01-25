/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InfoModule.cc                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 08:15:03 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 08:19:43 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "InfoModule.h"
#include "IMonitorDisplay.h"
#include <iostream>

// Constructors

InfoModule::InfoModule(const std::string &title)
{
	std::cout << "Info constructor called for " << title << std::endl;
	this->set_title(title);
}

InfoModule::~InfoModule(void)
{
	std::cout << "Info destructor called for " << this->get_title() \
		<< std::endl;
}

InfoModule::InfoModule(const InfoModule& other)
{
	std::cout << "Info copy constructor called" << std::endl;
	*this = other;
}

InfoModule&	InfoModule::operator = (const InfoModule& other)
{
	std::cout << "Info assignment operator called" << std::endl;
	this->set_title(other.get_title());
	return (*this);
}

// Other

void			InfoModule::display(const IMonitorDisplay &display) const
{
	display.draw_line_2("user", "alan");
	display.draw_line_2("hostname", "e1z2r3p10");
	display.draw_line_separator('.');
	display.draw_bar("cpu", 45);
	display.draw_bar("cpu", 55);
}
