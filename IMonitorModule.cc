/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:24:43 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 07:26:09 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.h"
#include "IMonitorDisplay.h"
#include <iostream>
#include <string>

// Constructors

IMonitorModule::IMonitorModule(void)
{
	std::cout << "Default module constructor called" << std::endl;
}

IMonitorModule::~IMonitorModule(void)
{
	std::cout << "Destructor called for " << _title << std::endl;
}

IMonitorModule::IMonitorModule(const IMonitorModule& other)
{
	std::cout << "Copy constructor called for " << _title << std::endl;
	*this = other;
}

IMonitorModule&	IMonitorModule::operator = (const IMonitorModule& other)
{
	std::cout << "Assignment operator called for " << _title << std::endl;
	_title = other.get_title();
	return (*this);
}

// Mutators

void			IMonitorModule::set_title(const std::string &title)
{
	_title = title;
}

// Accessors

std::string		IMonitorModule::get_title(void) const
{
	return (_title);
}
