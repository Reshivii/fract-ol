/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:56:34 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/17 18:41:18 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	init_mlx(t_mlx *mlx)
{	
	int	endian;
	int bits_per_pixel;
	int line_lenght;
	//char *buffer;
	
	mlx->init = mlx_init();
	if (!mlx->init)
		return (0);
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fract-ol");
	if (!mlx->win)
		return (0);
	mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	//buffer = mlx_get_data_addr(mlx->img, &bits_per_pixel, &line_lenght, &endian);
	mlx->addr = mlx_get_data_addr(mlx->img, &bits_per_pixel, &line_lenght, &endian);
	mlx->color = 0x430070;
	mlx->colors = (int *)malloc(sizeof(int) * MAX_ITERATIONS + 1);
	if (!mlx->color)
		return (0);
	ft_set_colors(mlx, mlx->color);
	return (1);
}