/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:58:44 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/20 14:26:09 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static bool	is_correct_number_of_argments(t_fractol *fractol, int argc);

void	is_valid(t_fractol *fractol, int argc)
{
	if (is_correct_number_of_argments(fractol, argc) == false)
		exit_on_error(fractol);
}

static bool	is_correct_number_of_argments(t_fractol *fractol, int argc)
{
	if (argc == 2)
		return (true);
	else
		fractol->err = INCORRECT;
	return (false);
}
