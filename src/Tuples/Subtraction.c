/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:20 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/27 12:36:21 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

/**
 * @brief Subtracts two tuples
 *
 * This function subtracts the components of the second tuple from the
 * first tuple and returns the result as a new tuple.
 *
 * @param tpl1 The first tuple
 * @param tpl2 The second tuple to subtract from the first
 * @return A pointer to the resulting tuple after subtraction
 */
double	*sub(double *tpl1, double *tpl2)
{
	int		idx;
	double	*res;

	if (tpl1[W] == 0 && tpl2[W] == 1)
		error("Error\n",
			"In this case, it's impossivel to subtract vector by point",
			NULL, ERROR);
	res = allocate(sizeof(double) * 4);
	idx = -1;
	while (++idx < 4)
		res[idx] = tpl1[idx] - tpl2[idx];
	return (res);
}
