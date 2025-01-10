/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Negating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:36:47 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/06 11:06:53 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Negates the components of a tuple
 *
 * This function negates each component of the given tuple and returns
 * the resulting tuple.
 *
 * @param x The x component of the tuple
 * @param y The y component of the tuple
 * @param z The z component of the tuple
 * @param w The w component of the tuple
 * @return A pointer to the resulting tuple after negation
 */
double	*negate(double x, double y, double z, double w)
{
	double		*neg_tpl;
	t_pool_set	*set;

	set = get_pools();
	neg_tpl = (double *)alloc_pool(sizeof(double) * 4, set->matrices);
	neg_tpl[X] = -x;
	neg_tpl[Y] = -y;
	neg_tpl[Z] = -z;
	neg_tpl[W] = -w;
	return (neg_tpl);
}

/**
 * @brief Negates the components of a vector
 *
 * This function negates each component of the given vector and returns
 * the resulting vector.
 *
 * @param vector The vector to be negated
 * @return A pointer to the resulting vector after negation
 */
double	*negate_vector(double *vector)
{
	return (negate(vector[X], vector[Y], vector[Z], vector[W]));
}
