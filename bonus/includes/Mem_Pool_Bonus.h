/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Mem_Pool_Bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 10:25:51 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 08:14:07 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MEM_POOL_BONUS_H
# define MEM_POOL_BONUS_H

# include <stdio.h>
# include "Colors_Bonus.h"
# include "Matrices_Bonus.h"
# include "Count_El_Bonus.h"

typedef struct s_pool
{
	size_t	used;
	size_t	size;
	size_t	saved_point;
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

#endif // ! MEM_POOL_BONUS_H
