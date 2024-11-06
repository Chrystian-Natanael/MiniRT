/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Magnitude.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 14:55:50 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/06 15:06:29 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Tuples.h"

static double	magnitude_aux(double x, double y, double z, double w)
{
	double	nbr_pow;

	nbr_pow = pow(x, 2) + pow(y, 2) + pow(z, 2) + pow(w, 2);
	return (sqrt(nbr_pow));
}

double	magnitude(double *vector)
{
	return (magnitude_aux(vector[X], vector[Y], vector[Z], vector[W]));
}
