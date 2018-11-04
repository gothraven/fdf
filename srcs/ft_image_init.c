/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_image_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:15:20 by szaghban          #+#    #+#             */
/*   Updated: 2018/11/04 23:28:13 by szaghban         ###   ########.fr       */
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

t_img	*ft_image_init(void)
{
	t_img	*image;
	int		tmp[3];

	SECUREE((image = (t_img*)malloc(sizeof(t_img))));
	SECUREE((image->window = (t_win*)malloc(sizeof(t_win))));
	image->window->mlx = mlx_init();
	image->window->mlx_win = mlx_new_window(
			image->window->mlx, WIN_WIDTH, WIN_HEIGHT, "FDF-42");
	image->window->mlx_img = mlx_new_image(
			image->window->mlx, WIN_WIDTH, WIN_HEIGHT);
	image->img_data = (int*)mlx_get_data_addr(
			image->window->mlx_img, tmp, tmp + 1, tmp + 2);
	image->window->width = WIN_WIDTH;
	image->window->height = WIN_HEIGHT;
	image->width = 0;
	image->height = 1;
	image->size = 0;
	image->points = NULL;
	image->pixels = NULL;
	ft_settings_init(image);
	return (image);
}

void	ft_free_image(t_img *image)
{
	free(image->points);
	image->points = NULL;
	free(image->pixels);
	image->pixels = NULL;
	free(image->window->mlx);
	image->window->mlx = NULL;
	free(image->window->mlx_win);
	image->window->mlx_win = NULL;
	free(image->window);
	image->window = NULL;
	free(image);
	image = NULL;
}
