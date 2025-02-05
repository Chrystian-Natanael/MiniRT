/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:17:30 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/04 15:29:49 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Helper function for vector normalization
 *
 * This static function assists in normalizing a vector by dividing each
 * component by the given magnitude.
 *
 * @param vector The vector to be normalized
 * @param mag The magnitude of the vector
 * @return A pointer to the normalized vector
 */
static double	*norm_aux(double *vector, double mag)
{
	int		idx;
	double	*vector_norm;
	t_pool_set	*set;

	set = get_pool();
	vector_norm = (double *)alloc_pool(sizeof(double) * 4, set->The_pool);
	idx = -1;
	while (++idx < 4)
		vector_norm[idx] = vector[idx] / mag;
	return (vector_norm);
}

/**
 * @brief Normalizes a vector
 *
 * This function normalizes the given vector by dividing each of its
 * components by its magnitude.
 * If the input is a null vector or a point, an error message is displayed
 * and the program is terminated.
 *
 * @param vector The vector to be normalized
 * @return A pointer to the normalized vector
 */
double	*norm(double *vector)
{
	double	magnitude;

	if (!vector || vector[W] == POINT)
		error("Error\n", "Impossible 'normalization' with null vector or point",
			NULL, ERROR);
	magnitude = mag(vector);
	return (norm_aux(vector, magnitude));
}
