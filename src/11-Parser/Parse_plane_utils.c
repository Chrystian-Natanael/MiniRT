/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_plane_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:01:01 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/06 11:07:09 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

int	sign(int number)
{
	if (number > 0)
		return (1);
	else if (number < 0)
		return (-1);
	else
		return (0);
}

t_matrix	get_rot_matrix(double x, double z)
{
	t_matrix	result;

	result = multiply_mtx(rotate_x(x), rotate_z(z));
	return (result);
}

void	calculate_rotation_angles(double *norm, double *x, double *z)
{
	if (fabs(norm[1]) == 1)
	{
		*x = 0;
		*z = 0;
	}
	else if (fabs(norm[2]) == 1)
	{
		*x = sign(norm[2]) * (90 * PI / 180);
		*z = 0;
	}
	else if (fabs(norm[0]) == 1)
	{
		*x = 0;
		*z = sign(norm[0]) * (90 * PI / 180);
	}
	else
	{
		if (!equal(norm[0], MAX_DIFF))
			*x = acos(norm[0]);
		if (!equal(norm[2], MAX_DIFF))
			*z = acos(norm[2]);
	}
}
