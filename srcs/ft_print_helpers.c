/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_helpers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/12 22:39:00 by szaghban          #+#    #+#             */
/*   Updated: 2018/10/12 23:57:04 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"


float	_z_options(t_img *image, t_2dp pixel, t_2dp p1, t_2dp p2,  float opt[3])
{
	float	z_bot;
	float	res;

	if (opt[1] < opt[2])
		z_bot = image->settings.zmax;
	else
		z_bot = image->settings.zmin;
	res = opt[0] ? (1.0 - (pixel.x - p1.x) / fabs(p2.x - p1.x)) *
		opt[0] + z_bot : opt[1];
	return res;
}


int		_flag(float opt[3])
{
	return (opt[1] < opt[2] ? 1 : 0);
}
