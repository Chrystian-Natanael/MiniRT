/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scaling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:14:39 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/22 10:37:33 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

t_matrix	scale(double x, double y, double z)
{
	t_matrix	scl_mtx;

	scl_mtx = id_mtx();
	set_val(get_pos(0, 0, 4), x, &scl_mtx);
	set_val(get_pos(1, 1, 4), y, &scl_mtx);
	set_val(get_pos(2, 2, 4), z, &scl_mtx);
	scl_mtx.col = 4;
	scl_mtx.row = 4;
	return (scl_mtx);
}
