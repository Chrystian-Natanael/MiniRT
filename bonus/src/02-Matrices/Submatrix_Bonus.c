/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Submatrix_Bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 14:18:06 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/10 07:38:33 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices_Bonus.h"

/**
 * @brief Auxiliary function to create a submatrix by removing a
 * specified row and column
 *
 * This function fills the result matrix with the elements of the
 * srcal matrix, excluding the specified row and column.
 *
 * @param res The result matrix to be filled
 * @param mtx The srcal matrix
 * @param sub_r The row index to be removed
 * @param sub_c The column index to be removed
 */
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

/**
 * @brief Create a submatrix by removing a specified row and column
 *
 * This function creates a submatrix by removing the specified row and column
 * from the srcal matrix. If the row or column index is negative, an error
 * message is displayed and the program is terminated.
 *
 * @param matrix The srcal matrix
 * @param sub_r The row index to be removed
 * @param sub_c The column index to be removed
 * @return The resulting submatrix
 */
t_matrix	submtx(t_matrix matrix, int sub_r, int sub_c)
{
	t_matrix	res;

	if (sub_r < 0 || sub_c < 0)
		error("Error\n", "Impossible to remove negative row or col", "", 1);
	init_mtx(&res);
	res.row = matrix.row - 1;
	res.col = matrix.col - 1;
	submtx_aux(&res, matrix, sub_r, sub_c);
	return (res);
}
