/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors_Bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:49:37 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 08:14:16 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_BONUS_H
# define COLORS_BONUS_H

# include "MLX42/MLX42.h"
# include "Mem_Pool_Bonus.h"
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

#endif // !COLORS_BONUS_H