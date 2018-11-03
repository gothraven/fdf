/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 23:26:51 by gothraven         #+#    #+#             */
/*   Updated: 2018/10/27 17:57:09 by szaghban         ###   ########.fr       */
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

void	ft_paint_screen_status(t_img *image)
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;
	int		i;
	char	*status[11];

	status[0] = ft_strjoin("scale: ", ft_itoa((int)image->settings.scale));
	status[1] = ft_strjoin("x rotation: ", ft_ftoa(image->settings.xrot, 2));
	status[2] = ft_strjoin("y rotation: ", ft_ftoa(image->settings.yrot, 2));
	status[3] = ft_strjoin("x move: ", ft_ftoa(image->settings.xmove, 2));
	status[4] = ft_strjoin("y move: ", ft_ftoa(image->settings.ymove, 2));
	status[5] = "projection: ISO";
	status[6] = "[UP DOWN LEFT RIGHT] move map arround";
	status[7] = "[A || D] rotate y left or right";
	status[8] = "[W || S] rotate x up or down";
	status[9] = "[E || Q] scale more or less";
	status[10] = NULL;
	mlx_ptr = image->window->mlx;
	mlx_win_ptr = image->window->mlx_win;
	i = -1;
	while (status[++i])
		mlx_string_put(mlx_ptr, mlx_win_ptr,
				20, i * 20, 0xffffff, status[i]);
}

void	ft_camera_prespective(t_img *image)
{
	float	camera_mtrc[4][4];
	int		i;
	int		scale;

	scale = image->settings.scale;
	ft_idnt_mtrc(camera_mtrc);
	ft_translate_mtrc(
			camera_mtrc, -(image->width / 2), -(image->height / 2), 0);
	ft_rotate_mtrc(camera_mtrc, 0, 0, .785);
	ft_rotate_mtrc(camera_mtrc, .785, 0, 0);
	ft_scale_mtrc(camera_mtrc, scale, scale, scale);
	ft_rotate_mtrc(camera_mtrc, image->settings.xrot, image->settings.yrot, 0);
	ft_translate_mtrc(
			camera_mtrc, image->settings.xmove, image->settings.ymove, 0);
	if (image->pixels == NULL)
		SECUREE((image->pixels = (t_2dp*)malloc(image->size * sizeof(t_2dp))));
	i = -1;
	while (++i < image->size)
		ft_mult_vec_mtrc(image->points[i], camera_mtrc, &image->pixels[i]);
}

int		ft_paint(t_img *image)
{
	int	i;

	ft_clear_image(image);
	ft_camera_prespective(image);
	ft_update_2d_pixels(image);
	ft_paint_screen_status(image);
	i = -1;
	while (++i < image->size)
	{
		if ((i + 1) % image->width && (i + 1) < image->size)
			ft_paint_line(image, i, i + 1);
		if ((i + image->width) < image->size)
			ft_paint_line(image, i, i + image->width);
	}
	mlx_put_image_to_window(
		image->window->mlx,
		image->window->mlx_win,
		image->window->mlx_img, 0, 0);
	return (0);
}

int		ft_repaint(t_img *image)
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;

	mlx_ptr = image->window->mlx;
	mlx_win_ptr = image->window->mlx_win;
	mlx_clear_window(mlx_ptr, mlx_win_ptr);
	return (ft_paint(image));
}
