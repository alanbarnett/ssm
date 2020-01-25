/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   InfoModule.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 08:15:00 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 08:17:24 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INFOMODULE_H
# define INFOMODULE_H

#include "IMonitorModule.h"
#include <string>

class	IMonitorDisplay;

class	InfoModule : public IMonitorModule
{
	public:
		// Constructors
		InfoModule(const std::string &title = "Info");
		~InfoModule(void);
		InfoModule(const InfoModule &other);
		InfoModule &operator = (const InfoModule &other);

		// Other
		void	display(const IMonitorDisplay &display) const;

	private:
};

#endif
