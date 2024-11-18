/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cofactor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 09:49:50 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/18 10:25:14 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Matrices.h"

double	cofactor(t_matrix matrix, int sub_r, int sub_c)
{
	double	minor_submtx;

	minor_submtx = minor(matrix, sub_r, sub_c);
	if ((sub_r + sub_c) % 2 != 0)
		return (minor_submtx * -1);
	return (minor_submtx);
}
