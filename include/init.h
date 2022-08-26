/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:44:09 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/20 14:25:37 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INIT_H
# define INIT_H

# include "fractol.h"

# define MANDELBROT	"1"
# define JULIA		"2"
# define LYAPUNOV	"3"
# define TITLE	"fractol"
# define TERMINAT_CHAR	1
# define COLOR_LYAP 0xc35000
# define JULIA_CR -0.0655
# define JULIA_CI -0.667

typedef enum e_type{
	MANDELBROT_NUMBER = 1,
	JULIA_NUMBER,
	LYAPUNOV_NUMBER,
}	t_type;

void	init_draw_param(t_fractol *fractol, t_draw_param *draw_param);
void	init_draw_param_mandl(t_draw_param *draw_param);
void	init_draw_param_julia(t_draw_param *draw_param);
void	init_draw_param_lyap(t_draw_param *draw_param);

#endif
