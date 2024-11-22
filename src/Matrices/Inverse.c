/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:20:00 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/22 10:24:29 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

static t_matrix	inv_aux(t_matrix matrix);

static t_matrix	inv_aux(t_matrix matrix)
{
	double		det_mtx;
	int			ir;
	int			ic;
	double		value;
	t_matrix	inv;

	ft_bzero(&inv, sizeof(t_matrix));
	det_mtx = det(matrix);
	ir = -1;
	inv.col = matrix.col;
	inv.row = matrix.row;
	while (++ir < matrix.row)
	{
		ic = -1;
		while (++ic < matrix.col)
		{
			value = cofactor(matrix, ir, ic) / det_mtx;
			set_val(get_pos(ic, ir, inv.col), value, &inv);
		}
	}
	return (inv);
}

t_matrix	inv(t_matrix matrix)
{
	if (det(matrix) == 0)
		error("Error\n", "msn", NULL, 1);
	return (inv_aux(matrix));
}
