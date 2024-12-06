/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hada_Colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:34:23 by cnatanae          #+#    #+#             */
/*   Updated: 2024/12/06 11:05:24 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"

/**
 * @brief Multiplies the components of two colors (Hadamard product)
 *
 * This function multiplies the red, green, and blue components of the first
 * color by the corresponding components of the second color and returns the
 * resulting color.
 *
 * @param color1 The first color
 * @param color2 The second color
 * @return A pointer to the resulting color after the Hadamard product
 */
t_colors	*hada_colors(t_colors *color1, t_colors *color2)
{
	t_colors	*res;
	t_pool_set	*set;

	set = get_pools();
	res = (t_colors *)alloc_pool(sizeof(t_colors), set->colors);
	res->red = color1->red * color2->red;
	res->green = color1->green * color2->green;
	res->blue = color1->blue * color2->blue;
	return (res);
}
