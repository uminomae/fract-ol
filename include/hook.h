/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:44:09 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/24 12:22:35 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HOOK_H
# define HOOK_H

# include "fractol.h"

//# include <X11/keysymdef.h>
// tells you which key is pressed (look for the X11 include file "keysymdef.h"),
# define K_ESC		0xff1b
# define K_LEFT		0xff51
# define K_UP		0xff52
# define K_RIGHT	0xff53
# define K_DOWN		0xff54
# define KEY_A		0x0061
# define KEY_B		0x0062
# define KEY_C		0x0063
# define KEY_X		0x0078
# define KEY_Y		0x0079
# define KEY_Z		0x007a

# define ON_EXPOSE			12
# define ON_DESTROY			17
# define MOUSE_LEFT			1
# define MOUSE_RIGHT		2
# define MOUSE_SCROLL_UP	4
# define MOUSE_SCROLL_DOWN	5
# define REVERSE_Y 			-1
# define LYAP_CL_CHANGE		0x101010
# define CHANGE_C			0.005

void	zoom(t_fractol *fractol, int x_m_pos, int y_m_pos, int mouse);
void	change_color_from_key(t_fractol *fractol);
void	change_color_from_mouse(t_fractol *fractol);
int		change_julia_c_from_mouse(t_fractol *fractol, int x_m_pos, int y_m_pos);
void	change_julia_c_from_key(t_fractol *fractol, int key);
void	move_drawing_area(t_fractol *fractol, int dx, int dy);

#endif