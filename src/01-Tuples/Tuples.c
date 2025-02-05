/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:26 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/04 15:30:29 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Creates a tuple
 *
 * This function allocates memory for a tuple and initializes it
 * with the provided values.
 *
 * @param x The x component of the tuple
 * @param y The y component of the tuple
 * @param z The z component of the tuple
 * @param w The w component of the tuple
 * @return A pointer to the newly created tuple
 */
double	*create_tp(double x, double y, double z, double w)
{
	double	*tuple;
	t_pool_set	*set;

	set = get_pool();
	tuple = (double *)alloc_pool(sizeof(double) * 4, set->The_pool);
	tuple[0] = x;
	tuple[1] = y;
	tuple[2] = z;
	tuple[3] = w;
	return (tuple);
}

/**
 * @brief Creates a point
 *
 * This function creates a point by calling the tuple function
 * with the POINT constant.
 *
 * @param x The x coordinate of the point
 * @param y The y coordinate of the point
 * @param z The z coordinate of the point
 * @return A pointer to the newly created point
 */
double	*point(double x, double y, double z)
{
	return (create_tp(x, y, z, POINT));
}

/**
 * @brief Creates a vector
 *
 * This function creates a vector by calling the tuple function
 * with the VECTOR constant.
 *
 * @param x The x component of the vector
 * @param y The y component of the vector
 * @param z The z component of the vector
 * @return A pointer to the newly created vector
 */
double	*vector(double x, double y, double z)
{
	return (create_tp(x, y, z, VECTOR));
}
