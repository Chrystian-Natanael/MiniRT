/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Matrices.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 09:43:54 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/20 16:34:47 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

t_matrix	create_matrix(int row, int col, double *elements)
{
	int			ir;
	int			ic;
	t_matrix	matrix;

	ft_bzero(&matrix, sizeof(t_matrix));
	if (!elements)
		error("empty elements", NULL, NULL, 1);
	if (row < 1 || col < 1)
		error("Rows and cols cannot be lesser than one", NULL, NULL, 1);
	ir = -1;
	matrix.row = row;
	matrix.col = col;
	while (++ir < row)
	{
		ic = -1;
		while (++ic < col)
		{
			matrix.content[get_pos(ir, ic, col)] = *elements;
			elements++;
		}
	}
	return (matrix);
}

bool	compare_matrix(t_matrix mtx_a, t_matrix mtx_b)
{
	int	ir;
	int	ic;
	int	pos;

	if (mtx_a.row != mtx_b.row || mtx_a.col != mtx_b.col)
		return (false);
	ir = -1;
	while (++ir < mtx_a.row)
	{
		ic = -1;
		while (++ic < mtx_a.col)
		{
			pos = get_pos(ir, ic, mtx_a.col);
			if (!equal(mtx_a.content[pos], mtx_b.content[pos]))
				return (false);
		}
	}
	return (true);
}

t_matrix	identity(void)
{
	static double	elements[16] = {1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0,
		1};

	return (create_matrix(4, 4, elements));
}
