/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:38:42 by thaismalhei       #+#    #+#             */
/*   Updated: 2025/01/08 10:41:20 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes.h"

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

	set = get_pools();
	node = (t_lights *)alloc_pool(sizeof(t_lights), set->objects);
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

void	create_obj_lst(t_world *world)
{
	t_obj		*node;
	t_pool_set	*set;

	set = get_pools();
	if (!world->obj_lst)
	{
		world->obj_lst = (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
		world->obj_lst->next = NULL;
		world->obj_lst->prev = NULL;
		world->obj_lst->sp = create_sp();
	}
	else
	{
		node = (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
		node->sp = create_sp();
		insert_into_obj_list(&world->obj_lst, node);
	}
}

t_world	*world(void)
{
	t_world		*world;
	t_pool_set	*set;

	set = get_pools();
	world = (t_world *)alloc_pool(sizeof(t_world), set->objects);
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

	set = get_pools();
	dfl_world = world();
	light1 = pt_light(point(-10, 10, -10), create_color(1, 1, 1));
	insert_into_light_list(&dfl_world->lights_lst, light1);
	lst_obj = (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	lst_obj->sp = create_sp();
	lst_obj->next = (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	lst_obj->next->sp = create_sp();
	lst_obj->sp->material.color = create_color(0.8, 1.0, 0.6);
	lst_obj->sp->material.diffu = create_color(0.7, 0.7, 0.7);
	lst_obj->sp->material.spec = create_color(0.2, 0.2, 0.2);
	lst_obj->prev = NULL;
	lst_obj->next->prev = lst_obj;
	set_transf(lst_obj->next->sp, scale(0.5, 0.5, 0.5));
	insert_into_obj_list(&dfl_world->obj_lst, lst_obj);
	return (dfl_world);
}
