/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HostnameModule.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:01:22 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 07:15:39 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOSTNAMEMODULE_H
# define HOSTNAMEMODULE_H

#include "IMonitorModule.h"
#include <string>

class	IMonitorDisplay;

class	HostnameModule : public IMonitorModule
{
	public:
		// Constructors
		HostnameModule(const std::string &title = "Hostname");
		~HostnameModule(void);
		HostnameModule(const HostnameModule &other);
		HostnameModule &operator = (const HostnameModule &other);

		// Other
		void	display(const IMonitorDisplay &display) const;

	private:
};

#endif
