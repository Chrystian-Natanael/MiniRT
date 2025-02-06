/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mem_pool.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:25:51 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/06 11:15:04 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_POOL_H
# define MEM_POOL_H

# include <stdio.h>
# include "Colors.h"
# include "Matrices.h"
# include "Count_el.h"

typedef struct s_pool
{
	size_t	used;
	size_t	size;
	void	*mem;
}			t_pool;

typedef struct s_pool_set
{
	t_pool	*the_pool;
}			t_pool_set;

t_pool		*create_pool(size_t size);
t_pool		*alloc_pool(size_t size, t_pool *pool);
t_pool_set	*get_pool(void);
void		init_pools(t_count_el count);

#endif // ! MEM_POOL_H
