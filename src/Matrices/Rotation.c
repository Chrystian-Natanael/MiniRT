/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:39:47 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/22 10:54:21 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

/**
 * @brief Create a rotation matrix for rotation around the X-axis
 *
 * This function creates a 4x4 rotation matrix for rotating points around the
 * X-axis by the specified angle in radians.
 *
 * @param rad The angle in radians
 * @return The rotation matrix for the X-axis
 */
t_matrix	rotate_x(double rad)
{
	t_matrix	rot_mtx;

	rot_mtx = id_mtx();
	set_val((get_pos(1, 1, 4)), cos(rad), &rot_mtx);
	set_val((get_pos(1, 2, 4)), -sin(rad), &rot_mtx);
	set_val((get_pos(2, 1, 4)), sin(rad), &rot_mtx);
	set_val((get_pos(2, 2, 4)), cos(rad), &rot_mtx);
	rot_mtx.col = 4;
	rot_mtx.row = 4;
	return (rot_mtx);
}

/**
 * @brief Create a rotation matrix for rotation around the Y-axis
 *
 * This function creates a 4x4 rotation matrix for rotating points around the
 * Y-axis by the specified angle in radians.
 *
 * @param rad The angle in radians
 * @return The rotation matrix for the Y-axis
 */
t_matrix	rotate_y(double rad)
{
	t_matrix	rot_mtx;

	rot_mtx = id_mtx();
	set_val((get_pos(0, 0, 4)), cos(rad), &rot_mtx);
	set_val((get_pos(0, 2, 4)), sin(rad), &rot_mtx);
	set_val((get_pos(2, 0, 4)), -sin(rad), &rot_mtx);
	set_val((get_pos(2, 2, 4)), cos(rad), &rot_mtx);
	rot_mtx.col = 4;
	rot_mtx.row = 4;
	return (rot_mtx);
}

/**
 * @brief Create a rotation matrix for rotation around the Z-axis
 *
 * This function creates a 4x4 rotation matrix for rotating points around the
 * Z-axis by the specified angle in radians.
 *
 * @param rad The angle in radians
 * @return The rotation matrix for the Z-axis
 */
t_matrix	rotate_z(double rad)
{
	t_matrix	rot_mtx;

	rot_mtx = id_mtx();
	set_val((get_pos(0, 0, 4)), cos(rad), &rot_mtx);
	set_val((get_pos(0, 1, 4)), -sin(rad), &rot_mtx);
	set_val((get_pos(1, 0, 4)), sin(rad), &rot_mtx);
	set_val((get_pos(1, 1, 4)), cos(rad), &rot_mtx);
	rot_mtx.col = 4;
	rot_mtx.row = 4;
	return (rot_mtx);
}
