/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:38:42 by thaismalhei       #+#    #+#             */
/*   Updated: 2025/02/04 15:33:00 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes.h"
#include "Objects.h"

void	insert_into_obj_list(t_obj **lst, t_obj *n1)
{
	t_obj	*tmp;

	tmp = *lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	n1->prev = tmp;
	if (!tmp)
		*lst = n1;
	else
		tmp->next = n1;
}

void	insert_into_light_list(t_lights **lst, t_pt_light n1)
{
	t_lights	*tmp;
	t_lights	*node;
	t_pool_set	*set;

	set = get_pool();
	node = (t_lights *)alloc_pool(sizeof(t_lights), set->The_pool);
	node->light_src.pos = n1.pos;
	node->light_src.intens = n1.intens;
	tmp = *lst;
	while (tmp && tmp->next)
		tmp = tmp->next;
	node->prev = tmp;
	if (!tmp)
		*lst = node;
	else
		tmp->next = node;
}

void	create_obj_lst(t_world *world, t_shape_id id)
{
	t_obj	*node;
	t_pool_set	*set;

	set = get_pool();
	if (!world->obj_lst)
	{
		world->obj_lst = (t_obj *)alloc_pool(sizeof(t_obj), set->The_pool);
		world->obj_lst->next = NULL;
		world->obj_lst->prev = NULL;
		init_shape(id, &world->obj_lst->shape);
	}
	else
	{
		node = (t_obj *)alloc_pool(sizeof(t_obj), set->The_pool);
		init_shape(id, &node->shape);
		insert_into_obj_list(&world->obj_lst, node);
	}
}

t_world	*world(void)
{
	t_world	*world;
	t_pool_set	*set;

	set = get_pool();
	world = (t_world *)alloc_pool(sizeof(t_world), set->The_pool);
	world->obj_lst = NULL;
	world->lights_lst = NULL;
	return (world);
}

t_world	*default_world(void)
{
	t_world		*dfl_world;
	t_obj		*lst_obj;
	t_pt_light	light1;
	t_pool_set	*set;
	t_shape		*shape;

	set = get_pool();
	dfl_world = world();
	light1 = pt_light(point(-10, 10, -10), create_color(1, 1, 1));
	shape = NULL;
	insert_into_light_list(&dfl_world->lights_lst, light1);
	init_shape(SPHERE, &shape);
	lst_obj = (t_obj *)alloc_pool(sizeof(t_obj), set->The_pool);
	lst_obj->shape = shape;
	lst_obj->shape->material.color = create_color(0.8, 1.0, 0.6);
	lst_obj->shape->material.diffu = create_color(0.7, 0.7, 0.7);
	lst_obj->shape->material.spec = create_color(0.2, 0.2, 0.2);
	lst_obj->next = (t_obj *)alloc_pool(sizeof(t_obj), set->The_pool);
	lst_obj->next->shape = NULL;
	init_shape(SPHERE, &lst_obj->next->shape);
	lst_obj->prev = NULL;
	lst_obj->next->prev = lst_obj;
	set_transf(&lst_obj->next->shape, scale(0.5, 0.5, 0.5));
	insert_into_obj_list(&dfl_world->obj_lst, lst_obj);
	return (dfl_world);
}
