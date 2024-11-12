/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 12:58:29 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/12 14:36:19 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_e)
{
	t_list	*aux;

	aux = *lst;
	if (aux == NULL)
	{
		*lst = new_e;
		return ;
	}
	while (aux->next)
		aux = aux->next;
	aux->next = new_e;
}
