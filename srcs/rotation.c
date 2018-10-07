/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/07 19:01:35 by szaghban          #+#    #+#             */
/*   Updated: 2018/10/07 19:16:02 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_rotate_mrtc_x(float xmtrc[4][4], float rx)
{
	ft_idnt_mtrc(xmtrc);
	xmtrc[1][1] = cos(rx);
	xmtrc[1][2] = sin(rx);
	xmtrc[2][1] = -sin(rx);
	xmtrc[2][2] = cos(rx);
}

void	ft_rotate_mrtc_y(float ymtrc[4][4], float ry)
{
	ft_idnt_mtrc(ymtrc);
	ymtrc[0][0] = cos(ry);
	ymtrc[0][2] = -sin(ry);
	ymtrc[2][0] = sin(ry);
	ymtrc[2][2] = cos(ry);
}

void	ft_rotate_mrtc_z(float zmtrc[4][4], float rz)
{
	ft_idnt_mtrc(zmtrc);
	zmtrc[0][0] = cos(rz);
	zmtrc[0][1] = sin(rz);
	zmtrc[1][0] = -sin(rz);
	zmtrc[1][1] = cos(rz);
}

void	ft_rotate_mtrc(float mtrc[4][4], float rx, float ry, float rz)
{
	float	xmtrc[4][4];
	float	ymtrc[4][4];
	float	zmtrc[4][4];
	float	tmp1_mtrc[4][4];
	float	tmp2_mtrc[4][4];

	ft_rotate_mrtc_x(xmtrc, rx);
	ft_rotate_mrtc_y(ymtrc, ry);
	ft_rotate_mrtc_z(zmtrc, rz);

	ft_mult_mtrc(mtrc, ymtrc, tmp1_mtrc);
	ft_mult_mtrc(tmp1_mtrc, xmtrc, tmp2_mtrc);
	ft_mult_mtrc(tmp2_mtrc, zmtrc, mtrc);
}
