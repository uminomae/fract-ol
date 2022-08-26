/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_lyapunov.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 19:31:23 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/24 12:21:47 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	set_value_lyapunov(t_lyapunov *lyap, t_draw_param *draw_param);
static void	calculate_and_put_lyapunov(t_img *img, t_lyapunov *lyap);
static void	lyapunov_get_s(t_lyapunov *lyap);

void	lyapunov(t_img *img, t_draw_param *draw_param, t_lyapunov *lyap)
{
	set_value_lyapunov(lyap, draw_param);
	calculate_and_put_lyapunov(img, lyap);
}

static void	set_value_lyapunov(t_lyapunov *lyap, t_draw_param *draw_param)
{
	lyap->d_param.d_range.x_left = draw_param->d_range.x_left;
	lyap->d_param.d_range.x_right = draw_param->d_range.x_right;
	lyap->d_param.d_range.y_top = draw_param->d_range.y_top;
	lyap->d_param.d_range.y_btm = draw_param->d_range.y_btm;
	lyap->d_param.x_per_pixel = draw_param->x_per_pixel;
	lyap->d_param.y_per_pixel = draw_param->y_per_pixel;
	lyap->d_param.cl_shift = draw_param->cl_shift;
	lyap->palette = PALETTE;
	ft_strlcpy(lyap->ab, "ab", 2);
	lyap->len_ab = ft_strlen(lyap->ab);
	lyap->nm = 10;
}

static void	calculate_and_put_lyapunov(t_img *img, t_lyapunov *lyap)
{
	int	ix;
	int	iy;

	ix = 0;
	lyap->a = lyap->d_param.d_range.x_left;
	while (ix <= X_WIN_SIZE)
	{
		lyap->b = lyap->d_param.d_range.y_btm;
		iy = Y_WIN_SIZE - 1;
		while (iy >= 0)
		{
			lyapunov_get_s(lyap);
			lyap->s = lyap->s / (lyap->nm);
			lyap->color = lyap->d_param.cl_shift / lyap->palette * \
			fabs(lyap->s);
			my_mlx_pixel_put(img, ix, iy, lyap->color);
			lyap->b -= lyap->d_param.y_per_pixel;
			iy--;
		}
		lyap->a += lyap->d_param.x_per_pixel;
		ix++;
	}
}

static void	lyapunov_get_s(t_lyapunov *lyap)
{
	int	n;
	int	m;

	lyap->s = 0;
	lyap->xx = 0.5;
	n = 0;
	while (n <= lyap->nm)
	{
		m = 0;
		while (m < 2)
		{
			if (lyap->ab[m] == 'a')
				lyap->rr = lyap->a;
			else
				lyap->rr = lyap->b;
			lyap->xx = lyap->rr * lyap->xx * (1 - lyap->xx);
			lyap->abs = fabs(lyap->rr * (1 - 2 * lyap->xx));
			if (0 < lyap->abs)
				lyap->s = lyap->s + log(lyap->abs);
			m++;
		}
		n++;
	}
}
