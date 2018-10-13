/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrice.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/02 20:13:35 by szaghban          #+#    #+#             */
/*   Updated: 2018/10/13 21:00:56 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_idnt_mtrc(float mtrc[4][4])
{
	ft_bzero(mtrc[0], sizeof(float) * 4);
	ft_bzero(mtrc[1], sizeof(float) * 4);
	ft_bzero(mtrc[2], sizeof(float) * 4);
	ft_bzero(mtrc[3], sizeof(float) * 4);
	mtrc[0][0] = 1;
	mtrc[1][1] = 1;
	mtrc[2][2] = 1;
	mtrc[3][3] = 1;
}

void	ft_mult_mtrc(
		float mtrc_1[4][4], float mtrc_2[4][4], float mtrc_rsult[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
		{
			mtrc_rsult[i][j] = mtrc_1[i][0] * mtrc_2[0][j] +
				mtrc_1[i][1] * mtrc_2[1][j] +
				mtrc_1[i][2] * mtrc_2[2][j] +
				mtrc_1[i][3] * mtrc_2[3][j];
		}
	}
}

void	ft_scale_mtrc(float mtrc[4][4], float x, float y, float z)
{
	float	tmp_mtrc_1[4][4];
	float	tmp_mtrc_2[4][4];

	ft_idnt_mtrc(tmp_mtrc_1);
	tmp_mtrc_1[0][0] = x;
	tmp_mtrc_1[1][1] = y;
	tmp_mtrc_1[2][2] = z;
	ft_mult_mtrc(mtrc, tmp_mtrc_1, tmp_mtrc_2);
	ft_copy_mtrc(tmp_mtrc_2, mtrc);
}

void	ft_translate_mtrc(float mtrc[4][4], float x, float y, float z)
{
	float	tmp_mtrc_1[4][4];
	float	tmp_mtrc_2[4][4];

	ft_idnt_mtrc(tmp_mtrc_1);
	tmp_mtrc_1[3][0] = x;
	tmp_mtrc_1[3][1] = y;
	tmp_mtrc_1[3][2] = z;
	ft_mult_mtrc(mtrc, tmp_mtrc_1, tmp_mtrc_2);
	ft_copy_mtrc(tmp_mtrc_2, mtrc);
}

void	ft_copy_mtrc(float mtrc_src[4][4], float mtrc_dest[4][4])
{
	int	i;
	int	j;

	i = -1;
	while (++i < 4)
	{
		j = -1;
		while (++j < 4)
			mtrc_dest[i][j] = mtrc_src[i][j];
	}
}
