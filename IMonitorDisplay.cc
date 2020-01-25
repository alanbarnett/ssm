/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:43:28 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 04:10:08 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.h"
#include "IMonitorModule.h"
#include <iostream>
#include <iomanip>
#include <list>

// Constructors

IMonitorDisplay::IMonitorDisplay(unsigned int width)
{
	std::cout << "Default constructor called for display\n";
	_width = width;
}

IMonitorDisplay::~IMonitorDisplay(void)
{
	std::cout << "Destructor called for display\n";
}

IMonitorDisplay::IMonitorDisplay(const IMonitorDisplay& other)
{
	std::cout << "Copy constructor called\n";
	*this = other;
}

IMonitorDisplay&	IMonitorDisplay::operator = (const IMonitorDisplay& other)
{
	std::cout << "Assignment operator called\n";
	(void)other;
	return (*this);
}

// Mutators

void	IMonitorDisplay::add_module(IMonitorModule module)
{
	_modules.push_back(module);
}

// Other

void	IMonitorDisplay::display_module(const IMonitorModule &module) const
{
	draw_title(module.get_title());
	module.display(*this);
}

void	IMonitorDisplay::refresh_modules(void) const
{
	std::list<IMonitorModule>::const_iterator	it;
	std::list<IMonitorModule>::const_iterator	it_end = _modules.end();

	for (it = _modules.begin(); it != it_end; ++it)
	{
		display_module(*it);
	}
}

void	IMonitorDisplay::draw_title(const std::string &title) const
{
	draw_line_center(title);
	for (unsigned int i = 0; i < _width; ++i)
	{
		std::cout << "-";
	}
	std::cout << "\n";
}

void	IMonitorDisplay::draw_line(const std::string &line) const
{
	std::cout << line << "\n";
}

void	IMonitorDisplay::draw_line_center(const std::string &line) const
{
	std::cout << std::setw((_width + line.length()) / 2) << line << "\n";
}

void	IMonitorDisplay::draw_line_2(const std::string &line1,
									const std::string &line2) const
{
	std::cout << line1 << std::setw(_width - line1.length()) \
		<< line2 << "\n";
}

void	IMonitorDisplay::draw_bar(const std::string &title, int percent) const
{
	int	bar_fill;
	int	bar_length;

	std::cout << title << ": [";
	bar_length = _width - title.length() - 4;
	bar_fill = (bar_length * percent) / 100;
	for (int i = 0; i < bar_fill; ++i)
		std::cout << "#";
	for (int i = 0; i < bar_length - bar_fill; ++i)
		std::cout << " ";
	std::cout << "]\n";
}
