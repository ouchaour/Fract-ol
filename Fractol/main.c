/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-ouc <yait-ouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 18:41:44 by yait-ouc          #+#    #+#             */
/*   Updated: 2022/07/02 18:37:18 by yait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fractol.h"
void	notif(void)
{
	ft_putstr("Invalid number of arguments, try again:\n");
	ft_putstr("1. Mandelbrot set\n");
	ft_putstr("2. Julia set\n");
	ft_putstr("3. Burninship set\n");
}
int main(int ac, char **av)
{
	t_mlx	*mlx;

	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if(!mlx)
		exit(EXIT_FAILURE);
	if (ac == 2)
	{
		if (!(ft_strcmp(av[1], "1")))
			ft_mandelbrot(mlx);
		else if (!(ft_strcmp(av[1], "2")))
			ft_julia(mlx);
		// else if (!(ft_strcmp(av[1], "3")))
		// 	ft_burningship(mlx);
		else
			return (ft_putstr("Please enter a valid number.\n"), 0);
		mlx_hook(mlx->win, 6, 0, mouse_move, (void *)mlx);
		mlx_hook(mlx->win, 4, 0, mouse_press, (void *)mlx);
		mlx_hook(mlx->win, 2, 0, key_press, (void *)mlx);
		mlx_hook(mlx->win, 17, 0, close_win, (void *)mlx);
		mlx_loop(mlx->ptr);
	}
	else
		notif();
	free(mlx);
	return (0);
}
