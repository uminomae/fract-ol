/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mandelbrot.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:34:32 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/24 12:37:14 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_value_mandelbrot(t_mandelbrot *mndl, t_draw_param *draw_param);
static void	calculate_and_put_mandelbrot(t_img *img, t_mandelbrot *mndl);
static void	mandelbrot_put_pixel(t_img *img, t_mandelbrot *mndl, \
int ix, int iy);

void	mandelbrot(t_img *img, t_draw_param *draw_param, t_mandelbrot *mndl)
{
	set_value_mandelbrot(mndl, draw_param);
	calculate_and_put_mandelbrot(img, mndl);
}

static void	set_value_mandelbrot(t_mandelbrot *mndl, t_draw_param *draw_param)
{
	mndl->a = draw_param->d_range.x_left;
	mndl->ib = draw_param->d_range.y_top;
	mndl->d_param.d_range.x_left = draw_param->d_range.x_left;
	mndl->d_param.d_range.x_right = draw_param->d_range.x_right;
	mndl->d_param.d_range.y_top = draw_param->d_range.y_top;
	mndl->d_param.d_range.y_btm = draw_param->d_range.y_btm;
	mndl->d_param.x_per_pixel = draw_param->x_per_pixel;
	mndl->d_param.y_per_pixel = draw_param->y_per_pixel;
	mndl->d_param.cl_shift = draw_param->cl_shift;
	mndl->palette = PALETTE;
	mndl->iteration_max = ITERATION_MAX;
	mndl->escape = ESCAPE_VAL;
}

// zn1=zn0^2+c;
// z=(x,y),c=(a,ib)
// x=x^2-y^2+a
// y=2xy+ib
static void	calculate_and_put_mandelbrot(t_img *img, t_mandelbrot *mndl)
{
	int	ix;
	int	iy;

	mndl->palette = mndl->iteration_max;
	mndl->ib = mndl->d_param.d_range.y_top;
	iy = Y_WIN_SIZE - 1;
	while (iy >= 0)
	{
		mndl->a = mndl->d_param.d_range.x_left;
		ix = 0;
		while (ix < X_WIN_SIZE)
		{
			mandelbrot_put_pixel(img, mndl, ix, iy);
			mndl->a += mndl->d_param.x_per_pixel;
			ix++;
		}
		mndl->ib += mndl->d_param.y_per_pixel;
		iy--;
	}
}

static void	mandelbrot_put_pixel(t_img *img, t_mandelbrot *mndl, int ix, int iy)
{
	int	i;

	mndl->x_zr = 0;
	mndl->y_zi = 0;
	i = 0;
	while (i < mndl->iteration_max)
	{
		mndl->x_zrn = pow(mndl->x_zr, 2) - pow(mndl->y_zi, 2) + mndl->a;
		mndl->y_zin = 2 * mndl->x_zr * mndl->y_zi + mndl->ib;
		if (mndl->x_zrn > mndl->escape || mndl->y_zin > mndl->escape)
		{
			mndl->color = mndl->d_param.cl_shift / mndl->palette * i;
			my_mlx_pixel_put(img, ix, iy, mndl->color);
			break ;
		}
		my_mlx_pixel_put(img, ix, iy, 0);
		mndl->x_zr = mndl->x_zrn;
		mndl->y_zi = mndl->y_zin;
		i++;
	}
}
