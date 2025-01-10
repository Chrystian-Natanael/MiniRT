/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Subtraction_Colors.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:14:55 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/08 09:20:56 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"

/**
 * @brief Subtracts the components of two colors
 *
 * This function subtracts the red, green, and blue components of the
 * second color from the first color and returns the resulting color.
 *
 * @param color1 The first color
 * @param color2 The second color to subtract from the first
 * @return A pointer to the resulting color after subtraction
 */
t_colors	sub_colors(t_colors color1, t_colors color2)
{
	t_colors	res;

	res.red = color1.red - color2.red;
	res.green = color1.green - color2.green;
	res.blue = color1.blue - color2.blue;
	return (res);
}
