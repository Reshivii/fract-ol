/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:56:34 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/17 11:33:17 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	init_mlx(t_mlx *mlx)
{	
	mlx->init = mlx_init();
	if (!mlx->init)
		return (0);
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fractol");
	if (!mlx->win)
		return (0);
	mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &mlx->bits_per_pixel, &mlx->line_lenght, &mlx->endian);
	mlx->color = 200;
	mlx->colors = (int *)malloc(sizeof(int) * MAX_ITERATIONS + 1);
	if (!mlx->color)
		return (0);
	ft_set_colors(mlx, mlx->color);
	return (1);
}