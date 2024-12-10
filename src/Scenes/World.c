/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   World.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thaismalheiros <thaismalheiros@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 09:38:42 by thaismalhei       #+#    #+#             */
/*   Updated: 2024/12/10 15:47:00 by thaismalhei      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes.h"

static void	insert_into_obj_list(void *lst, t_obj *n1)
{
    t_obj	*tmp;

	tmp = (t_obj *)lst;
	while (tmp->next)
		tmp = tmp->next;
    tmp->next = n1;
    n1->prev = tmp;
}

void    create_obj_lst(t_world *world)
{
    t_obj       *node;
    t_pool_set  *set;
    
    set =get_pools();
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
        insert_into_obj_list(world->obj_lst, node);
    }
}

t_world *world(void)
{
    t_world     *world;
    t_pool_set  *set;
    
    set = get_pools();
    world = (t_world *)alloc_pool(sizeof(t_world), set->objects);
    world->obj_lst = NULL;
    world->lights_lst = NULL;
    return (world);
}
