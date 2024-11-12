/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:17:30 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/12 14:27:29 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

static double	*norm_aux(double *vector, double mag)
{
	int		idx;
	double	*vector_norm;

	vector_norm = allocate(sizeof(double) * 4);
	idx = -1;
	while (++idx < 4)
		vector_norm[idx] = vector[idx] / mag;
	return (vector_norm);
}

double	*norm(double *vector)
{
	double	mag;

	if (!vector || vector[W] == POINT)
		error("Impossible 'normalization' with null vector or point", \
		NULL, NULL, ERROR);
	mag = magnitude(vector);
	return (norm_aux(vector, mag));
}
