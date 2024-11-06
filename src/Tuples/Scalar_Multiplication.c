/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scalar_Multiplication.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:57:21 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/06 16:42:26 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

double	*multiplication(double *vector, double factor)
{
	int		idx;
	double	*res;

	if (!vector)
		return (NULL);
	res = allocate(sizeof(double) * 4);
	idx = -1;
	while (++idx < 4)
		res[idx] = factor * vector[idx];
	return (res);
}
