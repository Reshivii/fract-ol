/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:15:56 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/17 18:38:49 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot(t_mlx *mlx)
{
	double	x;
	double	y;
	double	const_i;
	double	const_r;
	double	new_r;
	double	new_i;
	double	old_r;
	double	old_i;
	unsigned int i;
	int value;
	double	zoom;
	
	y = 0;
	zoom = 0.8;
	value = 0;
	while (y < HEIGHT)
	{
		x = 0;
		const_i = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT);
		while (x < WIDTH)
		{
			const_r = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH);
			new_r = 0;
			new_i = 0;
			old_r = 0;
			old_i = 0;
			i = 0;
			while ((new_r * new_r + new_i * new_i) < 4 && i < 100)
			{
                new_i = 2.0 * old_r * old_i + const_i;
                new_r = old_r * old_r - old_i * old_i + const_r;
                old_r = new_r;
                old_i = new_i;
                ++i;
            }
			ft_color(mlx, i, x, y);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}