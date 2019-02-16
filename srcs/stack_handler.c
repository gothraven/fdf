/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <szaghban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:38:47 by szaghban          #+#    #+#             */
/*   Updated: 2019/02/16 15:32:59 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include "error_message.h"
#include <stdlib.h>

/*
** Add t_coord_val element to stack
*/

void		push(t_coord_val **coords_stack, t_coord_val *new)
{
	if (coords_stack)
	{
		if (new)
			new->next = *coords_stack;
		*coords_stack = new;
	}
}

/*
** Get t_coord_val element from stack
*/

t_coord_val	*pop(t_coord_val **coords_stack)
{
	t_coord_val *top;

	top = NULL;
	if (coords_stack && *coords_stack)
	{
		top = *coords_stack;
		*coords_stack = (*coords_stack)->next;
	}
	return (top);
}

/*
** Convert stack with t_coord_val elements (contains z value and color value)
** to array with z values and array with color values.
*/

void		stack_to_arrays(t_coord_val **coords_stack, t_map *map)
{
	t_coord_val	*coord;
	ssize_t		i;
	ssize_t		arr_size;

	arr_size = map->width * map->height * sizeof(int);
	if (!(map->coords_arr = (int *)ft_memalloc(arr_size)))
		terminate(ERR_CONV_TO_ARR);
	if (!(map->colors_arr = (int *)ft_memalloc(arr_size)))
		terminate(ERR_CONV_TO_ARR);
	i = map->width * map->height - 1;
	while ((coord = pop(coords_stack)) && i >= 0)
	{
		map->coords_arr[i] = coord->z;
		map->colors_arr[i] = coord->color;
		if (coord->z > map->z_max)
			map->z_max = coord->z;
		if (coord->z < map->z_min)
			map->z_min = coord->z;
		i--;
		free(coord);
	}
	map->z_range = map->z_max - map->z_min;
}
