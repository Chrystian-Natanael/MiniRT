/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dolstadd_front.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:44:39 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/12 14:36:00 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_dolstadd_front(t_dolist **lst, t_element *new_e)
{
	if (!lst || !new_e)
		return ;
	new_e->next = (*lst)->first;
	new_e->prev = NULL;
	(*lst)->first->prev = new_e;
	(*lst)->first = new_e;
	(*lst)->size++;
}
