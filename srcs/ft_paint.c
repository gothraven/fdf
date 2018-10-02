/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_paint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothraven <gothraven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 23:26:51 by gothraven         #+#    #+#             */
/*   Updated: 2018/10/03 00:16:39 by gothraven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_paint(t_img *image)
{
	(void)image;
	//space_view
	//aligned_view
	//2dp projection of 3dp
	//draw lines
	return (0);
}

int	ft_repaint(t_img *image)
{
	void	*mlx_ptr;
	void	*mlx_win_ptr;

	mlx_ptr = image->window->mlx;
	mlx_win_ptr = image->window->mlx_win;
	mlx_clear_window(mlx_ptr, mlx_win_ptr);
	return ft_paint(image);
}