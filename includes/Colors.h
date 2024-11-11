/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:49:37 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/11 16:25:13 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

# include "garbage_collector.h"
# include "MLX42/MLX42.h"

typedef struct s_colors
{
	double	red;
	double	green;
	double	blue;
}			t_colors;

t_colors	*create_color(double red, double green, double blue);
t_colors	*sum_colors(t_colors *color1, t_colors *color2);
t_colors	*sub_colors(t_colors *color1, t_colors *color2);
t_colors	*multiplication_colors(t_colors *color1, double factor);
t_colors	*hada_prd_colors(t_colors *color1, t_colors *color2);
uint32_t	rgb_to_hexa(t_colors color);

#endif // !COLORS_H