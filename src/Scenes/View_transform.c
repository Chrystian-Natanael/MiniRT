/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   View_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/03 09:09:03 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/03 09:47:41 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes.h"

static void	set_val_mtx(t_matrix *mtx, double *forw, double *left, double *t_up)
{
	set_val(get_pos(0, 0, 4), left[X], mtx);
	set_val(get_pos(0, 1, 4), left[Y], mtx);
	set_val(get_pos(0, 2, 4), left[Z], mtx);
	set_val(get_pos(1, 0, 4), t_up[X], mtx);
	set_val(get_pos(1, 1, 4), t_up[Y], mtx);
	set_val(get_pos(1, 2, 4), t_up[Z], mtx);
	set_val(get_pos(2, 0, 4), -forw[X], mtx);
	set_val(get_pos(2, 1, 4), -forw[Y], mtx);
	set_val(get_pos(2, 2, 4), -forw[Z], mtx);
}

t_matrix	view_transform(double *from, double *to, double *up)
{
	double		*forward;
	double		*left;
	double		*true_up;
	t_matrix	orientation;

	forward = norm(sub(to, from));
	left = cross_prod(forward, norm(up));
	true_up = cross_prod(left, forward);
	orientation = id_mtx();
	set_val_mtx(&orientation, forward, left, true_up);
	return (multiply_mtx(orientation, translate(-from[X], -from[Y], -from[Z])));
}
