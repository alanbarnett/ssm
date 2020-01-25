/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.cc                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:03:32 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 08:29:41 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DateModule.h"
#include "IMonitorDisplay.h"
#include <iostream>

// Constructors

DateModule::DateModule(const std::string &title)
{
	std::cout << "Date constructor called for " << title << std::endl;
	this->set_title(title);
}

DateModule::~DateModule(void)
{
	std::cout << "Date destructor called for " << this->get_title() \
		<< std::endl;
}

DateModule::DateModule(const DateModule& other)
{
	std::cout << "Date copy constructor called" << std::endl;
	*this = other;
}

DateModule&	DateModule::operator = (const DateModule& other)
{
	std::cout << "Date assignment operator called" << std::endl;
	this->set_title(other.get_title());
	return (*this);
}

// Other

void			DateModule::display(const IMonitorDisplay &display) const
{
	display.draw_line_2("Sat, Jan 25, 2020", "9:33:35");
}
