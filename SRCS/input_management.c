/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_management.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 11:21:42 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/12 11:21:56 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_close(t_mlx *mlx)
{
	if (mlx->win)
		mlx_destroy_window(mlx->init, mlx->win);
	if (mlx->img)
		mlx_destroy_image(mlx->init, mlx->img);
	exit(EXIT_SUCCESS);
	return (0);
}

int	key_pressed(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_ESC)
		ft_close(mlx);
	
	return (0);
}

int	ft_released(int keycode, t_mlx *mlx)
{
	(void) keycode;
	(void) *mlx;
	return (0);
}