/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:36:48 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/14 17:26:04 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	julia(t_mlx *mlx)
{
	int y;
	int	x;

	y = 0;
	while (y < HEIGHT) {
		x = 0;
	  	while (x < WIDTH) {
	  	  double c_re = 0.3;
	  	  double c_im = 0.5;
		  double zoom = 0.8;
	  	  double z_re = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH);
	  	  double z_im = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT);
	  	  int value = 0;
	  	  int iteration = 0;
	  	  while (z_re * z_re + z_im * z_im < 4 && iteration < 80) {
	  	    double new_re = z_re * z_re - z_im * z_im + c_re;
	  	    double new_im = 2 * z_re * z_im + c_im;
	  	    z_re = new_re;
	  	    z_im = new_im;
	  	    iteration++;
	  	  }
	  	  if (iteration < 80) {
	  	    value = iteration;
	  	  }
	  	  int color = value * 255 / 100;
		  my_mlx_pixel_put(mlx, x, y, color << 6 | color << 15);
		  x++;
	  	}
		y++;
	}
}