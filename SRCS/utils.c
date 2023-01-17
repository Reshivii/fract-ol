/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:53:13 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/17 18:31:20 by aburnott         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fractol.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// void my_mlx_pixel_put(t_mlx *mlx, int x, int y, int color)
// {
// 	char	*dst;

// 	if (x < 0 || y < 0 || x >= WIDTH || y >= HEIGHT)
// 		return ;
// 	dst = mlx->addr + (y * mlx->line_lenght + x * (mlx->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	print_error(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write(2, &str[i], 1);
}