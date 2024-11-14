/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_Division.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:41 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/14 09:04:13 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Divides a vector by a scalar divisor
 *
 * This function divides each component of the given vector by the
 * specified scalar divisor and returns the resulting vector.
 *
 * @param vector The vector to be divided
 * @param divisor The scalar divisor to divide each component of the vector
 * @return A pointer to the resulting vector after division, or NULL if the
 * input vector is NULL or the divisor is zero
 */
double	*division(double *vector, double divisor)
{
	int		idx;
	double	*res;

	if (!vector || !divisor)
		return (NULL);
	res = allocate(sizeof(double) * 4);
	idx = -1;
	while (++idx < 4)
		res[idx] = vector[idx] / divisor;
	return (res);
}
