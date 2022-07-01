/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-ouc <yait-ouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:53:25 by yait-ouc          #+#    #+#             */
/*   Updated: 2022/07/01 19:09:15 by yait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	m_init(t_mlx *mlx)
{
	mlx->i = 0;
	mlx->j = 0;
	mlx->x = 0;
	mlx->y = 0;
	mlx->remin = -2;
	mlx->remax = 2;
	mlx->immin = -2;
	mlx->immax = 2;
	mlx->interpolation = 1.0;
	mlx->color = 0x6a0ee3;
	mlx->newcolor = 0x6a0ee3;
	mlx->ptr = mlx_init();
	mlx->type = 1;
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "mandelbrot");
	mlx->img_ptr = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_str = (int *)mlx_get_data_addr(mlx->img_ptr,&(mlx->bpp), &(mlx->l), &(mlx->endian));
}

void	m_calcul(t_mlx *mlx, int x, int y)
{
	mlx->iter = 1;
	mlx->c.r = mlx->remin + (x + mlx->j) / WIDTH * (mlx->remax - mlx->remin);
	mlx->c.i = mlx->immin + (y + mlx->i) / HEIGHT * (mlx->immax - mlx->immin);
	mlx->z.r = 0.0;
	mlx->z.i = 0.0;
	mlx->tmp = mlx->z;
	while (mlx->z.r * mlx->z.r + mlx->z.i * mlx->z.i < 4 && mlx->iter < MAX_ITER)
	{
		mlx->tmp.r = mlx->z.r * mlx->z.r - mlx->z.i * mlx->z.i + mlx->c.r;
		mlx->tmp.i = 2 * mlx->z.r * mlx->z.i + mlx->c.i;
		mlx->z = mlx->tmp;
		mlx->iter++;
	}
}

void	m_draw(t_mlx	*mlx)
{
	int	y;
	int	x;

	y = -1;
	while (++y < (int)HEIGHT)
	{
		x = -1;
		while (++x < (int)WIDTH)
		{
			m_calcul(mlx, x, y);
			if (mlx->iter == MAX_ITER)
				mlx->color = mlx->newcolor;
			else
				mlx->color = mlx->newcolor * mlx->iter;
			my_mlx_pixel_put(x, y , mlx->img_str, mlx->color);
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_ptr, 0, 0);
}

void	ft_mandelbrot(t_mlx *mlx)
{
	m_init(mlx);
	m_draw(mlx);
}
