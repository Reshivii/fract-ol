/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 16:18:20 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/08 19:59:52 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

#define WIDTH 800
#define HEIGHT 600

int main(int argc, char** argv) {
	(void) argc;
	(void) argv;
  	void* mlx = mlx_init();
  	void* window = mlx_new_window(mlx, WIDTH, HEIGHT, "Julia Fractal");
	
  	for (int y = 0; y < HEIGHT; y++) {
  	  for (int x = 0; x < WIDTH; x++) {
  	    double c_re = -0.9;
  	    double c_im = 0.3809;
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
  	    mlx_pixel_put(mlx, window, x, y, color << 8 | color << 6);
  	  }
  	}
	
  	mlx_loop(mlx);

  	return 0;
}