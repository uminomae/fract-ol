/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:49:40 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/24 12:14:33 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "hook.h"

static bool	is_range_over_limit(t_draw_param *tmp, int dx, int dy);

void	move_drawing_area(t_fractol *fractol, int dx, int dy)
{
	t_draw_param	*d_p;

	d_p = &fractol->draw_param;
	if (fractol->fractol_type != 3)
		dy *= REVERSE_Y;
	if (is_range_over_limit(d_p, dx, dy))
		return ;
	d_p->d_range.x_left += d_p->x_per_pixel * dx;
	d_p->d_range.x_right += d_p->x_per_pixel * dx;
	d_p->d_range.y_top += d_p->y_per_pixel * dy;
	d_p->d_range.y_btm += d_p->y_per_pixel * dy;
	draw_fractol(fractol);
}

static bool	is_range_over_limit(t_draw_param *tmp, int dx, int dy)
{
	t_range	widest_range;

	widest_range = tmp->init_range;
	if (widest_range.x_left > tmp->d_range.x_left + tmp->x_per_pixel * dx)
		return (true);
	if (widest_range.x_right < tmp->d_range.x_right + tmp->x_per_pixel * dx)
		return (true);
	if (widest_range.y_top > tmp->d_range.y_top + tmp->y_per_pixel * dy)
		return (true);
	if (widest_range.y_btm < tmp->d_range.y_btm + tmp->y_per_pixel * dy)
		return (true);
	return (false);
}
