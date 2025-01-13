/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Objects.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 15:53:51 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/13 14:17:29 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Objects.h"

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
