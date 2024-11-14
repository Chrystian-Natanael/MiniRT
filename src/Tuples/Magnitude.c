/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:55:50 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/14 09:04:04 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Negates the components of a vector
 *
 * This function negates each component of the given vector and returns
 * the resulting vector.
 *
 * @param vector The vector to be negated
 * @return A pointer to the resulting vector after negation
 */
static double	magnitude_aux(double x, double y, double z, double w)
{
	double	nbr_pow;

	nbr_pow = pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2);
	return (sqrt(nbr_pow));
}

/**
 * @brief Helper function to calculate the magnitude of a vector
 *
 * This static function assists in calculating the magnitude of a vector
 * by computing the square root of the sum of the squares of its components.
 *
 * @param x The x component of the vector
 * @param y The y component of the vector
 * @param z The z component of the vector
 * @param w The w component of the vector
 * @return The magnitude of the vector
 */
double	magnitude(double *vector)
{
	return (magnitude_aux(vector[X], vector[Y], vector[Z], vector[W]));
}
