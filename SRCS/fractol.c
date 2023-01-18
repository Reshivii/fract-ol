/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:47:24 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/18 13:26:55 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	main(int ac, char **av)
{
	t_mlx	mlx;
	(void) ac;
	(void) **av;
	
	if (ac >= 2)
	{
		if(!init_mlx(&mlx))
			exit(EXIT_FAILURE);	
		ft_parsing(av, ac, &mlx);
		mlx_hook(mlx.win, ON_DESTROY, 0, ft_close, &mlx);
		mlx_hook(mlx.win, ON_KEYDOWN, 0, key_pressed, &mlx);
		mlx_hook(mlx.win, ON_KEYUP, 0, ft_released, &mlx);
		mlx_mouse_hook(mlx.win, mouse_wheel, &mlx);
		//mandelbrot(&mlx);
		//mlx_put_image_to_window(mlx.init, mlx.win, mlx.img, 0, 0);
		mlx_loop(mlx.init);
	}
	print_error("Error. Missing arguments.\n");
	return (0);
}