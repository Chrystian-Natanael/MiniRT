/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Multiplication_Colors.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:25:36 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/11 14:27:58 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"

t_colors	*multiplication_colors(t_colors *color, double factor)
{
	t_colors	*res;

	res = allocate(sizeof(t_colors));
	res->red = color->red * factor;
	res->green = color->green * factor;
	res->blue = color->blue * factor;
	return (res);
}
