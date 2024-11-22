/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Set_Matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:39:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/22 10:23:25 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

int	get_pos(int x, int y, int col)
{
	return (x * col + y);
}

double	get_val_pos(int x, int y, t_matrix matrix)
{
	return (matrix.content[x * matrix.col + y]);
}

void	set_val(int pos, double value, t_matrix *matrix)
{
	matrix->content[pos] = value;
}
