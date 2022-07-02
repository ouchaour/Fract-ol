/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-ouc <yait-ouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:01:41 by yait-ouc          #+#    #+#             */
/*   Updated: 2022/07/02 18:37:35 by yait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(int x, int y, int *str, int clr)
{
	str[y * (int)WIDTH + x] = clr;
}

double interpolate(double start, double end, double i)
{
    return (start + ((end - start) * i));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& (unsigned char)s1[i] && (unsigned char)s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

void	checker(t_mlx *mlx)
{
	if (mlx->type == 1)
		m_draw(mlx);
	else if (mlx->type == 2)
		j_draw(mlx);
	// else if (mlx->type == 3)
	// 	b_draw(mlx);
}
