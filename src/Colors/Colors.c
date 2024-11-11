/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:56:54 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/11 16:23:21 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"

static uint32_t	convert(double color_value);

t_colors	*create_color(double red, double green, double blue)
{
	t_colors	*color;

	color = allocate(sizeof(t_colors));
	color->red = red;
	color->green = green;
	color->blue = blue;
	return (color);
}

static uint32_t	convert(double color_value)
{
	if (color_value > 1)
		color_value = 1;
	color_value *= 255;
	return ((uint32_t) color_value & 0xFF);
}

uint32_t	rgb_to_hexa(t_colors color)
{
	uint32_t	convert_color;

	convert_color = convert(color.red) << 24 | \
		convert(color.green) << 16 | \
		convert(color.blue) << 8 | \
		0xFF;
	return (convert_color);
}
