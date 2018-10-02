/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothraven <gothraven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 21:58:54 by szaghban          #+#    #+#             */
/*   Updated: 2018/10/02 23:49:08 by gothraven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char const *argv[])
{
	t_img *image = NULL;

	if (argc < 2 || argc > 4)
	{
		ft_putstr(
			"Usage : ./fdf map.fdf [iColor] [fColor]\n\
			 - iColor: Hexacode for the low color\n\
			 - fColor: Hexacode for the high color\n");
		return (-1);
	}
	image = ft_image_init(
		argc >= 3? argv[2]: NULL,
		argc >= 4? argv[3]: NULL
	);
	image = ft_file_to_image(image, argv[1]);
	ft_paint(image);
	ft_engine_loop(image);
	//TODO: free_all
	return (0);
}
