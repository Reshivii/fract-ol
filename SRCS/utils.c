/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aburnott <aburnott@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 14:53:13 by aburnott          #+#    #+#             */
/*   Updated: 2023/01/20 12:10:53 by aburnott         ###   ########.fr       */
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

void	ft_putstr(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		write (1, &str[i], 1);
	write (1, "\n", 1);
}

float	ft_atof(char *arr)
{
	float val = 0;
	int afterdot=0;
	float scale=1;
	int neg = 0;
	
	if (*arr == '-') {
	  arr++;
	  neg = 1;
	}
	while (*arr) {
	  if (afterdot) {
	    scale = scale/10;
	    val = val + (*arr-'0')*scale;
	  } else {
	    if (*arr == '.') 
	  afterdot++;
	    else
	  val = val * 10.0 + (*arr - '0');
	  }
	  arr++;
	}
	if(neg) return -val;
	else    return  val;
}
