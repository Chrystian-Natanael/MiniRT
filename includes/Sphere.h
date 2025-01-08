/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Sphere.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 12:04:17 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/08 09:22:29 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPHERE_H
# define SPHERE_H

# include "Colors.h"
# include "Matrices.h"
# include "Tuples.h"

typedef struct s_material
{
	t_colors	color;
	t_colors	ambient;
	t_colors	diffu;
	t_colors	spec;
	double		shininess;
}				t_material;

typedef struct s_sp
{
	double		*src;
	double		radius;
	t_matrix	transf;
	t_matrix	inv;
	t_matrix	transp;
	t_material	material;
}				t_sp;

t_sp		*create_sp(void);
void		set_transf(t_sp *s, t_matrix t);
t_material	material(void);

#endif
