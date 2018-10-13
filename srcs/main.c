/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 21:58:54 by szaghban          #+#    #+#             */
/*   Updated: 2018/10/13 21:04:31 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char const *argv[])
{
	t_img *image;

	if (argc != 2)
	{
		ft_putendl("Usage : ./fdf map.fdf");
		return (-1);
	}
	image = ft_image_init();
	image = ft_file_to_image(image, argv[1]);
	ft_paint(image);
	ft_engine_loop(image);
	ft_free_image(image);
	return (0);
}
