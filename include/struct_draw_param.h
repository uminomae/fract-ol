/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_draw_param.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hioikawa <hioikawa@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 17:44:09 by hioikawa          #+#    #+#             */
/*   Updated: 2022/08/21 23:44:27 by hioikawa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_DRAW_PARAM_H
# define STRUCT_DRAW_PARAM_H

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_range
{
	double	x_left;
	double	x_right;
	double	y_top;
	double	y_btm;
}	t_range;

typedef struct s_draw_param
{
	t_range			d_range;
	t_range			init_range;
	double			x_per_pixel;
	double			y_per_pixel;
	unsigned int	cl_shift;
}	t_draw_param;

#endif
