/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:51:42 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/09 16:11:24 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Light_and_Shading.h"
#include "Objects.h"

double	*normal_at_sphere(t_shape *shape, double *wld_pt)
{
	double	*obj_pt;
	double	*obj_n;
	double	*wld_n;

	obj_pt = multiply_mtx_tp(shape->inv, wld_pt);
	obj_n = sub(obj_pt, point(0, 0, 0));
	wld_n = multiply_mtx_tp(shape->transp, obj_n);
	wld_n[W] = 0;
	return (norm(wld_n));
}

double	*normal_at(t_shape *shape, double *wld_pt)
{
	if (shape->id == SPHERE)
		return (normal_at_sphere(shape, wld_pt));
	return (0);
}
