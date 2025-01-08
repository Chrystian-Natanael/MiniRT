/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mem_pool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:29:01 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/08 09:04:44 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mem_pool.h"
#include "Utils.h"
#include "garbage_collector.h"

t_pool	*create_pool(size_t size)
{
	t_pool	*pool;

	pool = allocate(sizeof(t_pool));
	pool->mem = allocate(size);
	pool->size = size;
	pool->used = 0;
	return (pool);
}

t_pool	*alloc_pool(size_t size, t_pool *pool)
{
	void	*ptr;

	if (!pool || pool->used + size > pool->size)
		warning("Missing space in pool memmory", NULL, NULL);
	ptr = (char *)pool->mem + pool->used;
	if (!ptr)
		warning("Other missing space mns", NULL, NULL);
	pool->used += size;
	return (ptr);
}

t_pool_set	*get_pools(void)
{
	static t_pool_set	set;

	return (&set);
}

void	init_pools(void)
{
	t_pool_set	*set;

	set = get_pools();
	set->colors = create_pool(MAX_MEM);
	set->objects = create_pool(MAX_MEM);
	set->matrices = create_pool(MAX_MEM);
}
