/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:44:47 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/06 16:44:49 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

#include "garbage_collector.h"
#include <stdbool.h>
#include <math.h>

#define MAX_DIFF 0.00001

typedef enum e_tuple_type
{
	VECTOR,
	POINT
} t_tuple_type;


typedef enum e_tuple_axis
{
	X,
	Y,
	Z,
	W
} t_tuple_axis;

double	*tuple(double x, double y, double z, double w);
double	*point(double x, double y, double z);
double	*vector(double x, double y, double z);
bool	equal(double nbr1, double nbr2);

double	*sum(double *tpl1, double *tpl2);
double	*sub(double *tpl1, double *tpl2);
double	*negate(double x, double y, double z, double w);
double	*negate_vector(double *vector);
double	*multiplication(double *vector, double factor);
double	*division(double *vector, double divisor);
double	magnitude(double *vector);
double	*norm(double *vector);
double	dot_product(double *vector1, double *vector2);
double *cross_product(double *vector1, double *vector2);

#endif // !TUPLES_H