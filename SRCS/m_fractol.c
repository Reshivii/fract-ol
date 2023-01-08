/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 11:47:24 by aburnott          #+#    #+#             */
/*   Updated: 2022/11/26 13:45:21 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

static void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->addr + (y * mlx->line_lenght + x * (mlx->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
}

// static int mouse_draw(int keycode, int x, int y, t_mlx *mlx)
// {
// 	if (keycode == 1)
// 		my_mlx_pixel_put(mlx, x, y, 0xF458FF);
// 	return (0);
// }

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
	if (keycode == KEY_W)
		mlx->move->up = 1;
	if (keycode == KEY_D)
		mlx->move->right = 1;
	if (keycode == KEY_S)
		mlx->move->down = 1;
	if (keycode == KEY_A)
		mlx->move->left = 1;
	
	return (0);
}

int	ft_released(int keycode, t_mlx *mlx)
{
	if (keycode == KEY_W)
		mlx->move->up = 0;
	if (keycode == KEY_D)
		mlx->move->right = 0;
	if (keycode == KEY_S)
		mlx->move->down = 0;
	if (keycode == KEY_A)
		mlx->move->left = 0;
	return (0);
}

int ft_move(t_mlx *mlx)
{
	if (mlx->move->up)
		my_mlx_pixel_put(mlx, mlx->data->x, mlx->data->y--, 0xFFFFFF);
	if (mlx->move->right)
		my_mlx_pixel_put(mlx, mlx->data->x++, mlx->data->y, 0xF458FF);
	if (mlx->move->left)
		my_mlx_pixel_put(mlx, mlx->data->x--, mlx->data->y, 0xF458FF);
	if (mlx->move->down)
		my_mlx_pixel_put(mlx, mlx->data->x, mlx->data->y++, 0xF458FF);
	mlx_put_image_to_window(mlx->init, mlx->win, mlx->img, 0, 0);
	return (0);
}

int	main(int ac, char **av)
{
	t_mlx	mlx;
	(void)	av;
	(void)	ac;
	
	mlx.init = mlx_init();
	mlx.win = mlx_new_window(mlx.init, 900, 600, "Fractol");
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
	mlx_loop_hook(mlx.init, ft_move, &mlx);
	mlx_loop(mlx.init);
}

// const unsigned int MAX_ITERATION = 142;

// // Taille de l'image de sortie
// const unsigned int OUTPUT_WIDTH = 1920;
// const unsigned int OUTPUT_HEIGHT = 1080;

// // Point de départ de la fenêtre de dessin dans le plan réel / complexe de mandelbrot
// const double START_X = -0.75;
// const double START_Y = 0.0;
// const double ZOOM = 0.8;

// // Tableaux de couleurs (142 couleurs, tirées d'un nuancier trouvé sur le web)
// const unsigned int COLOR_TABLE[] = {
//     0xf7df, 0xff5a, 0x07ff, 0x7ffa, 0xf7ff, 0xf7bb, 0xff38, 0xff59, 0x001f, 0x895c, 
//     0xa145, 0xddd0, 0x5cf4, 0x7fe0, 0xd343, 0xfbea, 0x64bd, 0xffdb, 0xd8a7, 0x07ff, 
//     0x0011, 0x0451, 0xbc21, 0xad55, 0x0320, 0xbdad, 0x8811, 0x5345, 0xfc60, 0x9999, 
//     0x8800, 0xecaf, 0x8df1, 0x49f1, 0x2a69, 0x067a, 0x901a, 0xf8b2, 0x05ff, 0x6b4d, 
//     0x1c9f, 0xd48e, 0xb104, 0xffde, 0x2444, 0xf81f, 0xdefb, 0xffdf, 0xfea0, 0xdd24, 
//     0x8410, 0x0400, 0xafe5, 0xf7fe, 0xfb56, 0xcaeb, 0x4810, 0xfffe, 0xf731, 0xe73f, 
//     0xff9e, 0x7fe0, 0xffd9, 0xaedc, 0xf410, 0xe7ff, 0xffda, 0xd69a, 0x9772, 0xfdb8, 
//     0xfd0f, 0x2595, 0x867f, 0x839f, 0x7453, 0xb63b, 0xfffc, 0x07e0, 0x3666, 0xff9c, 
//     0xf81f, 0x8000, 0x6675, 0x0019, 0xbaba, 0x939b, 0x3d8e, 0x7b5d, 0x07d3, 0x4e99, 
//     0xc0b0, 0x18ce, 0xf7ff, 0xff3c, 0xff36, 0xfef5, 0x0010, 0xffbc, 0x8400, 0x6c64, 
//     0xfd20, 0xfa20, 0xdb9a, 0xef55, 0x9fd3, 0xaf7d, 0xdb92, 0xff7a, 0xfed7, 0xcc27, 
//     0xfe19, 0xdd1b, 0xb71c, 0x8010, 0xf800, 0xbc71, 0x435c, 0x8a22, 0xfc0e, 0xf52c, 
//     0x2c4a, 0xffbd, 0xa285, 0xc618, 0x867d, 0x6ad9, 0x7412, 0xffdf, 0x07ef, 0x4416, 
//     0xd5b1, 0x0410, 0xddfb, 0xfb08, 0x471a, 0xec1d, 0xd112, 0xf6f6, 0xffff, 0xf7be, 
//     0xffe0, 0x9e66, 0x0000
// };

// int main(void) {
//     t_mlx	mlx;
// 	mlx.init = mlx_init();
// 	mlx.win = mlx_new_window(mlx.init, 900, 600, "Fractol");
// 	mlx.img = mlx_new_image(mlx.init, 900, 600);
// 	mlx.addr = mlx_get_data_addr(mlx.img, &mlx.bits_per_pixel, &mlx.line_lenght, &mlx.endian);
// 	mlx_hook(mlx.win, ON_DESTROY, 0, ft_close, &mlx);
// 	mlx_hook(mlx.win, ON_KEYDOWN, 0, key_pressed, &mlx);
// 	mlx_hook(mlx.win, ON_KEYUP, 0, ft_released, &mlx);
// 	for (unsigned int y = 0; y < OUTPUT_HEIGHT; ++y) {
//         double p_i = (y - OUTPUT_HEIGHT / 2.0) / (0.5 * ZOOM * OUTPUT_HEIGHT) + START_Y;
        
//         // Pour chaque pixel en X
//         for (unsigned int x = 0; x < OUTPUT_WIDTH; ++x) {
//             double p_r = 1.5 * (x - OUTPUT_WIDTH / 2.0) / (0.5 * ZOOM * OUTPUT_WIDTH) + START_X;
//             double new_r = 0, new_i = 0, old_r = 0, old_i = 0;
//             unsigned int i = 0;

//             // Magie noir mathématique (merci Wikipedia)
//             while ((new_r * new_r + new_i * new_i) < 4.0 && i < MAX_ITERATION) {
//                 old_r = new_r;
//                 old_i = new_i;
//                 new_r = old_r * old_r - old_i * old_i + p_r;
//                 new_i = 2.0 * old_r * old_i + p_i;
//                 ++i;
//             }

//             // Dessine le pixel (avec conversion RGB565 -> RGB888)
//             //unsigned int color = COLOR_TABLE[i];
// 			my_mlx_pixel_put(&mlx, 3 * x, y,0x1F);
// 			my_mlx_pixel_put(&mlx, 3 * x + 1, y,0x3F);
// 			my_mlx_pixel_put(&mlx, 3 * x + 2, y,0x5F);
//         }
//     }
// 	mlx_loop(mlx.init);
// 	// Pour chaque pixel en Y

    
//     // All done
//     return 0;
// }