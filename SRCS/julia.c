/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 11:36:48 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/09 15:54:18 by aburnott         ###   ########.fr       */
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
	  	  double c_re = -0.7;
	  	  double c_im = 0.2958;
	  	  double z_re = 1.5 * (x - WIDTH / 2) / (0.5 * WIDTH);
	  	  double z_im = (y - HEIGHT / 2) / (0.5 * HEIGHT);
	  	  int value = 0;
	  	  int iteration = 0;
	  	  while (z_re * z_re + z_im * z_im < 4 && iteration < 100) {
	  	    double new_re = z_re * z_re - z_im * z_im + c_re;
	  	    double new_im = 2 * z_re * z_im + c_im;
	  	    z_re = new_re;
	  	    z_im = new_im;
	  	    iteration++;
	  	  }
	  	  if (iteration < 100) {
	  	    value = iteration;
	  	  }
	  	  int color = value * 255 / 100;
		  my_mlx_pixel_put(mlx, x, y, color << 8 | color << 6);
	  	  //mlx_pixel_put(mlx, window, x, y, color << 8 | color << 6);
		  //printf("%d %d\n", x, y);
		  x++;
	  	}
		y++;
	}
}