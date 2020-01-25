/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:24:43 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 03:40:11 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.h"
#include "IMonitorDisplay.h"
#include <iostream>
#include <string>

// Constructors

IMonitorModule::IMonitorModule(const std::string &title)
{
	std::cout << "Default constructor called for " << title << std::endl;
	_title = title;
}

IMonitorModule::~IMonitorModule(void)
{
	std::cout << "Destructor called for " << _title << std::endl;
}

IMonitorModule::IMonitorModule(const IMonitorModule& other)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

IMonitorModule&	IMonitorModule::operator = (const IMonitorModule& other)
{
	std::cout << "Assignment operator called" << std::endl;
	_title = other.get_title();
	return (*this);
}

// Accessors

std::string		IMonitorModule::get_title(void) const
{
	return (_title);
}

// Other

void			IMonitorModule::display(const IMonitorDisplay &display) const
{
	display.draw_line_2("hostname", "e1z2r3p10");
	display.draw_bar("ram", 65);
}
