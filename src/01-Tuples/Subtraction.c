/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Subtraction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:20 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/04 15:30:21 by cnatanae         ###   ########.fr       */
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
	t_pool_set	*set;

	set = get_pool();
	if (tpl1[W] == 0 && tpl2[W] == 1)
		error("Error\n",
			"impossibel to subtract vector by point", NULL, ERROR);
	res = (double *)alloc_pool(sizeof(double) * 4, set->The_pool);
	idx = -1;
	while (++idx < 4)
		res[idx] = tpl1[idx] - tpl2[idx];
	return (res);
}
