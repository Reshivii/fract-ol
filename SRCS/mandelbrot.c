/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 13:15:56 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/13 11:56:39 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	mandelbrot(t_mlx *mlx)
{
	double	x;
	double	y;
	double	p_i;
	double	p_r;
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
		p_i = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT);
		while (x < WIDTH)
		{
			p_r = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH);
			new_r = 0;
			new_i = 0;
			old_r = 0;
			old_i = 0;
			i = 0;
			while ((new_r * new_r + new_i * new_i) < 4.0 && i < 90) {
                old_r = new_r;
                old_i = new_i;
                new_r = old_r * old_r - old_i * old_i + p_r;
                new_i = 2.0 * old_r * old_i + p_i;
                ++i;
            }
			if (i < 100)
				value = i;
			int color = value * 255 / 100;
		  	my_mlx_pixel_put(mlx, x, y, color << 16 | color << 4);
			x++;
		}
		y++;
	}
}