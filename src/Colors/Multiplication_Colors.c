/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Multiplication_Colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:25:36 by cnatanae          #+#    #+#             */
/*   Updated: 2024/12/06 11:05:27 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"

/**
 * @brief Multiplies the components of a color by a scalar factor
 *
 * This function multiplies the red, green, and blue components of the
 * given color by the specified scalar factor and returns the resulting color.
 *
 * @param color The color to be multiplied
 * @param factor The scalar factor to multiply each component of the color
 * @return A pointer to the resulting color after multiplication
 */
t_colors	*multiply_colors(t_colors *color, double factor)
{
	t_colors	*res;
	t_pool_set	*set;

	set = get_pools();
	res = (t_colors *)alloc_pool(sizeof(t_colors), set->colors);
	res->red = color->red * factor;
	res->green = color->green * factor;
	res->blue = color->blue * factor;
	return (res);
}
