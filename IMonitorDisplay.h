/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorDisplay.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:43:27 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 03:52:46 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORDISPLAY_H
# define IMONITORDISPLAY_H

#include <list>

class	IMonitorModule;

class	IMonitorDisplay
{
	public:
		// Constructors
		IMonitorDisplay(unsigned int width = 40);
		~IMonitorDisplay(void);
		IMonitorDisplay(const IMonitorDisplay &other);
		IMonitorDisplay &operator = (const IMonitorDisplay &other);

		// Mutators
		void			add_module(IMonitorModule module);

		// Other
		void			display_module(const IMonitorModule &module) const;
		void			refresh_modules(void) const;
		void			draw_title(const std::string &title) const;
		void			draw_line(const std::string &line) const;
		void			draw_line_center(const std::string &line) const;
		void			draw_bar(const std::string &title, int percent) const;
		void			draw_line_2(const std::string &line1,
									const std::string &line2) const;

	private:
		std::list<IMonitorModule>	_modules;
		unsigned int				_width;
};

#endif
