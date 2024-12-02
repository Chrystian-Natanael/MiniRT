/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/02 14:54:50 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/02 15:00:07 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"

t_lst_inter	hit(t_lst_inter *list)
{
	t_lst_inter	*tmp;

	tmp = list;
	while (tmp)
	{
		if (tmp->pos > 0)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
