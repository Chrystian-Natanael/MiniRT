/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 14:39:47 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/20 19:05:08 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

t_matrix	rotation_x(double rad)
{
	t_matrix	rot_mtx;

	rot_mtx = identity();
	set_value_pos((get_pos(1, 1, 4)), cos(rad), &rot_mtx);
	set_value_pos((get_pos(1, 2, 4)), -sin(rad), &rot_mtx);
	set_value_pos((get_pos(2, 1, 4)), sin(rad), &rot_mtx);
	set_value_pos((get_pos(2, 2, 4)), cos(rad), &rot_mtx);
	rot_mtx.col = 4;
	rot_mtx.row = 4;
	return (rot_mtx);
}

t_matrix	rotation_y(double rad)
{
	t_matrix	rot_mtx;

	rot_mtx = identity();
	set_value_pos((get_pos(0, 0, 4)), cos(rad), &rot_mtx);
	set_value_pos((get_pos(0, 2, 4)), sin(rad), &rot_mtx);
	set_value_pos((get_pos(2, 0, 4)), -sin(rad), &rot_mtx);
	set_value_pos((get_pos(2, 2, 4)), cos(rad), &rot_mtx);
	rot_mtx.col = 4;
	rot_mtx.row = 4;
	return (rot_mtx);
}

t_matrix	rotation_z(double rad)
{
	t_matrix	rot_mtx;

	rot_mtx = identity();
	set_value_pos((get_pos(0, 0, 4)), cos(rad), &rot_mtx);
	set_value_pos((get_pos(0, 1, 4)), -sin(rad), &rot_mtx);
	set_value_pos((get_pos(1, 0, 4)), sin(rad), &rot_mtx);
	set_value_pos((get_pos(1, 1, 4)), cos(rad), &rot_mtx);
	rot_mtx.col = 4;
	rot_mtx.row = 4;
	return (rot_mtx);
}
