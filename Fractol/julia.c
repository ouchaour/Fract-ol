/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-ouc <yait-ouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 19:18:20 by yait-ouc          #+#    #+#             */
/*   Updated: 2022/07/02 18:38:29 by yait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	j_init(t_mlx *mlx)
{	
	mlx->i = 0;
	mlx->j = 0;
	mlx->x = 50;
	mlx->y = 50;
	mlx->remin = -2;
	mlx->remax = 2;
	mlx->immin = -2;
	mlx->immax = 2;
	mlx->interpolation = 1.0;
	mlx->type = 2;
	mlx->color = 0x6a0ee3;
	mlx->newcolor = 0x6a0ee3;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "julia");
	mlx->img_ptr = mlx_new_image(mlx->ptr, WIDTH, HEIGHT);
	mlx->img_str = (int *)mlx_get_data_addr(mlx->img_ptr, \
			&(mlx->bpp), &(mlx->l), &(mlx->endian));
}

void	j_calcul(t_mlx *mlx, int x, int y)
{
	mlx->iter = 1;
	mlx->z.r = mlx->remin + x / WIDTH * (mlx->remax - mlx->remin);
	mlx->z.i = mlx->remin + y / HEIGHT * (mlx->remax - mlx->remin);
	mlx->c.r = mlx->remin + mlx->x / (WIDTH / (mlx->remax - mlx->remin));
	mlx->c.i = mlx->immin + mlx->y / (HEIGHT / (mlx->immax - mlx->immin));
	while (mlx->z.r * mlx->z.r + mlx->z.i * mlx->z.i < 4 && mlx->iter < MAX_ITER)
	{
		mlx->tmp = mlx->z;
		mlx->z.r = mlx->tmp.r * mlx->tmp.r - mlx->tmp.i * mlx->tmp.i + mlx->c.r;
		mlx->z.i = 2. * mlx->tmp.r * mlx->tmp.i + mlx->c.i;
		mlx->iter++;
	}
}

void	j_draw(t_mlx	*mlx)
{
	int	y;
	int	x;

	y = -1;
	while (++y < (int)HEIGHT)
	{
		x = -1;
		while (++x < (int)WIDTH)
		{
			j_calcul(mlx, x, y);
			if (mlx->iter == MAX_ITER)
				mlx->color = mlx->newcolor;
			else
				mlx->color = mlx->newcolor * mlx->iter;
			my_mlx_pixel_put(x, y , mlx->img_str, mlx->color);
		}
	}
	mlx_put_image_to_window(mlx->ptr, mlx->win, mlx->img_ptr, 0, 0);
}

void	ft_julia(t_mlx *mlx)
{
	j_init(mlx);
	j_draw(mlx);
}
