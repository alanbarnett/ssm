/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DateModule.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:01:22 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 08:29:42 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATEMODULE_H
# define DATEMODULE_H

#include "IMonitorModule.h"
#include <string>

class	IMonitorDisplay;

class	DateModule : public IMonitorModule
{
	public:
		// Constructors
		DateModule(const std::string &title = "Date");
		~DateModule(void);
		DateModule(const DateModule &other);
		DateModule &operator = (const DateModule &other);

		// Other
		void	display(const IMonitorDisplay &display) const;

	private:
};

#endif
