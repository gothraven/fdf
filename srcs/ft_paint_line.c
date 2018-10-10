/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/10 21:23:37 by szaghban          #+#    #+#             */
/*   Updated: 2018/10/10 23:11:53 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_paint_pixel(t_img *image, t_2dp p, float z, int flag)
{
	void *mlx_ptr;
	void *mlx_win_ptr;

	mlx_ptr = image->window->mlx;
	mlx_win_ptr = image->window->mlx_win;
	printf("test\n");
	mlx_pixel_put(mlx_ptr, mlx_win_ptr, p.x, p.y, z + flag);
}

void	on_x_axis(t_img *image, t_2dp p1, t_2dp p2, float zt[3])
{
	t_2dp	pixel;
	int		neg_y;
	float	e;
	float	miss;

	(void)zt;
	miss = fabs((p2.y - p1.y) / (p2.x - p1.x));
	neg_y = p2.y < p1.y ? 1 : 0;
	pixel.x = p1.x;
	pixel.y = p1.y;
	e = miss - 1.0;
	while (pixel.x <= p2.x)
	{
		ft_paint_pixel(image, pixel, 120, 5); //TODO fix current z and flag
		if (e >= 0.0)
		{
			pixel.y = neg_y ? pixel.y - 1.0 : pixel.y + 1.0;
			e -= 1.0;
		}
		pixel.x += 1.0;
		e += miss;
	}
}

void	on_y_axis(t_img *image, t_2dp p1, t_2dp p2, float zt[3])
{
	t_2dp	pixel;
	int		neg_x;
	float	e;
	float	miss;

	(void)zt;
	miss = fabs((p2.x - p1.x) / (p2.y - p1.y));
	pixel.x = p1.x;
	pixel.y = p1.y;
	neg_x = p2.x < p1.x ? 1 : 0;
	e = miss - 1.0;
	while (pixel.y <= p2.y)
	{
		while (e >= 0.0)
		{
			pixel.x = neg_x ? pixel.x - 1.0 : pixel.x + 1.0;
			e -= 1.0;
		}
		ft_paint_pixel(image, pixel, 120, 5);
		pixel.y += 1.0;
		e += miss;
	}
}

void	ft_paint_line(t_img *image, int i, int j)
{
	float dx;
	float dy;
	float zt[3];

	dx = image->pixels[j].x - image->pixels[i].x;
	dy = image->pixels[j].y - image->pixels[i].y;
	zt[0] = fabs(image->points[j].z - image->points[j].z);
	zt[1] = image->points[i].z;
	zt[2] = image->points[j].z;
	if (fabs(dx) >= fabs(dy))
	{
		if (image->pixels[j].x >= image->pixels[i].x)
			on_x_axis(image, image->pixels[i], image->pixels[j], zt);
		else
			ft_paint_line(image, j, i);
	}
	else
	{
		if (image->pixels[j].y >= image->pixels[i].y)
			on_y_axis(image, image->pixels[i], image->pixels[j], zt);
		else
			ft_paint_line(image, j, i);
	}
}
