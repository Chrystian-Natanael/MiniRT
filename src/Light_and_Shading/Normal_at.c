/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Normal_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:51:42 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/06 14:21:55 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Light_and_Shading.h"

double	*normal_at(t_sp sp, double *wld_pt)
{
	double	*obj_pt;
	double	*obj_n;
	double	*wld_n;

	obj_pt = multiply_mtx_tp(sp.inv, wld_pt);
	obj_n = sub(obj_pt, point(0, 0, 0));
	wld_n = multiply_mtx_tp(sp.transp, obj_n);
	wld_n[W] = 0;
	return (norm(wld_n));
}
