/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:56:34 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/18 14:04:37 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	init_mlx(t_mlx *mlx)
{	
	int	endian;
	int bits_per_pixel;
	int line_lenght;
	
	mlx->init = mlx_init();
	if (!mlx->init)
		return (0);
	mlx->win = mlx_new_window(mlx->init, WIDTH, HEIGHT, "Fract-ol");
	if (!mlx->win)
		return (0);
	mlx->img = mlx_new_image(mlx->init, WIDTH, HEIGHT);
	mlx->addr = mlx_get_data_addr(mlx->img, &bits_per_pixel, &line_lenght, &endian);
	mlx->color = 0x430070;
	mlx->colors = (int *)malloc(sizeof(int) * MAX_ITERATIONS + 1);
	if (!mlx->color)
		return (0);
	ft_set_colors(mlx, mlx->color);
	mlx->zoom = 0.8;
	return (1);
}

int	init_fractal(char **av, t_mlx *mlx)
{
	(void)mlx;
	if (av[2])
	{
		if (mlx->fractal == 2)
			ft_atof(av[2]);
	}
	if (av[3])
		ft_atof(av[3]);
	return (0);
}