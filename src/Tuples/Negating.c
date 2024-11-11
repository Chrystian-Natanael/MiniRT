/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Negating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:36:47 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/11 13:34:14 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

double	*negate(double x, double y, double z, double w)
{
	double	*neg_tpl;

	neg_tpl = allocate(sizeof(double) * 4);
		neg_tpl[X] = -x;
		neg_tpl[Y] = -y;
		neg_tpl[Z] = -z;
		neg_tpl[W] = -w;
	return (neg_tpl);
}

double	*negate_vector(double *vector)
{
	return (negate(vector[X], vector[Y], vector[Z], vector[W]));
}
