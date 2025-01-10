/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:50:31 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/10 15:55:43 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OBJECTS_H
# define OBJECTS_H

# include "Sphere.h"

typedef struct s_material
{
	t_colors	color;
	t_colors	ambient;
	t_colors	diffu;
	t_colors	spec;
	double		shininess;
}				t_material;

typedef enum	e_shape_id
{
	SPHERE
}				t_shape_id;

typedef struct	s_shape
{
	t_matrix	transf;
	t_matrix	inv;
	t_matrix	transp;
	t_material	material;
	t_shape_id	id;
	void		*obj;
	// void		(*create_shape)(t_shape_id id, struct s_shape *shape);
}				t_shape;

t_material	material(void);
void		init_shape(t_shape_id id, struct s_shape *shape);
// void		create_shape(t_shape_id id, struct s_shape *shape);
void		set_transf(t_shape *s, t_matrix t);

#endif