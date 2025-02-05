/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:50:31 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/05 11:50:15 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "Shapes.h"
# include "Patterns.h"

typedef struct s_material
{
	t_colors	color;
	t_colors	ambient;
	t_colors	diffu;
	t_colors	spec;
	double		shininess;
	t_pattern	pattern;
}				t_material;

typedef enum e_shape_id
{
	SPHERE,
	PLANE
}				t_shape_id;

typedef struct s_shape
{
	t_matrix	transf;
	t_matrix	inv;
	t_matrix	transp;
	t_material	material;
	t_shape_id	id;
	void		*obj;
}				t_shape;

t_material	material(void);
void		init_shape(t_shape_id id, struct s_shape **shape);
void		set_transf(t_shape **s, t_matrix t);
t_colors	pattern_at_shape(t_shape *obj, double *world_pt);
// t_colors	stripe_at_object(t_shape *obj, double *world_pt);

#endif