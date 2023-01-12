/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:56:34 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/12 11:17:08 by aburnott         ###   ########.fr       */
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
	mlx->move = malloc(sizeof(*mlx->move));
	if (!mlx->move)
		return (0);
	mlx->data = malloc(sizeof(*mlx->data));
	if (!mlx->data)
		return (0);
	mlx->move->up = 0;
	mlx->move->right = 0;
	mlx->move->left = 0;
	mlx->move->down = 0;
	return (1);
}