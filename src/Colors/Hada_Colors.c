/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hada_Colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:34:23 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/11 14:36:24 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Colors.h"

t_colors	*hada_prd_colors(t_colors *color1, t_colors *color2)
{
	t_colors	*res;

	res = allocate(sizeof(t_colors));
	res->red = color1->red * color2->red;
	res->green = color1->green * color2->green;
	res->blue = color1->blue * color2->blue;
	return (res);
}
