/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothraven <gothraven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 21:58:46 by szaghban          #+#    #+#             */
/*   Updated: 2018/10/01 23:30:56 by gothraven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include "../libft/includes/libft.h"
# include "../minilibx_macos/mlx.h"
# include <stdio.h>

# define SECUREE(x) if (!x) exit(-1);
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080

typedef struct 	s_rgb
{
	int			r;
	int			g;
	int			b;
}				t_rgb;

typedef struct s_win
{
	void		*mlx;
	void		*mlx_win;
	int			height;
	int			width;
}				t_win;

typedef	struct 	s_3dp
{
	float		x;
	float		y;
	float		z;
}				t_3dp;

typedef	struct	s_img
{
	int			width;
	int			height;
	int			size;
	float		scale;
	t_rgb		i_color;
	t_rgb		f_color;
	t_win		*window;
	t_3dp		*pixels;
}				t_img;


t_img	*ft_image_init(const char *i_color, const char *f_color);
t_img	*ft_file_to_image(t_img *image, const char *fname);
t_rgb	ft_storgb(char *str);

#endif