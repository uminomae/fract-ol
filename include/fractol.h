/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:44:09 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/23 23:52:29 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdbool.h>
# include <math.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include "struct_draw_param.h"
# include "struct_type_fractol.h"

typedef struct s_fractol
{
	void			*mlx;
	void			*win;
	int				fractol_type;
	void			(*init_draw_param_type[4])();
	int				err;
	t_img			img;
	t_draw_param	draw_param;
	t_mandelbrot	mndl;
	t_julia			julia;
	t_lyapunov		lyap;
	int				x_m_pos;
	int				y_m_pos;
}	t_fractol;

# define X_WIN_SIZE 800
# define Y_WIN_SIZE 800

# define ITERATION_MAX	100
# define PALETTE		100
# define MAGNIFICATION	0.8
# define CL_SHIFT		0x00100000

# define EARLY_COLORS	0x000000ff
# define LAST_COLORS	0x00ffffff

# define INCORRECT	1
# define ESCAPE_VAL	4

void	is_valid(t_fractol *fractol, int argc);
void	exit_on_error(t_fractol *fractol);

void	init_fractol(t_fractol *fractol, char **argv);

void	draw_fractol(t_fractol *fractol);
void	my_mlx_pixel_put(t_img *data, int x, int y, int color);

void	hook_mlx(t_fractol *fractol);
void	loop_for_hook(t_fractol *fractol);

void	mandelbrot(t_img *img, t_draw_param *draw_param, t_mandelbrot *mndl);
void	julia(t_img *img, t_draw_param *draw_param, t_julia *julia);
void	lyapunov(t_img *img, t_draw_param *draw_param, t_lyapunov *lyap);

#endif
