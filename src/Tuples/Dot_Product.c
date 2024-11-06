/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dot_Product.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 15:51:37 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/06 16:13:06 by tmalheir         ###   ########.fr       */
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
		quit(1);
	return (dot_product_aux(vector1, vector2));
}
