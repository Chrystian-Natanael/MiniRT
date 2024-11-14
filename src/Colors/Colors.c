/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:56:54 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/14 09:07:18 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"

static uint32_t	convert(double color_value);

/**
 * @brief Creates a color with specified red, green, and blue components
 *
 * This function allocates memory for a color structure and initializes
 * it with the provided red, green, and blue values.
 *
 * @param red The red component of the color
 * @param green The green component of the color
 * @param blue The blue component of the color
 * @return A pointer to the newly created color structure
 */
t_colors	*create_color(double red, double green, double blue)
{
	t_colors	*color;

	color = allocate(sizeof(t_colors));
	color->red = red;
	color->green = green;
	color->blue = blue;
	return (color);
}

/**
 * @brief Converts a color component to an 8-bit value
 *
 * This static function converts a color component value from the
 * range [0, 1] to an 8-bit value in the range [0, 255].
 *
 * @param color_value The color component value to be converted
 * @return The 8-bit value of the color component
 */
static uint32_t	convert(double color_value)
{
	if (color_value > 1)
		color_value = 1;
	color_value *= 255;
	return ((uint32_t) color_value & 0xFF);
}

/**
 * @brief Converts an RGB color to a hexadecimal value
 *
 * This function converts the red, green, and blue components of a color
 * to a single 32-bit hexadecimal value.
 *
 * @param color The color structure containing the red, green, and blue
 * components
 * @return The 32-bit hexadecimal value representing the color
 */
uint32_t	rgb_to_hexa(t_colors color)
{
	uint32_t	convert_color;

	convert_color = convert(color.red) << 24 | \
		convert(color.green) << 16 | \
		convert(color.blue) << 8 | \
		0xFF;
	return (convert_color);
}
