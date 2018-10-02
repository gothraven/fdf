/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothraven <gothraven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 23:42:07 by gothraven         #+#    #+#             */
/*   Updated: 2018/10/03 00:18:26 by gothraven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	_expose_hook_(t_img *image)
{
	return ft_repaint(image);
}

int	_key_hook_(int keycode, t_img *image)
{
	(void)image;
	if (keycode == 53)
		exit(0);
    //TODO handle some keycode for movements
	return (keycode);
}

void	ft_engine_loop(t_img *image)
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;

	mlx_ptr = image->window->mlx;
	mlx_win_ptr = image->window->mlx_win;
	mlx_expose_hook(mlx_win_ptr, _expose_hook_, image);
	mlx_key_hook(mlx_win_ptr, _key_hook_, image);
	mlx_loop(mlx_ptr);
}