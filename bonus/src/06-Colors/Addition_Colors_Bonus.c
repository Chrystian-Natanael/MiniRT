/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Addition_Colors_Bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:57:10 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:41:30 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors_Bonus.h"

/**
 * @brief Adds the components of two colors
 *
 * This function adds the red, green, and blue components of the first
 * color to the corresponding components of the second color and returns
 * the resulting color.
 *
 * @param color1 The first color
 * @param color2 The second color to add to the first
 * @return A pointer to the resulting color after addition
 */
t_colors	sum_colors(t_colors color1, t_colors color2)
{
	t_colors	res;

	res.red = color1.red + color2.red;
	res.green = color1.green + color2.green;
	res.blue = color1.blue + color2.blue;
	return (res);
}
