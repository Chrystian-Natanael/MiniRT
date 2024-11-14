/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Get_Set_Matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 15:39:52 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/14 16:09:25 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

int	get_pos(int x, int y, int col)
{
	return (x * col + y);
}

double	get_value_pos(int x, int y, t_matrix matrix)
{
	return (matrix.content[x * matrix.col + y]);
}

void	set_value_pos(int pos, double value, t_matrix *matrix)
{
	matrix->content[pos] = value;
}
