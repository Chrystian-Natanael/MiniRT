/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:49:26 by cnatanae          #+#    #+#             */
/*   Updated: 2024/12/02 14:49:32 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

void	append_to_end(t_lst_inter *tmp, t_lst_inter *new1)
{
	tmp->next = new1;
	new1->prev = tmp;
}

void	insert_before(t_lst_inter *tmp, t_lst_inter *new_node)
{
	if (tmp->prev)
	{
		tmp->prev->next = new_node;
		new_node->prev = tmp->prev;
	}
	tmp->prev = new_node;
	new_node->next = tmp;
}

void	insert_into_list(t_lst_inter **head, t_lst_inter *n1)
{
	t_lst_inter	*tmp;

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

// void	initialize_head(t_lst_inter **head, t_intersect value, t_sphere *s)
// {
// 	*head = allocate(sizeof(t_lst_inter));
// 	(*head)->pos = value.t1;
// 	(*head)->sphere = s;
// 	(*head)->next = allocate(sizeof(t_lst_inter));
// 	(*head)->next->pos = value.t2;
// 	(*head)->next->sphere = s;
// }

int	lst_count(t_lst_inter *lst)
{
	int			idx;
	t_lst_inter	*tmp;

	tmp = lst;
	idx = 0;
	while (tmp)
	{
		idx++;
		tmp = tmp->next;
	}
	return (idx);
}
