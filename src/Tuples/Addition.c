/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Addition.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:45:14 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/04 17:32:06 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

double	*sum(double *tpl1, double *tpl2)
{
	int		idx;
	double	*res;


	if (tpl1[3] == 1 && tpl2[3] == 1)
		return (NULL);
	res = allocate(sizeof(double) * 4);
	idx = -1;
	while (++idx < 4)
		res[idx] = tpl1[idx] + tpl2[idx];
	return (res);
}
