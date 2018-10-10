/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothraven <gothraven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 21:58:46 by szaghban          #+#    #+#             */
/*   Updated: 2018/10/10 23:11:55 by szaghban         ###   ########.fr       */
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

typedef	struct 	s_2dp
{
	float		x;
	float		y;
}				t_2dp;

typedef struct	s_stg
{
	float		scale;
	float		zmin;
	float		zmax;
	float		yrot;
	float		xrot;
	float		xmove;
	float		ymove;
}				t_stg;

typedef	struct	s_img
{
	int			width;
	int			height;
	int			size;
	t_stg		settings;
	t_rgb		i_color;
	t_rgb		f_color;
	t_win		*window;
	t_3dp		*points;
	t_2dp		*pixels;
}				t_img;


t_img	*ft_image_init(const char *i_color, const char *f_color);
t_img	*ft_file_to_image(t_img *image, const char *fname);
t_rgb	ft_storgb(char *str);
void	ft_copy_mtrc(float mtrc_src[4][4], float mtrc_dest[4][4]);
void	ft_translate_mtrc(float mtrc[4][4], float x, float y, float z);
void	ft_scale_mtrc(float mtrc[4][4], float x, float y, float z);
void	ft_mult_mtrc(float mtrc_1[4][4], float mtrc_2[4][4], float mtrc_rsult[4][4]);
void	ft_idnt_mtrc(float mtrc[4][4]);
void	ft_mult_vec_mtrc(t_3dp p_src, float mtrc[4][4], t_2dp *p_dest);
void	ft_rotate_mtrc(float mtrc[4][4], float rx, float ry, float rz);
int		ft_paint(t_img *image);
int		ft_repaint(t_img *image);
void	ft_engine_loop(t_img *image);
void	ft_paint_line(t_img *image, int i, int j);

#endif
