/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:35:24 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/17 14:14:26 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_parsing(char **av, int ac, t_mlx *mlx)
{
	(void) ac;
	if (!ft_strncmp(av[1], "mandelbrot", 10))
		mandelbrot(mlx);
	else if (!ft_strncmp(av[1], "julia", 5))
		julia(mlx);
	else
	{
		print_error("Wrong fractal name.");
		exit(EXIT_FAILURE);
	}
	return (1);
}