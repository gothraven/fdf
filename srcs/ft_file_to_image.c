/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothraven <gothraven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:12:32 by gothraven         #+#    #+#             */
/*   Updated: 2018/10/01 23:57:08 by gothraven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3dp	_3dp_(float x, float y, float z)
{
	t_3dp	pixel;

	pixel.x = x;
	pixel.y = y;
	pixel.z = z;
	return (pixel);
}

void	ft_save_points(t_img *image, char **points)
{
	int	x;
	int offset;

	SECUREE((image->pixels = (t_3dp*)realloc(
		image->pixels, image->size  * sizeof(t_3dp))));
	x = -1;
	offset = image->size - image->width;
	while (++x < image->width)
		image->pixels[offset++] = _3dp_(x, image->height-1, ft_atoi(points[x]));
}

void	ft_parse_file(int fd, t_img *image)
{
	char	*line;
	char	**points;
	int		width;

	while (ft_gnl(fd, &line))
	{
		points = ft_strsplit(line, ' ');
		width = 0;
		while (points[width])
			width++;
		if (image->width != 0 && image->width != width)
		{
			ft_putstr("Error: invalid map\n");
			// TODO free everything.
			exit(-1);
		}
		image->width = width;
		image->size = width * image->height;
		ft_save_points(image, points);
		image->height++;
	}
	free(line);
}

int		ft_open_file(const char *fname)
{
	int	fd;

	if ((fd = open(fname, O_RDONLY)) < 0)
	{
		ft_putstr("Error: File can't be opened\n");
		exit(-1);
	}
	return (fd);
}

t_img	*ft_file_to_image(t_img *image, const char *fname)
{
	int	fd;

	fd = ft_open_file(fname);
	ft_parse_file(fd, image);
	close(fd);
	return image;
}