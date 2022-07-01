/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-ouc <yait-ouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 16:07:06 by yait-ouc          #+#    #+#             */
/*   Updated: 2022/07/01 16:43:39 by yait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int main()
{
	t_mlx vars;
	int x,y, color;
	int *img_str;

	vars.ptr = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 800, 800, "Hey");
	vars.img = mlx_new_image(vars.mlx, 800, 800);

	img_str = (int*)mlx_get_data_addr(img.img,  &img.bpp, &img.length, &img.end);
	y = 0;
	while (y < 800)
	{
		x = 0;
		while (x < 800)
		{
			vars.iteration = 1;
			c.r =   -2 + x / 800. * 4; // Rmax - Rmin ( 2 - -2)
			c.i =  -2 + y / 800. * 4 ; // Imax - Imin ( 2 - -2)
			z.r = 0.0;
			z.i = 0.0;
			tmp = z;
			while (z.r * z.r + z.i * z.i < 4 && vars.iteration < 10)
			{
				tmp.r = z.r * z.r - z.i * z.i + c.r;
				tmp.i = 2 * z.r * z.i + c.i;
				z = tmp;
				vars.iteration++;
			}
			if (vars.iteration == 10)
				color = 0;
			else
				color = 0x00ff00 * vars.iteration;
			my_mlx_pixel_put(x, y , img_str, color);
			x++;
		}
		y++;
	}
	
	mlx_hook(vars.mlx_win, 126, 0, zid, &vars);
	mlx_hook(vars.mlx_win, 17, 0, close_win, &vars);
	mlx_put_image_to_window(vars.mlx, vars.mlx_win, img.img, 0, 0);
	mlx_loop(vars.mlx);
}
