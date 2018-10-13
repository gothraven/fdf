/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothraven <gothraven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 23:42:07 by gothraven         #+#    #+#             */
/*   Updated: 2018/10/13 00:22:04 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	_expose_hook_(t_img *image)
{
	return ft_repaint(image);
}

int	_key_hook_(int keycode, t_img *image)
{
	if (keycode == ESC) {
		exit(0);
    //TODO free things here
  }
	if (keycode == Q_KEY || keycode == E_KEY)
		image->settings.scale += keycode == Q_KEY ? -1 : 1;
	if (keycode == ARROW_KEY_UP || keycode == ARROW_KEY_DOWN)
		image->settings.ymove += keycode == ARROW_KEY_UP ? - 1 : 1;
	if (keycode == ARROW_KEY_LEFT || keycode == ARROW_KEY_RIGHT)
		image->settings.xmove += keycode == ARROW_KEY_LEFT ? - 1 : 1;
	if (keycode == W_KEY || keycode == S_KEY)
		image->settings.xrot += keycode == W_KEY ? 0.1 : - 0.1;
	if (keycode == A_KEY || keycode == D_KEY)
		image->settings.yrot += keycode == A_KEY ? 0.1 : - 0.1;
	ft_repaint(image);
	return (0);
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
