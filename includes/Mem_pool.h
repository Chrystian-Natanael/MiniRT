/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mem_pool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:25:51 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/22 13:48:46 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_POOL_H
# define MEM_POOL_H

# include <stdio.h>

// # define MAX_MEM 199999999999 // for grafic full screen
// # define MAX_MEM 99999999999 // for simple grafic (max 1000x1000)
# define MAX_MEM 500000 // for tests

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
