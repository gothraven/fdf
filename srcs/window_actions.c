/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_actions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <szaghban@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/31 15:38:54 by szaghban          #+#    #+#             */
/*   Updated: 2019/02/16 15:33:01 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <stdlib.h>

/*
** Close window with 'X'
*/

int		end(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

/*
** Connect functions-controllers to window
*/

void	setup_controls(t_fdf *fdf)
{
	mlx_hook(fdf->win, 2, 0, key_press, fdf);
	mlx_hook(fdf->win, 17, 0, end, fdf);
	mlx_hook(fdf->win, 4, 0, mouse_press, fdf);
	mlx_hook(fdf->win, 5, 0, mouse_release, fdf);
	mlx_hook(fdf->win, 6, 0, mouse_move, fdf);
}
