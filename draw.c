/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:58:44 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/20 14:19:41 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "init.h"

static void	create_image_with_selected_fractol_type(t_fractol *fractol);

void	draw_fractol(t_fractol *fractol)
{
	create_image_with_selected_fractol_type(fractol);
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
}

static void	create_image_with_selected_fractol_type(t_fractol *fractol)
{
	if (fractol->fractol_type == MANDELBROT_NUMBER)
		mandelbrot(&fractol->img, &fractol->draw_param, &fractol->mndl);
	else if (fractol->fractol_type == JULIA_NUMBER)
		julia(&fractol->img, &fractol->draw_param, &fractol->julia);
	else if (fractol->fractol_type == LYAPUNOV_NUMBER)
		lyapunov(&fractol->img, &fractol->draw_param, &fractol->lyap);
}

void	my_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
