/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_Division.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:41 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/06 16:42:14 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

double	*division(double *vector, double divisor)
{
	int		idx;
	double	*res;

	if (!vector || !divisor)
		return (NULL);
	res = allocate(sizeof(double) * 4);
	idx = -1;
	while (++idx < 4)
		res[idx] = vector[idx] / divisor;
	return (res);
}
