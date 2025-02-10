/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scaling_Bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:14:39 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:38:35 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices_Bonus.h"

/**
 * @brief Create a scaling matrix
 *
 * This function creates a 4x4 scaling matrix for scaling points by the specified
 * factors along the X, Y, and Z axes.
 *
 * @param x The scaling factor for the X-axis
 * @param y The scaling factor for the Y-axis
 * @param z The scaling factor for the Z-axis
 * @return The scaling matrix
 */
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
