/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_Multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:21 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/22 10:06:01 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Multiplies a vector by a scalar factor
 *
 * This function multiplies each component of the given vector by the
 * specified scalar factor and returns the resulting vector.
 *
 * @param vector The vector to be multiplied
 * @param factor The scalar factor to multiply each component of the vector
 * @return A pointer to the resulting vector after multiplication, or NULL
 * if the input vector is NULL
 */
double	*multiply(double *vector, double factor)
{
	int		idx;
	double	*res;

	if (!vector)
		return (NULL);
	res = allocate(sizeof(double) * 4);
	idx = -1;
	while (++idx < 4)
		res[idx] = factor * vector[idx];
	return (res);
}
