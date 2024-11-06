/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Negating.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 13:36:47 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/06 14:59:50 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

double	*negate(double x, double y, double z, double w)
{
	int		idx;
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
