/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_engine.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 23:42:07 by szaghban          #+#    #+#             */
/*   Updated: 2018/10/13 21:31:26 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		expose_hook(t_img *image)
{
	return (ft_repaint(image));
}

int		key_hook(int keycode, t_img *image)
{
	if (keycode == ESC)
	{
		ft_free_image(image);
		exit(0);
	}
	if (keycode == Q_KEY || keycode == E_KEY)
		image->settings.scale += keycode == Q_KEY ? -1 : 1;
	if (keycode == ARROW_KEY_UP || keycode == ARROW_KEY_DOWN)
		image->settings.ymove += keycode == ARROW_KEY_UP ? -1 : 1;
	if (keycode == ARROW_KEY_LEFT || keycode == ARROW_KEY_RIGHT)
		image->settings.xmove += keycode == ARROW_KEY_LEFT ? -1 : 1;
	if (keycode == W_KEY || keycode == S_KEY)
		image->settings.xrot += keycode == W_KEY ? 0.1 : -0.1;
	if (keycode == A_KEY || keycode == D_KEY)
		image->settings.yrot += keycode == A_KEY ? 0.1 : -0.1;
	ft_repaint(image);
	return (0);
}

void	ft_engine_loop(t_img *image)
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;

	mlx_ptr = image->window->mlx;
	mlx_win_ptr = image->window->mlx_win;
	mlx_expose_hook(mlx_win_ptr, expose_hook, image);
	mlx_key_hook(mlx_win_ptr, key_hook, image);
	mlx_loop(mlx_ptr);
}
