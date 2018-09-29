/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szaghban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 21:58:54 by szaghban          #+#    #+#             */
/*   Updated: 2018/09/29 21:58:56 by szaghban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fdf.h"


int main()
{
	void *mlx_ptr;
	void *mlx_window_ptr;

	mlx_ptr = mlx_init();
	mlx_window_ptr = mlx_new_window(mlx_ptr, 500, 500, "42");
	return mlx_loop(mlx_ptr);
}
