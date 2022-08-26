/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_type_fractol.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:44:09 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/21 23:42:43 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_TYPE_FRACTOL_H
# define STRUCT_TYPE_FRACTOL_H

# include "fractol.h"

typedef struct s_mandelbrot
{
	t_draw_param	d_param;
	double			a;
	double			ib;
	double			x_zr;
	double			y_zi;
	double			x_zrn;
	double			y_zin;
	int				palette;
	unsigned int	color;
	int				iteration_max;
	int				escape;
}	t_mandelbrot;

typedef struct s_julia
{
	t_draw_param	d_param;
	double			x;
	double			y;
	double			a;
	double			ib;
	double			x_zr;
	double			y_zi;
	double			x_zrn;
	double			y_zin;
	int				palette;
	unsigned int	color;
	int				iteration_max;
	int				escape;
}	t_julia;

typedef struct s_lyapunov
{
	t_draw_param	d_param;
	double			a;
	double			b;
	char			ab[3];
	int				len_ab;
	double			nm;
	double			s;
	double			xx;
	double			rr;
	double			abs;
	int				palette;
	unsigned int	color;
}	t_lyapunov;

#endif
