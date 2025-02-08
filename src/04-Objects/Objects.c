/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:53:51 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/08 12:05:16 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Objects.h"

t_colors	pattern_at_shape(t_shape *obj, double *world_pt)
{
	double	*obj_pt;
	double	*pat_pt;

	obj_pt = multiply_mtx_tp(inv((obj->transf)), world_pt);
	pat_pt = multiply_mtx_tp(inv(obj->material.pattern.transf), obj_pt);
	if (obj->material.pattern.id == STRIPES)
		return (stripe_at(obj->material.pattern, pat_pt));
	else if (obj->material.pattern.id == GRADIENT)
		return (gradient_at(obj->material.pattern, pat_pt));
	else if (obj->material.pattern.id == RING)
		return (ring_at(obj->material.pattern, pat_pt));
	else
		return (checker_at(obj->material.pattern, pat_pt));
}

void	set_transf(t_shape **s, t_matrix t)
{
	(*s)->transf = t;
	(*s)->inv = inv((*s)->transf);
	(*s)->transp = transp_mtx((*s)->inv);
	return ;
}

t_material	material(void)
{
	t_material	material;

	material.color = create_color(1, 1, 1);
	material.ambient = create_color(0.1, 0.1, 0.1);
	material.diffu = create_color(0.9, 0.9, 0.9);
	material.spec = create_color(0.9, 0.9, 0.9);
	material.shininess = 200;
	material.pattern.flag = false;
	return (material);
}

t_shape	*new_shape(void)
{
	t_pool_set	*set;
	t_shape		*shape;

	set = get_pool();
	shape = (t_shape *)alloc_pool(sizeof(t_shape), set->the_pool);
	shape->inv = id_mtx();
	shape->transp = id_mtx();
	shape->material = material();
	shape->transf = id_mtx();
	return (shape);
}
void	init_shape(t_shape_id id, struct s_shape **shape);

void	init_shape(t_shape_id id, t_shape **shape)
{
	(*shape) = new_shape();
	if (id == SPHERE)
	{
		(*shape)->obj = create_sp();
		(*shape)->id = SPHERE;
	}
	else if (id == PLANE)
	{
		(*shape)->obj = create_pl();
		(*shape)->id = PLANE;
	}
	else if (id == CYLINDER)
	{
		(*shape)->obj = create_cl();
		(*shape)->id = CYLINDER;
	}
}
