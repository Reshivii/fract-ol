/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 13:30:00 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/19 11:18:52 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

void	print_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
}

void	display_option(void)
{
	ft_putstr("Name: mandelbrot, julia, dragon");
	ft_putstr("Option:");
	ft_putstr("\t- [julia re]: Default: -0.4");
	ft_putstr("\t- [julia im]: Default: 0.6");
	ft_putstr("Exemple with option for julia:");
	ft_putstr("./fractol julia -0.256 0.2659");
}