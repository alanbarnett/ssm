/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cc                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarnett <alanbarnett328@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/25 00:25:51 by abarnett          #+#    #+#             */
/*   Updated: 2020/01/25 04:11:09 by abarnett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "IMonitorModule.h"
#include "IMonitorDisplay.h"
#include <unistd.h>

int	main(void)
{
	IMonitorDisplay	display;
	IMonitorModule	info("info");

	display.add_module(info);

	for (int i = 0; i < 5; ++i)
	{
		display.refresh_modules();
		sleep(1);
	}
	return (0);
}
