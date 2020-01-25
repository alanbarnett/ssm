/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   IMonitorModule.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:24:42 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 07:25:54 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMONITORMODULE_H
# define IMONITORMODULE_H

# include <string>

class	IMonitorDisplay;

class	IMonitorModule
{
	public:
		// Constructors
		IMonitorModule(void);
		virtual ~IMonitorModule(void) = 0;
		IMonitorModule(const IMonitorModule &other);
		IMonitorModule &operator = (const IMonitorModule &other);

		// Mutators
		void			set_title(const std::string &title);

		// Accessors
		std::string		get_title(void) const;

		// Other
		virtual void	display(const IMonitorDisplay &display) const = 0;

	private:
		std::string	_title;
};

/*
** Should contain the things a module would want to draw
*/

#endif
