/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mem_pool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:29:01 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/04 12:03:13 by cnatanae         ###   ########.fr       */
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

void	init_pools(t_count_el counts)
{
	t_pool_set	*set;

	set = get_pools();
	set->colors = create_pool(counts.sp * sizeof(t_colors) * 4 +
	counts.pl * sizeof(t_colors) * 8 +
	counts.cy * sizeof(t_colors) * 8 + 
	(counts.lights * sizeof(t_colors)) * 20 +
	(counts.patterns * sizeof(t_colors) * 4) * 10 + 5e8);
	set->objects = create_pool(counts.sp * 4 + counts.pl * 4 + counts.cy * 4 + 5e8);
	set->matrices = create_pool((counts.sp * sizeof(t_matrix) * 128) +
	(counts.pl * sizeof(t_matrix) * 128) +
	(counts.cy * sizeof(t_matrix) * 128) +
	counts.lights * sizeof(t_matrix) * 60 +
	(counts.patterns * sizeof(t_matrix) * 40) + 5e8);
}
