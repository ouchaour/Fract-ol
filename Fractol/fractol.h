/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yait-ouc <yait-ouc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 15:37:56 by yait-ouc          #+#    #+#             */
/*   Updated: 2022/07/05 18:10:46 by yait-ouc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>

# define MAX_ITER 100
# define WIDTH 800.
# define HEIGHT 800.
# define COLORA 0xFFE162
# define COLORB 0xFF6464
# define COLORC 0x91C483

typedef struct s_cmplx
{
	double	r;
	double	i;
}	t_cmplx;

typedef struct s_mlx{
	void		*ptr;
	void		*win;
	void		*img_ptr;
	int			*img_str;
	int			bpp;
	int			l;
	int			endian;
	int			x;
	int			y;
	int			i;
	int			j;
	int			color;
	int			newcolor;
	int			iter;
	int			type;
	double		remin;
	double		remax;
	double		immin;
	double		immax;
	double		interpolation;
	t_cmplx		z;
	t_cmplx		tmp;
	t_cmplx		c;
}	t_mlx;

//Mandelbrot:
void	m_init(t_mlx *mlx);
void	m_calcul(t_mlx *mlx, int x, int y);
void	m_draw(t_mlx *mlx);
void	ft_mandelbrot(t_mlx *mlx);
//Julia:
void	j_calcul(t_mlx *mlx, int x, int y);
void	j_init(t_mlx *mlx);
void	j_draw(t_mlx *mlx);
void	ft_julia(t_mlx *mlx);
//Burningship:
void	b_calcul(t_mlx *mlx, int x, int y);
void	b_init(t_mlx *mlx);
void	b_draw(t_mlx *mlx);
void	ft_burningship(t_mlx *mlx);
//Utils:
void	my_mlx_pixel_put(int x, int y, int *str, int clr);
double	interpolate(double start, double end, double i);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *s);
int		checker(t_mlx *mlx);
// Events;
int		close_win(t_mlx *mlx);
void	hooks(t_mlx *mlx);
int		mouse_move(int x, int y, t_mlx	*mlx);
int		key_press(int keycode, t_mlx	*mlx);
int		mouse_press(int button, int x, int y, t_mlx *mlx);

#endif