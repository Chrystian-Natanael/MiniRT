/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Lst_Functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:49:26 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:18:46 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

void	append_to_end(t_inter *tmp, t_inter *new1)
{
	tmp->next = new1;
	new1->prev = tmp;
}

void	insert_before(t_inter *tmp, t_inter *new_node)
{
	if (tmp->prev)
	{
		tmp->prev->next = new_node;
		new_node->prev = tmp->prev;
	}
	tmp->prev = new_node;
	new_node->next = tmp;
}

void	insert_into_list(t_inter **head, t_inter *n1)
{
	t_inter	*tmp;

	tmp = *head;
	while (tmp)
	{
		if (tmp->pos >= n1->pos)
		{
			insert_before(tmp, n1);
			break ;
		}
		else if (!tmp->next)
		{
			append_to_end(tmp, n1);
			break ;
		}
		tmp = tmp->next;
	}
}

int	lst_count(t_inter *lst)
{
	int		idx;
	t_inter	*tmp;

	tmp = lst;
	idx = 0;
	while (tmp)
	{
		idx++;
		tmp = tmp->next;
	}
	return (idx);
}
