/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cross_Product.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:25:59 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/05 12:25:51 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Helper function to calculate the cross product of two vectors
 *
 * This static function assists in calculating the cross product by computing
 * the determinant of the matrix formed by the vectors.
 *
 * @param vec1 The first vector
 * @param vec2 The second vector
 * @return A pointer to the resulting vector after the cross product operation
 */
static double	*cross_prod_aux(double *vec1, double *vec2)
{
	return (vector((vec1[Y] * vec2[Z]) - (vec1[Z] * vec2[Y]), (vec1[Z]
				* vec2[X]) - (vec1[X] * vec2[Z]), (vec1[X] * vec2[Y]) - (vec1[Y]
				* vec2[X])));
}

/**
 * @brief Calculates the cross product of two vectors
 *
 * This function calculates the cross product of two vectors. If either vector
 * is null or is a point, an error message is displayed and the
 * program is terminated.
 *
 * @param vector1 The first vector
 * @param vector2 The second vector
 * @return A pointer to the resulting vector after the cross product operation
 */
double	*cross_prod(double *vector1, double *vector2)
{
	if (!vector1 || !vector2 || vector1[W] != 0 || vector2[W] != 0)
	{
		printf("v1[W][%f], v2[W][%f]\n", vector1[Y], vector2[Y]);
		error("Error\n",
			"Impossible 'cross product' operation with null \
			vectors or with point",
			NULL,
			ERROR);
	}
	return (cross_prod_aux(vector1, vector2));
}
