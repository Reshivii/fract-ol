/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:47:24 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/09 15:55:02 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= 900 || y >= 600)
		return ;
	dst = mlx->addr + (y * mlx->line_lenght + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

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

int	main(int ac, char **av)
{
	t_mlx	mlx;
	(void) ac;
	(void) av;
	
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, 900, 600, "Fractol"); //re
	mlx.img = mlx_new_image(mlx.init, 900, 600);
	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_lenght, &mlx.endian);
	mlx.move = malloc(sizeof(*mlx.move));
	if (!mlx.move)
		return (0);
	mlx.data = malloc(sizeof(*mlx.data));
	if (!mlx.data)
		return (0);
	mlx.move->up = 0;
	mlx.move->right = 0;
	mlx.move->left = 0;
	mlx.move->down = 0;
	mlx.data->x = 500;
	mlx.data->y = 500;
	mlx_hook(mlx.win, ON_DESTROY, 0, ft_close, &mlx);
	mlx_hook(mlx.win, ON_KEYDOWN, 0, key_pressed, &mlx);
	mlx_hook(mlx.win, ON_KEYUP, 0, ft_released, &mlx);
	//mlx_hook(mlx.win, ON_MOUSEDOWN, 0, mouse_draw, &mlx);
	mandelbrot(&mlx);
	mlx_put_image_to_window(mlx.init, mlx.win, mlx.img, 0, 0);
	mlx_loop(mlx.init);
}