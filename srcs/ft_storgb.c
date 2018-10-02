/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_storgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gothraven <gothraven@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 15:34:31 by gothraven         #+#    #+#             */
/*   Updated: 2018/09/30 16:50:38 by gothraven        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_rgb	ft_storgb(char *str)
{
	t_rgb	color;
	int		i;

	color.r = 0xff;
	color.g = 0xff;
	color.b = 0xff;
	if (!str)
		return (color);
	i = ft_strlen(str) - 1;
	i = i >= 1 ? i - 1 : i;
	color.b = ft_xtoi(&str[i]);
	str[i--] = '\0';
	i = i >= 1 ? i - 1 : i;
	color.g = ft_xtoi(&str[i]);
	str[i--] = '\0';
	i = i >= 1 ? i - 1 : i;
	color.r = ft_xtoi(&str[i]);

	return (color);
}