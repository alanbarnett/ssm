/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:25:51 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 08:30:29 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HostnameModule.h"
#include "InfoModule.h"
#include "DateModule.h"
#include "IMonitorDisplay.h"
#include <unistd.h>

int	main(void)
{
	IMonitorDisplay	display;

	display.add_module(new HostnameModule());
	display.add_module(new InfoModule());
	display.add_module(new DateModule());

	for (int i = 0; i < 5; ++i)
	{
		display.refresh_modules();
		sleep(1);
	}
	return (0);
}
