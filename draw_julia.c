/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_julia.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:02:50 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/21 21:05:50 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_value_julia(t_julia *julia, t_draw_param *draw_param);
static void	julia_put_pixel(t_img *img, t_julia *julia, int ix, int iy);
static void	calculate_and_put_julia(t_img *img, t_julia *julia);

void	julia(t_img *img, t_draw_param *draw_param, t_julia *julia)
{
	set_value_julia(julia, draw_param);
	calculate_and_put_julia(img, julia);
}

static void	set_value_julia(t_julia *julia, t_draw_param *draw_param)
{
	julia->x = draw_param->d_range.x_left;
	julia->y = draw_param->d_range.y_top;
	julia->d_param.d_range.x_left = draw_param->d_range.x_left;
	julia->d_param.d_range.x_right = draw_param->d_range.x_right;
	julia->d_param.d_range.y_top = draw_param->d_range.y_top;
	julia->d_param.d_range.y_btm = draw_param->d_range.y_btm;
	julia->d_param.x_per_pixel = draw_param->x_per_pixel;
	julia->d_param.y_per_pixel = draw_param->y_per_pixel;
	julia->d_param.cl_shift = draw_param->cl_shift;
	julia->palette = PALETTE;
	julia->iteration_max = ITERATION_MAX;
	julia->escape = ESCAPE_VAL;
}

static void	calculate_and_put_julia(t_img *img, t_julia *julia)
{
	int	ix;
	int	iy;

	julia->palette = julia->iteration_max;
	julia->y = julia->d_param.d_range.y_top;
	iy = Y_WIN_SIZE - 1;
	while (iy >= 0)
	{
		julia->x = julia->d_param.d_range.x_left;
		ix = 0;
		while (ix < X_WIN_SIZE)
		{
			julia_put_pixel(img, julia, ix, iy);
			julia->x += julia->d_param.x_per_pixel;
			ix++;
		}
		julia->y += julia->d_param.y_per_pixel;
		iy--;
	}
}

static void	julia_put_pixel(t_img *img, t_julia *julia, int ix, int iy)
{
	int	i;

	julia->x_zr = julia->x;
	julia->y_zi = julia->y;
	i = 0;
	while (i < julia->iteration_max)
	{
		julia->x_zrn = pow(julia->x_zr, 2) - pow(julia->y_zi, 2) + julia->a;
		julia->y_zin = 2 * julia->x_zr * julia->y_zi + julia->ib;
		if (pow(julia->x_zrn, 2) + pow(julia->y_zin, 2) > julia->escape)
		{
			julia->color = julia->d_param.cl_shift / julia->palette * i;
			my_mlx_pixel_put(img, ix, iy, julia->color);
			break ;
		}
		my_mlx_pixel_put(img, ix, iy, 0);
		julia->x_zr = julia->x_zrn;
		julia->y_zi = julia->y_zin;
		i++;
	}
}
