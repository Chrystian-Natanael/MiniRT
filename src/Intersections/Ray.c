/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:08:38 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/22 11:33:41 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"
#include "Tuples.h"

t_ray	create_ray(double *origin, double *direction)
{
	t_ray	ray;

	if (!origin || !direction || origin[W] != POINT || direction[W] != VECTOR)
		error("Error\n", "Impossible to create a ray", NULL, ERROR);
	ray.origin = origin;
	ray.direction = direction;
	return (ray);
}

double	*pos_ray(t_ray ray, double time)
{
	return (sum(ray.origin, multiply(ray.direction, time)));
}
