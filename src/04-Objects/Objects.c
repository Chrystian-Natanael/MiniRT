/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaismalheiros <thaismalheiros@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:53:51 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/14 20:43:22 by thaismalhei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Objects.h"

t_colors	stripe_at_object(t_pattern pat, t_shape *obj, double *world_pt)
{
	double	*obj_pt;
	double	*pat_pt;
	
	obj_pt = multiply_mtx_tp(inv((obj->transf)), world_pt);
	pat_pt = multiply_mtx_tp(inv(pat.transf), obj_pt);
	return (stripe_at(pat, pat_pt));
}

void	set_transf_pattern(t_shape **s, t_matrix t)
{
	(*s)->material.pattern.transf = t;
	(*s)->material.pattern.inv = inv((*s)->material.pattern.inv);
	(*s)->material.pattern.transf = transp_mtx((*s)->material.pattern.inv);
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

	set = get_pools();
	shape = (t_shape *)alloc_pool(sizeof(t_shape), set->objects);
	shape->inv = id_mtx();
	shape->transp = id_mtx();
	shape->material = material();
	shape->transf = id_mtx();
	return (shape);
}

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
}
