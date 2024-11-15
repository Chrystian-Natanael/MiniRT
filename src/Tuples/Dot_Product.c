/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dot_Product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:51:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/15 11:06:50 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Helper function to calculate the dot product of two vectors
 *
 * This static function assists in calculating the dot product by
 * multiplying corresponding components of the vectors and summing the results.
 *
 * @param vector1 The first vector
 * @param vector2 The second vector
 * @return The dot product of the two vectors
 */
static double	dot_product_aux(double *vector1, double *vector2)
{
	int		idx;
	double	dot_prod;

	idx = -1;
	dot_prod = 0;
	while (++idx < 4)
		dot_prod += (vector1[idx] * vector2[idx]);
	return (dot_prod);
}

/**
 * @brief Calculates the dot product of two vectors
 *
 * This function calculates the dot product of two vectors. If either
 * vector is null, an error message is displayed and the program is terminated.
 *
 * @param vector1 The first vector
 * @param vector2 The second vector
 * @return The dot product of the two vectors
 */
double	dot_product(double *vector1, double *vector2)
{
	if (!vector1 || !vector2)
		error("Error\n", "Impossible 'dot product' operation with null vectors",
			NULL, ERROR);
	return (dot_product_aux(vector1, vector2));
}
