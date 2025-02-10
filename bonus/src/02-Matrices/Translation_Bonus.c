/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Translation_Bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 12:54:32 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:38:30 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices_Bonus.h"

/**
 * @brief Create a translation matrix
 *
 * This function creates a 4x4 translation matrix for translating points by the
 * specified distances along the X, Y, and Z axes.
 *
 * @param x The translation distance for the X-axis
 * @param y The translation distance for the Y-axis
 * @param z The translation distance for the Z-axis
 * @return The translation matrix
 */
t_matrix	translate(double x, double y, double z)
{
	t_matrix	trnsl_mtx;

	trnsl_mtx = id_mtx();
	set_val((get_pos(0, 3, 4)), x, &trnsl_mtx);
	set_val((get_pos(1, 3, 4)), y, &trnsl_mtx);
	set_val((get_pos(2, 3, 4)), z, &trnsl_mtx);
	trnsl_mtx.col = 4;
	trnsl_mtx.row = 4;
	return (trnsl_mtx);
}
