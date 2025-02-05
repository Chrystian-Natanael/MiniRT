/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_Division.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:41 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/05 10:01:36 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Divides a Tuple by a scalar divisor
 *
 * This function divides each component of the given Tuple by the
 * specified scalar divisor and returns the resulting Tuple.
 *
 * @param tuple The Tuple to be divided
 * @param divisor The scalar divisor to divide each component of the Tuple
 * @return A pointer to the resulting Tuple after division, or NULL if the
 * input Tuple is NULL or the divisor is zero
 */
double	*division(double *tuple, double divisor)
{
	int		idx;
	double	*res;
	t_pool_set	*set;

	set = get_pool();
	if (!tuple || !divisor)
		error("Not possible to divide by zero or null tuple", "", "", 1);
	res = (double *)alloc_pool(sizeof(double) * 4, set->the_pool);
	idx = -1;
	while (++idx < 4)
		res[idx] = tuple[idx] / divisor;
	return (res);
}
