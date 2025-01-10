/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:08:38 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/06 10:21:32 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"
#include "Tuples.h"

t_ray	create_ray(double *src, double *dir)
{
	t_ray	ray;

	if (!src || !dir || src[W] != POINT || dir[W] != VECTOR)
		error("Error\n", "Impossible to create a ray", NULL, ERROR);
	ray.src = src;
	ray.dir = dir;
	return (ray);
}

double	*pos_ray(t_ray ray, double time)
{
	return (sum(ray.src, multiply(ray.dir, time)));
}

t_ray	transform(t_ray ray, t_matrix action)
{
	return (create_ray(multiply_mtx_tp(action, ray.src), multiply_mtx_tp(action,
				ray.dir)));
}
