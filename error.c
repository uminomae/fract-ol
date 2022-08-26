/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:58:44 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/20 14:22:53 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	print_how_to_use(void);

void	exit_on_error(t_fractol *fractol)
{
	if (fractol->err == INCORRECT)
		print_how_to_use();
	else if (fractol->win == NULL)
		mlx_destroy_display(fractol->mlx);
	else if (fractol->img.img == NULL)
	{
		mlx_destroy_window(fractol->mlx, fractol->win);
		mlx_destroy_display(fractol->mlx);
	}
	exit (EXIT_FAILURE);
}

static void	print_how_to_use(void)
{
	ft_putstr_fd("usage:\n", 1);
	ft_putstr_fd("arg[0] = ./fractol\n", 1);
	ft_putstr_fd("arg[1] = No.\n", 1);
	ft_putstr_fd("\t1 = Mandelbrot\n", 1);
	ft_putstr_fd("\t2 = Julia\n", 1);
	ft_putstr_fd("\t3 = Lyapunov\n", 1);
	ft_putstr_fd("example: ./fractol 1\n", 1);
}
