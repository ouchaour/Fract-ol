/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-ouc <yait-ouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:01:41 by yait-ouc          #+#    #+#             */
/*   Updated: 2022/07/04 17:58:28 by yait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	my_mlx_pixel_put(int x, int y, int *str, int clr)
{
	str[y * (int)WIDTH + x] = clr;
}

double	interpolate(double start, double end, double i)
{
	return (start + ((end - start) * i));
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

void	ft_putstr(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		write(1, &s[i], 1);
}

int	checker(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	if (mlx->type == 1)
		m_draw(mlx);
	else if (mlx->type == 2)
		j_draw(mlx);
	else if (mlx->type == 3)
		b_draw(mlx);
	return (0);
}
