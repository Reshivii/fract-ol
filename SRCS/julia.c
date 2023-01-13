/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:36:48 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/13 11:52:34 by aburnott         ###   ########.fr       */
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
	  	  double c_re = -0.8;
	  	  double c_im = 0.156;
		  double zoom = 1.5;
	  	  double z_re = 1.5 * (x - WIDTH / 2) / (0.5 * zoom * WIDTH);
	  	  double z_im = (y - HEIGHT / 2) / (0.5 * zoom * HEIGHT);
	  	  int value = 0;
	  	  int iteration = 0;
	  	  while (z_re * z_re + z_im * z_im < 4 && iteration < 140) {
	  	    double new_re = z_re * z_re - z_im * z_im + c_re;
	  	    double new_im = 2 * z_re * z_im + c_im;
	  	    z_re = new_re;
	  	    z_im = new_im;
	  	    iteration++;
	  	  }
	  	  if (iteration < 140) {
	  	    value = iteration;
	  	  }
	  	  int color = value * 255 / 100;
		  my_mlx_pixel_put(mlx, x, y, color << 5 | color << 13);
		  x++;
	  	}
		y++;
	}
}