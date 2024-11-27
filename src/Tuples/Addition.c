/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:14 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/27 12:22:46 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Adds two tuples
 *
 * This function adds the components of two tuples and returns the
 * resulting tuple. If both tuples are points, the function returns NULL.
 *
 * @param tpl1 The first tuple
 * @param tpl2 The second tuple
 * @return A pointer to the resulting tuple after addition, or NULL
 * if both tuples are points
 */
double	*sum(double *tpl1, double *tpl2)
{
	int		idx;
	double	*res;

	if (tpl1[W] == 1 && tpl2[W] == 1)
		error("Error\n", "Impossible make addition with two points", NULL,
			ERROR);
	res = allocate(sizeof(double) * 4);
	idx = -1;
	while (++idx < 4)
		res[idx] = tpl1[idx] + tpl2[idx];
	return (res);
}
