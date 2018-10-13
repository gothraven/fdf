/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_file_to_image.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:12:32 by szaghban          #+#    #+#             */
/*   Updated: 2018/10/13 21:00:22 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_3dp	create_3dp(float x, float y, float z)
{
	t_3dp	point;

	point.x = x;
	point.y = y;
	point.z = z;
	return (point);
}

void	ft_save_points(t_img *image, char **points)
{
	int	x;
	int offset;

	SECUREE((image->points = (t_3dp*)realloc(
		image->points, image->size * sizeof(t_3dp))));
	x = -1;
	offset = image->size - image->width;
	while (++x < image->width)
	{
		image->points[offset] = create_3dp(
				x, image->height - 1, ft_atoi(points[x]));
		if (image->points[offset].z < image->settings.zmin)
			image->settings.zmin = image->points[offset].z;
		if (image->points[offset].z > image->settings.zmax)
			image->settings.zmax = image->points[offset].z;
		offset++;
	}
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
			ft_free_image(image);
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
	int		fd;
	float	tmp;

	fd = ft_open_file(fname);
	ft_parse_file(fd, image);
	close(fd);
	if (image->settings.zmin < 0)
	{
		fd = -1;
		tmp = -(image->settings.zmin);
		while (++fd < image->size)
			image->points[fd].z += tmp;
		image->settings.zmin += tmp;
		image->settings.zmax += tmp;
	}
	return (image);
}
