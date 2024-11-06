/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:26 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/06 14:36:31 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

double	*tuple(double x, double y, double z, double w)
{
	double	*tuple;

	tuple = allocate(sizeof(double) * 4);
	tuple[0] = x;
	tuple[1] = y;
	tuple[2] = z;
	tuple[3] = w;
	return (tuple);
}

double	*point(double x, double y, double z)
{
	return (tuple(x, y, z, POINT));
}

double	*vector(double x, double y, double z)
{
	return (tuple(x, y, z, VECTOR));
}

bool	equal(double nbr1, double nbr2)
{
	if (fabs(nbr1 - nbr2) < MAX_DIFF)
		return (true);
	return (false);
}
