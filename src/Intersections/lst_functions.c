/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:49:26 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/27 15:31:37 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

void	append_to_end(t_lst_inter *tmp, t_lst_inter *new1, t_lst_inter *new2)
{
	new1->next = new2;
	new2->prev = new1;
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

void	insert_into_list(t_lst_inter **head, t_lst_inter *n1, t_lst_inter *n2)
{
	t_lst_inter	*tmp;
	bool		t1_ready;

	tmp = *head;
	t1_ready = false;
	while (tmp)
	{
		if (tmp->pos >= n1->pos && !t1_ready)
		{
			insert_before(tmp, n1);
			t1_ready = true;
		}
		if (t1_ready && tmp->pos >= n2->pos)
		{
			insert_before(tmp, n2);
			break ;
		}
		if (!tmp->next)
		{
			append_to_end(tmp, n1, n2);
			break ;
		}
		tmp = tmp->next;
	}
}

void	initialize_head(t_lst_inter **head, t_intersect value, t_sphere *s)
{
	*head = allocate(sizeof(t_lst_inter));
	(*head)->pos = value.t1;
	(*head)->sphere = s;
	(*head)->next = allocate(sizeof(t_lst_inter));
	(*head)->next->pos = value.t2;
	(*head)->next->sphere = s;
}
