/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 16:44:47 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/22 10:06:01 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

# include "Utils.h"

typedef enum e_tuple_type
{
	VECTOR,
	POINT
}	t_tuple_type;

typedef enum e_tuple_axis
{
	X,
	Y,
	Z,
	W
}	t_tuple_axis;

double	*create_tp(double x, double y, double z, double w);
double	*point(double x, double y, double z);
double	*vector(double x, double y, double z);
bool	equal(double nbr1, double nbr2);

double	*sum(double *tpl1, double *tpl2);
double	*sub(double *tpl1, double *tpl2);
double	*negate(double x, double y, double z, double w);
double	*negate_vector(double *vector);
double	*multiply(double *vector, double factor);
double	*division(double *vector, double divisor);
double	mag(double *vector);
double	*norm(double *vector);
double	dot_prod(double *vector1, double *vector2);
double	*cross_prod(double *vector1, double *vector2);

#endif // !TUPLES_H