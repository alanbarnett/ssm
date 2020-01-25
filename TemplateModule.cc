/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemplateModule.cc                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:03:32 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 08:21:32 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Change all occurances of Template to whatever you want
// Edit the display function to your liking

#include "TemplateModule.h"
#include "IMonitorDisplay.h"
#include <iostream>

// Constructors

TemplateModule::TemplateModule(const std::string &title)
{
	std::cout << "Template constructor called for " << title << std::endl;
	this->set_title(title);
}

TemplateModule::~TemplateModule(void)
{
	std::cout << "Template destructor called for " << this->get_title() \
		<< std::endl;
}

TemplateModule::TemplateModule(const TemplateModule& other)
{
	std::cout << "Template copy constructor called" << std::endl;
	*this = other;
}

TemplateModule&	TemplateModule::operator = (const TemplateModule& other)
{
	std::cout << "Template assignment operator called" << std::endl;
	this->set_title(other.get_title());
	return (*this);
}

// Other

void			TemplateModule::display(const IMonitorDisplay &display) const
{
	display.draw_line_2("hostname", "e1z2r3p10");
}
