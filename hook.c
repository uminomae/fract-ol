/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:49:40 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/24 12:27:29 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hook.h"
#include "init.h"
#include <unistd.h>

static int	operate_with_mouse(int mouse, int x_m_pos, int y_m_pos, \
								t_fractol *fractol);
static int	operate_with_key(int keycode, t_fractol *fractol);
static int	close_window(t_fractol *fractol);

void	hook_mlx(t_fractol *fractol)
{
	mlx_mouse_hook(fractol->win, &operate_with_mouse, fractol);
	mlx_key_hook(fractol->win, &operate_with_key, fractol);
	mlx_hook(fractol->win, ON_DESTROY, 0, close_window, fractol);
}

static int	operate_with_mouse(int mouse, int x_m_pos, int y_m_pos, \
								t_fractol *fractol)
{
	fractol->x_m_pos = x_m_pos;
	fractol->y_m_pos = y_m_pos;
	if (mouse == MOUSE_LEFT && fractol->fractol_type == JULIA_NUMBER)
		change_julia_c_from_mouse(fractol, x_m_pos, y_m_pos);
	else if (mouse == MOUSE_LEFT)
		change_color_from_mouse(fractol);
	else if (mouse == MOUSE_SCROLL_UP || mouse == MOUSE_SCROLL_DOWN)
		zoom(fractol, x_m_pos, y_m_pos, mouse);
	return (0);
}

static int	operate_with_key(int keycode, t_fractol *fractol)
{
	if (keycode == K_ESC)
		close_window(fractol);
	else if (keycode == K_LEFT)
		move_drawing_area(fractol, -10, 0);
	else if (keycode == K_RIGHT)
		move_drawing_area(fractol, 10, 0);
	else if (keycode == K_UP)
		move_drawing_area(fractol, 0, -10);
	else if (keycode == K_DOWN)
		move_drawing_area(fractol, 0, 10);
	else if (keycode == KEY_C)
		change_color_from_key(fractol);
	else if (keycode == KEY_X || keycode == KEY_Y \
				|| keycode == KEY_A || keycode == KEY_B)
		change_julia_c_from_key(fractol, keycode);
	else if (keycode == KEY_Z)
		zoom(fractol, fractol->x_m_pos, fractol->y_m_pos, MOUSE_SCROLL_UP);
	return (0);
}

static int	close_window(t_fractol *fractol)
{
	mlx_destroy_window(fractol->mlx, fractol->win);
	exit(0);
	return (0);
}
