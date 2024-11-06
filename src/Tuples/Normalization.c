/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Normalization.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:17:30 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/06 15:24:42 by tmalheir         ###   ########.fr       */
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

	if (!vector)
		return (NULL);
	mag = magnitude(vector);
	return (norm_aux(vector, mag));
}
