/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 21:58:46 by szaghban          #+#    #+#             */
/*   Updated: 2018/09/29 21:58:48 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../libft/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>

typedef struct 	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef	struct 	s_3d
{
	float		x;
	float		y;
	float		z;
}				t_3d;

typedef	struct	s_img
{
	t_3d		*pixels;
	int			width;
	int			height;
	int			scale;
	t_rgb		i_color;
	t_rgb		f_color;

	void		*mlx_ptr;
	void		*mlx_win_ptr;
}				t_img;

#endif