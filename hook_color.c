/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:49:40 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/23 23:53:39 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "hook.h"
#include "init_range_value.h"

static unsigned int	create_trgb(int t, int r, int g, int b);
static void			change_color_trgb(t_fractol *fractol, int trgb);

static unsigned int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

static void	change_color_trgb(t_fractol *fractol, int trgb)
{
	fractol->draw_param.cl_shift = \
		(fractol->draw_param.cl_shift + (unsigned int)trgb) % LAST_COLORS;
	draw_fractol(fractol);
}

void	change_color_from_key(t_fractol *fractol)
{
	unsigned int	trgb;

	trgb = create_trgb(0, 0x10, 0, 0);
	change_color_trgb(fractol, trgb);
}

void	change_color_from_mouse(t_fractol *fractol)
{
	fractol->draw_param.cl_shift = \
		(fractol->draw_param.cl_shift + CL_SHIFT) % LAST_COLORS;
	draw_fractol(fractol);
}
