/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:58:44 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/20 14:26:17 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	put_after_hook( t_fractol *fractol);

void	loop_for_hook(t_fractol *fractol)
{
	mlx_loop_hook(fractol->mlx, &put_after_hook, fractol);
	mlx_loop(fractol->mlx);
}

static int	put_after_hook( t_fractol *fractol)
{
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->img.img, 0, 0);
	return (0);
}
