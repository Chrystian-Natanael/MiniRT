/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:49:37 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/08 09:21:19 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "MLX42/MLX42.h"
# include "Mem_pool.h"
# include "garbage_collector.h"

typedef struct s_colors
{
	double	red;
	double	green;
	double	blue;
}			t_colors;

t_colors	create_color(double red, double green, double blue);
t_colors	sum_colors(t_colors color1, t_colors color2);
t_colors	sub_colors(t_colors color1, t_colors color2);
t_colors	multiply_col(t_colors color1, double factor);
t_colors	hada_col(t_colors color1, t_colors color2);
uint32_t	rgb2hex(t_colors color);

#endif // !COLORS_H