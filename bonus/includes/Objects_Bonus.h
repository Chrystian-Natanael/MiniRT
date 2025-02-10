/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Objects_Bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:50:31 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 08:15:00 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_BONUS_H
# define OBJECTS_BONUS_H

# include "Shapes_Bonus.h"
# include "Patterns_Bonus.h"

typedef struct s_material
{
	t_colors	color;
	t_colors	ambient;
	t_colors	diffu;
	t_colors	spec;
	double		shininess;
	t_pattern	pat;
}				t_material;

typedef enum e_shape_id
{
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
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

#endif