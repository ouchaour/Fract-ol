/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-ouc <yait-ouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:00:03 by yait-ouc          #+#    #+#             */
/*   Updated: 2022/07/05 18:05:25 by yait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	close_win(t_mlx *mlx)
{
	free(mlx);
	exit (0);
}

int	mouse_move(int x, int y, t_mlx	*mlx)
{
	mlx->x = x;
	mlx->y = y;
	checker(mlx);
	return (0);
}

int	key_press(int keycode, t_mlx	*mlx)
{
	if (keycode == 53)
		exit(0);
	if (keycode == 126)
		mlx->i += 20;
	else if (keycode == 125)
		mlx->i -= 20;
	else if (keycode == 123)
		mlx->j += 20;
	else if (keycode == 124)
		mlx->j -= 20;
	if (keycode == 18)
		mlx->newcolor = COLORA;
	else if (keycode == 19)
		mlx->newcolor = COLORB;
	else if (keycode == 20)
		mlx->newcolor = COLORC;
	checker(mlx);
	return (0);
}

int	mouse_press(int button, int x, int y, t_mlx *mlx)
{
	double	mousr;
	double	mousi;

	mousr = (double)mlx->x / (WIDTH / (mlx->remax - mlx->remin)) + mlx->remin;
	mousi = (double)mlx->y / (HEIGHT / (mlx->immax - mlx->immin)) + mlx->immin;
	x = 0;
	y = 0;
	if (button == 5)
		mlx->interpolation = 0.9;
	else if (button == 4)
		mlx->interpolation = 1.2;
	mlx->remin = interpolate(mousr, mlx->remin, mlx->interpolation);
	mlx->immin = interpolate(mousi, mlx->immin, mlx->interpolation);
	mlx->remax = interpolate(mousr, mlx->remax, mlx->interpolation);
	mlx->immax = interpolate(mousi, mlx->immax, mlx->interpolation);
	checker(mlx);
	return (0);
}
