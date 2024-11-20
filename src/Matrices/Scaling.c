/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:14:39 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/20 14:37:12 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

t_matrix	scaling(double x, double y, double z)
{
	t_matrix	scl_mtx;

	scl_mtx = identity();
	set_value_pos(get_pos(0, 0, 4), x, &scl_mtx);
	set_value_pos(get_pos(1, 1, 4), y, &scl_mtx);
	set_value_pos(get_pos(2, 2, 4), z, &scl_mtx);
	return (scl_mtx);
}
