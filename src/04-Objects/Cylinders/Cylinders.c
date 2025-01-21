/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cylinders.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 13:03:04 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/13 17:40:57 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

bool	check_cap(t_ray ray, double t)
{
	double x;
	double z;

	x = ray.src[X] + t * ray.dir[X];
	z = ray.src[Z] + t * ray.dir[Z];
	return (pow(x, 2) + pow(z, 2) <= 1);
}

t_cl	*create_cl(void)
{
	t_cl		*cl;
	t_pool_set	*set;

	set = get_pools();
	cl = (t_cl *)alloc_pool(sizeof(t_cl), set->objects);
	cl->src = point(0, 0, 0);
	cl->radius = 1;
	cl->min = INT32_MIN;
	cl->max = INT32_MAX;
	cl->closed = false;
	return (cl);
}
