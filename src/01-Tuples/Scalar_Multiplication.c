/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_Multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:21 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/04 15:30:12 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Multiplies a Tuple by a scalar factor
 *
 * This function multiplies each component of the given Tuple by the
 * specified scalar factor and returns the resulting Tuple.
 *
 * @param tuple The Tuple to be multiplied
 * @param factor The scalar factor to multiply each component of the Tuple
 * @return A pointer to the resulting Tuple after multiplication, or NULL
 * if the input Tuple is NULL
 */
double	*multiply(double *tuple, double factor)
{
	int		idx;
	double	*res;
	t_pool_set	*set;

	set = get_pool();
	if (!tuple)
		error("Not possible to multiply a null tuple", "", "", 1);
	res = (double *)alloc_pool(sizeof(double) * 4, set->The_pool);
	idx = -1;
	while (++idx < 4)
		res[idx] = factor * tuple[idx];
	return (res);
}
