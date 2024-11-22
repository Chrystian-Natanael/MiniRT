/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:06:07 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/22 13:11:13 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "Sphere.h"

typedef struct s_ray
{
	double	*origin;
	double	*direction;
}			t_ray;

typedef struct s_intersec
{
	int		count;
	double	*intersections;
}			t_intersec;

typedef struct s_coef
{
	double	a;
	double	b;
	double	c;
	double	discrim;
}			t_coef;

t_ray		create_ray(double *origin, double *direction);
double		*pos_ray(t_ray ray, double time);

t_intersec	*intersect(t_sphere *sphere, t_ray ray);

#endif