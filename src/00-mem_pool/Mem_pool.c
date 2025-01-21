/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mem_pool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:29:01 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/21 16:59:32 by cnatanae         ###   ########.fr       */
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
		error("Missing space in pool memmory", NULL, NULL, 1);
	ptr = (char *)pool->mem + pool->used;
	pool->used += size;
	return (ptr);
}

t_pool_set	*get_pools(void)
{
	static t_pool_set	set;

	return (&set);
}

__attribute__((constructor)) void	init_pools(void)
{
	t_pool_set	*set;

	set = get_pools();
	set->colors = create_pool(MAX_MEM);
	set->objects = create_pool(MAX_MEM);
	set->matrices = create_pool(MAX_MEM);
}
