/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chzabakh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 15:54:23 by chzabakh          #+#    #+#             */
/*   Updated: 2020/02/06 16:02:52 by chzabakh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

typedef struct s_mlx{
	double r;
	double i;
}			t_mlx;

int		keypress(int keycode, void *z)
{
	t_mlx	*z2;

	z2 = (t_mlx*)z;
	if (keycode == 53 && z)
	{
		system("clear");
		exit(0);
	}
	return (0);
}

/*int mouse_move(int x, int y, void *p)
{
	t_mlx *c;

	c = (t_mlx*)p;
}*/

int	main()
{
	t_mlx  z;
	t_mlx  c;
	t_mlx  tmp;
	void	*mlx_ptr, *win_ptr;
	int x,y = 800;
	int	iter = 0;
	int			clr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 800, "fdf");
	y = -1;
	while (++y < 800)
	{
		x = -1;
		while (++x < 800)
		{
			iter = -1;

			z.r =   -2 + x/200.0 ;
			z.i =   -2 + y/200.0 ;

			c.r = -0.60;
			c.i = -0.70;
			
			while(sqrt(z.r * z.r + z.i * z.i) < 2 && ++iter < 100)
			{
				tmp = z;
				z.r = (tmp.r * tmp.r) - (tmp.i * tmp.i) + c.r;
				z.i = 2.0 * tmp.r * tmp.i + c.i;
			}
			clr = iter == 100 ? 0 : 0xA0F00F * (iter * 70 + 1);
			mlx_pixel_put(mlx_ptr, win_ptr, x, y, clr);
		}
	}
	//mlx_hook(m.win_ptr, 6, 0, mouse_move, (void *)&m);
	mlx_hook(win_ptr, 2, 0, keypress, (void *)&z);
	mlx_loop(mlx_ptr);
}

