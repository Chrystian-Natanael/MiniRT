/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:14 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/05 10:01:36 by tmalheir         ###   ########.fr       */
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
	t_pool_set	*set;

	set = get_pool();
	if (tpl1[W] == 1 && tpl2[W] == 1)
		error("Error\n", "Impossible make addition with two points", NULL,
			ERROR);
	res = (double *)alloc_pool(sizeof(double) * 4, set->the_pool);
	idx = -1;
	while (++idx < 4)
		res[idx] = tpl1[idx] + tpl2[idx];
	return (res);
}
