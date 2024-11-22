/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Submatrix.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:18:06 by cnatanae          #+#    #+#             */
/*   Updated: 2024/11/22 10:38:18 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

static void	submtx_aux(t_matrix *res, t_matrix mtx, int sub_r, int sub_c)
{
	int		ir_m;
	int		ic_m;
	int		ir_r;
	int		ic_r;
	double	vl_pos_m;

	ir_m = -1;
	ir_r = 0;
	while (++ir_m < mtx.row)
	{
		if (ir_m == sub_r)
			continue ;
		ic_m = -1;
		ic_r = 0;
		while (++ic_m < mtx.col)
		{
			if (ic_m == sub_c)
				continue ;
			vl_pos_m = get_val_pos(ir_m, ic_m, mtx);
			set_val(get_pos(ir_r, ic_r, res->col), vl_pos_m, res);
			ic_r++;
		}
		ir_r++;
	}
}

t_matrix	submtx(t_matrix matrix, int sub_r, int sub_c)
{
	t_matrix	res;

	if (sub_r < 0 || sub_c < 0)
		error("Error\n", "Impossible to remove negative row or col", NULL, 1);
	ft_bzero(&res, sizeof(t_matrix));
	res.row = matrix.row - 1;
	res.col = matrix.col - 1;
	submtx_aux(&res, matrix, sub_r, sub_c);
	return (res);
}
