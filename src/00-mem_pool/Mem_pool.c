/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mem_pool.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:29:01 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/08 18:59:21 by cnatanae         ###   ########.fr       */
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
		error("Error\n", "Pool is null", "", 1);
	else if (!pool->mem)
		error("Error\n", "Pool memory is null", "", 1);
	else if (size == 0)
		error("Error\n", "Requested size is zero", "", 1);
	else if (!pool || pool->used + size > pool->size)
		error("Error\n", "Missing space in pool memmory", "", 1);
	ptr = (char *)pool->mem + pool->used;
	pool->used += size;
	ft_bzero(ptr, size);
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
	size_t		size;

	set = get_pool();
	size = 100e6;
	if (counts.cy + counts.pl + counts.sp >= 80)
		size += 100e8 * (counts.sp + counts.cy + counts.pl);
	set->the_pool = create_pool(size);
}
