/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:58:44 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/23 23:56:00 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include "init.h"

static int	get_type_fractol(t_fractol *fractol, char **argv);
static void	init_c_for_julia(t_julia *julia);
static void	init_function_ptr(t_fractol *fractol);
static void	init_mlx(t_fractol *fractol);

void	init_fractol(t_fractol *fractol, char **argv)
{
	fractol->fractol_type = get_type_fractol(fractol, argv);
	init_function_ptr(fractol);
	init_draw_param(fractol, &fractol->draw_param);
	if (fractol->fractol_type == JULIA_NUMBER)
		init_c_for_julia(&fractol->julia);
	fractol->x_m_pos = X_WIN_SIZE / 2;
	fractol->y_m_pos = Y_WIN_SIZE / 2;
	init_mlx(fractol);
}

static int	get_type_fractol(t_fractol *fractol, char **argv)
{
	int	ret;

	ret = 0;
	if (ft_memcmp(argv[1], MANDELBROT, ft_strlen(argv[1]) + TERMINAT_CHAR) == 0)
		ret = MANDELBROT_NUMBER;
	else if (ft_memcmp(argv[1], JULIA, ft_strlen(argv[1]) + TERMINAT_CHAR) == 0)
		ret = JULIA_NUMBER;
	else if (ft_memcmp(argv[1], LYAPUNOV, ft_strlen(argv[1]) + \
														TERMINAT_CHAR) == 0)
		ret = LYAPUNOV_NUMBER;
	else
	{
		fractol->err = INCORRECT;
		exit_on_error(fractol);
	}
	return (ret);
}

static void	init_function_ptr(t_fractol *fractol)
{
	fractol->init_draw_param_type[MANDELBROT_NUMBER] = init_draw_param_mandl;
	fractol->init_draw_param_type[JULIA_NUMBER] = init_draw_param_julia;
	fractol->init_draw_param_type[LYAPUNOV_NUMBER] = init_draw_param_lyap;
}

static void	init_c_for_julia(t_julia *julia)
{
	julia->a = JULIA_CR;
	julia->ib = JULIA_CI;
}

static void	init_mlx(t_fractol *fractol)
{
	fractol->mlx = mlx_init();
	if (fractol->mlx == NULL)
		exit_on_error(fractol);
	fractol->win = mlx_new_window(fractol->mlx, X_WIN_SIZE, Y_WIN_SIZE, TITLE);
	if (fractol->win == NULL)
		exit_on_error(fractol);
	fractol->img.img = mlx_new_image(fractol->mlx, X_WIN_SIZE, Y_WIN_SIZE);
	if (fractol->img.img == NULL)
		exit_on_error(fractol);
	fractol->img.addr = mlx_get_data_addr(\
					fractol->img.img, &fractol->img.bits_per_pixel, \
					&fractol->img.line_length, &fractol->img.endian);
	fractol->err = 0;
}
