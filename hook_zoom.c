/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_zoom.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:49:40 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/24 12:13:47 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "hook.h"

static bool	is_shrinking_much(t_draw_param *d_p, double x_tmp, \
double y_tmp, double zoom_mag);
static void	set_to_upper_limit(t_draw_param *draw_param);
static void	change_to_zoomed_size(t_fractol *fractol, double x_tmp, \
double y_tmp, double zoom_mag);

void	zoom(t_fractol *fractol, int x_m_pos, int y_m_pos, int mouse)
{
	double			x_tmp;
	double			y_tmp;
	double			zoom_mag;
	t_draw_param	*d_p;

	d_p = &fractol->draw_param;
	zoom_mag = 0;
	if (mouse == MOUSE_SCROLL_UP)
		zoom_mag = MAGNIFICATION;
	else if (mouse == MOUSE_SCROLL_DOWN)
		zoom_mag = 1 / MAGNIFICATION;
	x_tmp = (x_m_pos * d_p->x_per_pixel) + d_p->d_range.x_left;
	if (fractol->fractol_type == 3)
		y_tmp = (y_m_pos * d_p->y_per_pixel) + d_p->d_range.y_top;
	else
		y_tmp = d_p->d_range.y_btm - (y_m_pos * d_p->y_per_pixel);
	if (is_shrinking_much(d_p, x_tmp, y_tmp, zoom_mag))
		set_to_upper_limit(d_p);
	else
		change_to_zoomed_size(fractol, x_tmp, y_tmp, zoom_mag);
	d_p->x_per_pixel = \
	(d_p->d_range.x_right - d_p->d_range.x_left) / X_WIN_SIZE;
	d_p->y_per_pixel = (d_p->d_range.y_btm - d_p->d_range.y_top) / Y_WIN_SIZE;
	draw_fractol(fractol);
}

static bool	is_shrinking_much(t_draw_param *d_p, double x_tmp, \
double y_tmp, double zoom_mag)
{
	t_range	limit;

	limit = d_p->init_range;
	if (limit.x_left > (x_tmp - (x_tmp - d_p->d_range.x_left) * zoom_mag))
		return (true);
	if (limit.x_right < (x_tmp + (d_p->d_range.x_right - x_tmp) * zoom_mag))
		return (true);
	if (limit.y_top > (y_tmp - (y_tmp - d_p->d_range.y_top) * zoom_mag))
		return (true);
	if (limit.y_btm < (y_tmp + (d_p->d_range.y_btm - y_tmp) * zoom_mag))
		return (true);
	return (false);
}

static void	set_to_upper_limit(t_draw_param *draw_param)
{
	draw_param->d_range = draw_param->init_range;
}

static void	change_to_zoomed_size(t_fractol *fractol, double x_tmp, \
double y_tmp, double zoom_mag)
{
	t_draw_param	*d_p;

	d_p = &fractol->draw_param;
	d_p->d_range.x_left = (x_tmp - (x_tmp - d_p->d_range.x_left) * zoom_mag);
	d_p->d_range.x_right = (x_tmp + (d_p->d_range.x_right - x_tmp) * zoom_mag);
	d_p->d_range.y_top = (y_tmp - (y_tmp - d_p->d_range.y_top) * zoom_mag);
	d_p->d_range.y_btm = (y_tmp + (d_p->d_range.y_btm - y_tmp) * zoom_mag);
}
