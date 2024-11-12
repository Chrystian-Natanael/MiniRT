/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dot_Product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:51:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/12 14:27:40 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

static double	dot_product_aux(double *vector1, double *vector2)
{
	int		idx;
	double	dot_prod;

	idx = -1;
	dot_prod = 0;
	while (++idx < 4)
		dot_prod += (vector1[idx] * vector2[idx]);
	return (dot_prod);
}

double	dot_product(double *vector1, double *vector2)
{
	if (!vector1 || !vector2)
		error("Impossible 'dot product' operation with null vectors", \
			NULL, NULL, ERROR);
	return (dot_product_aux(vector1, vector2));
}
