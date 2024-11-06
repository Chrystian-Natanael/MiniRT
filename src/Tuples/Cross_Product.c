/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cross_Product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:25:59 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/06 16:41:57 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

static double	*cross_product_aux(double *vec1, double *vec2)
{
	return (vector((vec1[Y] * vec2[Z]) - (vec1[Z] * vec2[Y]) \
	, (vec1[Z] * vec2[X]) - (vec1[X] * vec2[Z]) \
	, (vec1[X] * vec2[Y]) - (vec1[Y] * vec2[X])));
}

double	*cross_product(double *vector1, double *vector2)
{
	if (!vector1 || !vector2 || vector1[W] != 0 || vector2[W] != 0)
		return (NULL);
	return (cross_product_aux(vector1, vector2));
}
