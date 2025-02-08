/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mem_pool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:29:01 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/08 16:26:35 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Mem_pool.h"
#include "Utils.h"
#include "Canvas.h"
#include "garbage_collector.h"
#include "Count_el.h"

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

	if (!pool)
		error("Pool is null", NULL, NULL, 1);
	else if (!pool->mem)
		error("Pool memory is null", NULL, NULL, 1);
	else if (size == 0)
		error("Requested size is zero", NULL, NULL, 1);
	else if (!pool || pool->used + size > pool->size)
		error("Missing space in pool memmory", NULL, NULL, 1);
	ptr = (char *)pool->mem + pool->used;
	pool->used += size;
	return (ptr);
}

t_pool_set	*get_pool(void)
{
	static t_pool_set	set;

	return (&set);
}

void	init_pools(t_count_el counts)
{
	t_pool_set	*set;

	set = get_pool();
	set->the_pool = create_pool(counts.cy * sizeof(t_obj) * 32
			+ counts.pl * sizeof(t_obj) * 32
			+ counts.sp * sizeof(t_obj) * 32
			+ counts.lights * sizeof(t_lights) * 32
			+ counts.patterns * sizeof(t_lights) * 32
			* (WIDHT * HEIGHT * sizeof(t_colors)) + 10e11);
}
