/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:17 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/02 15:52:11 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "Tuples.h"
# include "Matrices.h"

typedef struct s_sphere
{
	double		*origin;
	double		radius;
	t_matrix	transform;
}			t_sphere;

t_sphere	*create_sphere(void);
void		set_transform(t_sphere *s, t_matrix t);

#endif