/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothraven <gothraven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 23:26:51 by gothraven         #+#    #+#             */
/*   Updated: 2018/10/13 00:39:53 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_update_2d_pixels(t_img *image)
{
	int i;

	i = -1;
	while (++i < image->size)
	{
		image->pixels[i].x = 11 * image->pixels[i].x + WIN_WIDTH / 2;
		image->pixels[i].y = 11 * image->pixels[i].y + WIN_HEIGHT / 2;
	}
}

void	ft_camera_prespective(t_img *image)
{
	float	camera_mtrc[4][4];
	int		i;

	ft_idnt_mtrc(camera_mtrc);
	ft_translate_mtrc(camera_mtrc, -(image->width / 2), -(image->height / 2), 0);
	ft_rotate_mtrc(camera_mtrc, 0, 0, .785);
	ft_rotate_mtrc(camera_mtrc, .785, 0, 0);
	SECUREE((image->pixels = (t_2dp*)malloc(image->size * sizeof(t_2dp))));
	i = -1;
	while (++i < image->size)
		ft_mult_vec_mtrc(image->points[i], camera_mtrc, &image->pixels[i]);
}

void	ft_update_view(t_img *image)
{
	float	view_mtrc[4][4];
	int		i;
	int		scale;

	scale = image->settings.scale;
	ft_idnt_mtrc(view_mtrc);
	ft_scale_mtrc(view_mtrc, scale, scale, scale);
	ft_rotate_mtrc(view_mtrc, image->settings.xrot, image->settings.yrot, 0);
	ft_translate_mtrc(view_mtrc, image->settings.xmove, image->settings.ymove, 0);
	i = -1;
	while (++i < image->size)
		ft_mult_vec_mtrc(image->points[i], view_mtrc, &image->pixels[i]);
}

int		ft_paint(t_img *image)
{
	int	i;

	ft_camera_prespective(image);
	ft_update_view(image);
	ft_update_2d_pixels(image);
	i = -1;
	while (++i < image->size)
	{
		if ((i + 1) % image->width && (i + 1) < image->size)
			ft_paint_line(image, i, i + 1);
		if ((i + image->width) < image->size)
			ft_paint_line(image, i, i + image->width);
	}
	return (0);
}

int		ft_repaint(t_img *image)
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;

	mlx_ptr = image->window->mlx;
	mlx_win_ptr = image->window->mlx_win;
	mlx_clear_window(mlx_ptr, mlx_win_ptr);
	return ft_paint(image);
}
