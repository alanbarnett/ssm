/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.cc                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:43:28 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 06:46:00 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorDisplay.h"
#include "IMonitorModule.h"
#include <iostream>
#include <iomanip>
#include <string>

// Constructors

IMonitorDisplay::IMonitorDisplay(unsigned int width)
{
	std::cout << "Default constructor called for display\n";
	_width = width;
	_modules_count = 0;
	_modules_max = 8;
	_modules = new IMonitorModule* [_modules_max];
}

IMonitorDisplay::~IMonitorDisplay(void)
{
	std::cout << "Destructor called for display\n";
	for (unsigned int i = 0; i < _modules_count; ++i)
	{
		delete _modules[i];
	}
	delete[] _modules;
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
	// TODO Implement this actually!
	return (*this);
}

// Mutators

void	IMonitorDisplay::resize(void)
{
	IMonitorModule	**new_modules;

	_modules_max *= 2;
	new_modules = new IMonitorModule* [_modules_max];
	for (unsigned int i = 0; i < _modules_count; ++i)
	{
		new_modules[i] = _modules[i];
	}
	delete[] _modules;
	_modules = new_modules;
}

void	IMonitorDisplay::add_module(IMonitorModule *module)
{
	if (_modules_count == _modules_max)
	{
		resize();
	}
	_modules[_modules_count] = module;
	++_modules_count;
}

// Displaying

void	IMonitorDisplay::display_module(IMonitorModule *module) const
{
	draw_title(module->get_title());
	module->display(*this);
}

void	IMonitorDisplay::refresh_modules(void) const
{
	for (unsigned int i = 0; i < _modules_count; ++i)
	{
		display_module(_modules[i]);
	}
}

// Drawing

void	IMonitorDisplay::draw_title(const std::string &title) const
{
	draw_line_center(title);
	draw_line_separator('-');
}

void	IMonitorDisplay::draw_line(const std::string &line) const
{
	std::cout << line << "\n";
}

void	IMonitorDisplay::draw_line_separator(char c) const
{
	std::cout << std::string(_width, c) << "\n";
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
