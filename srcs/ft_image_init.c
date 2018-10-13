/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothraven <gothraven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:15:20 by gothraven         #+#    #+#             */
/*   Updated: 2018/10/07 20:12:16 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_settings_init(t_img *image)
{
	image->settings.scale = 1.0;
	image->settings.zmin = 0.0;
	image->settings.zmax = 0.0;
	image->settings.yrot = 0.0;
	image->settings.xrot = 0.0;
	image->settings.xmove = 0.0;
	image->settings.ymove = 0.0;
}

t_img	*ft_image_init(const char *i_color, const char *f_color)
{
	t_img	*image;

	SECUREE((image = (t_img*)malloc(sizeof(t_img))));
	SECUREE((image->window = (t_win*)malloc(sizeof(t_win))));
	image->window->mlx = mlx_init();
	image->window->mlx_win = mlx_new_window(image->window->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF-42");
	image->window->width = WIN_WIDTH;
	image->window->height = WIN_HEIGHT;
	image->i_color = ft_storgb((char*)i_color);
	image->f_color = ft_storgb((char*)f_color);
	image->width = 0;
	image->height = 1;
	image->size = 0;
	image->points = NULL;
	image->pixels = NULL;
	ft_settings_init(image);

	return (image);
}

