/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   TemplateModule.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 04:01:22 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 08:21:31 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Change all occurances of Template to whatever you want
// TODO Make sure this is uppercase!
#ifndef TemplateMODULE_H
# define TemplateMODULE_H

#include "IMonitorModule.h"
#include <string>

class	IMonitorDisplay;

class	TemplateModule : public IMonitorModule
{
	public:
		// Constructors
		TemplateModule(const std::string &title = "Template");
		~TemplateModule(void);
		TemplateModule(const TemplateModule &other);
		TemplateModule &operator = (const TemplateModule &other);

		// Other
		void	display(const IMonitorDisplay &display) const;

	private:
};

#endif
