/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dragon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 23:29:08 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/20 10:33:22 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void dragon_curve(int n, double size, double x, double y, double angle, t_mlx *mlx) 
{
    double x1, y1, x2, y2;
    x1 = x + size * cos(angle);
    y1 = y + size * sin(angle);
    x2 = x1 + size * cos(angle + M_PI/2);
    y2 = y1 + size * sin(angle + M_PI/2);

	if (n == 0)
		return ;
	ft_color(mlx, n, x, y);
    dragon_curve(n-1, size/sqrt(2), x, y, angle + M_PI/4, mlx);
    dragon_curve(n-1, size/sqrt(2), x1, y1, angle - M_PI/4, mlx);
    dragon_curve(n-1, size/sqrt(2), x2, y2, angle - M_PI/4, mlx);
	//ntm 
}