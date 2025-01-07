/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mem_pool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:25:51 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/07 17:06:32 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_POOL_H
# define MEM_POOL_H

# include <stdio.h>

// # define MAX_MEM 500000000 // for grafic
# define MAX_MEM 50000 // for tests

typedef struct s_pool
{
	size_t	used;
	size_t	size;
	void	*mem;
}			t_pool;

typedef struct s_pool_set
{
	t_pool	*colors;
	t_pool	*objects;
	t_pool	*matrices;
}			t_pool_set;

t_pool		*create_pool(size_t size);
t_pool		*alloc_pool(size_t size, t_pool *pool);
t_pool_set	*get_pools(void);
void		init_pools(void);

#endif // ! MEM_POOL_H
