/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_julia_c.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:49:40 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/23 23:55:10 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "hook.h"
#include "init_range_value.h"

int	change_julia_c_from_mouse(t_fractol *fractol, int x_m_pos, int y_m_pos)
{
	t_julia			*julia;
	t_draw_param	*d_p;

	julia = &fractol->julia;
	d_p = &fractol->julia.d_param;
	julia->a = (x_m_pos * d_p->x_per_pixel) + d_p->d_range.x_left;
	julia->ib = (y_m_pos * d_p->y_per_pixel) + d_p->d_range.y_top;
	draw_fractol(fractol);
	return (0);
}

void	change_julia_c_from_key(t_fractol *fractol, int key)
{
	if (key == KEY_X)
	{
		fractol->julia.a += CHANGE_C;
		if (fractol->julia.a > JULIA_X_RGT)
			fractol->julia.a = JULIA_X_LFT;
	}
	if (key == KEY_Y)
	{
		fractol->julia.ib += CHANGE_C;
		if (fractol->julia.ib > JULIA_Y_BTM)
			fractol->julia.ib = JULIA_Y_TOP;
	}
	if (key == KEY_A)
	{
		fractol->julia.a -= CHANGE_C;
		if (fractol->julia.a < JULIA_X_LFT)
			fractol->julia.a = JULIA_X_RGT;
	}
	if (key == KEY_B)
	{
		fractol->julia.ib -= CHANGE_C;
		if (fractol->julia.ib < JULIA_Y_TOP)
			fractol->julia.ib = JULIA_Y_BTM;
	}
	draw_fractol(fractol);
}
