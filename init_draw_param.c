/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_draw_param.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:58:44 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/20 14:25:58 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "init.h"
#include "init_range_value.h"

void	init_draw_param(t_fractol *fractol, t_draw_param *draw_param)
{
	t_draw_param	*d_p;

	d_p = draw_param;
	(*fractol->init_draw_param_type[fractol->fractol_type])(draw_param);
	d_p->cl_shift = EARLY_COLORS;
	if (fractol->fractol_type == LYAPUNOV_NUMBER)
		d_p->cl_shift = COLOR_LYAP;
	d_p->x_per_pixel = \
					(d_p->d_range.x_right - d_p->d_range.x_left) / X_WIN_SIZE;
	d_p->y_per_pixel = (d_p->d_range.y_btm - d_p->d_range.y_top) / Y_WIN_SIZE;
}

void	init_draw_param_mandl(t_draw_param *draw_param)
{
	draw_param->d_range.x_left = MNDL_X_LFT;
	draw_param->d_range.x_right = MNDL_X_RGT;
	draw_param->d_range.y_top = MNDL_Y_TOP;
	draw_param->d_range.y_btm = MNDL_Y_BTM;
	draw_param->init_range = draw_param->d_range;
}

void	init_draw_param_julia(t_draw_param *draw_param)
{
	draw_param->d_range.x_left = JULIA_X_LFT;
	draw_param->d_range.x_right = JULIA_X_RGT;
	draw_param->d_range.y_top = JULIA_Y_TOP;
	draw_param->d_range.y_btm = JULIA_Y_BTM;
	draw_param->init_range = draw_param->d_range;
}

void	init_draw_param_lyap(t_draw_param *draw_param)
{
	draw_param->d_range.x_left = LYAP_X_LFT;
	draw_param->d_range.x_right = LYAP_X_RGT;
	draw_param->d_range.y_top = LYAP_Y_TOP;
	draw_param->d_range.y_btm = LYAP_Y_BTM;
	draw_param->init_range = draw_param->d_range;
}
