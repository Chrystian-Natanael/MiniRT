/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:47:07 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/09 12:15:23 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes.h"

double	*reflect(double *in, double *normal)
{
	double	*reflection;

	reflection = multiply(normal, 2);
	reflection = multiply(reflection, dot_prod(in, normal));
	return (sub(in, reflection));
}

t_pt_light	pt_light(double *pos, t_colors intens)
{
	t_pt_light	light;

	light.pos = pos;
	light.intens = intens;
	return (light);
}

t_colors	lighting(t_material m, t_pt_light light, t_pt_pos pt, t_sight sig)
{
	t_light_aux	dt;

	dt.eff_col = hada_col(m.color, light.intens);
	dt.lightv = norm(sub(light.pos, pt.pos));
	dt.ambient = hada_col(dt.eff_col, m.ambient);
	dt.light_dtn = dot_prod(dt.lightv, sig.normal);
	if (dt.light_dtn < 0 || pt.in_shadow)
	{
		dt.diffu = create_color(0, 0, 0);
		dt.spec = create_color(0, 0, 0);
	}
	else
	{
		dt.diffu = multiply_col(hada_col(m.diffu, dt.eff_col), dt.light_dtn);
		dt.reflectv = reflect(negate_vector(dt.lightv), sig.normal);
		dt.reflect_dot_eye = dot_prod(dt.reflectv, sig.eye);
		if (dt.reflect_dot_eye <= 0)
			dt.spec = create_color(0, 0, 0);
		else
		{
			dt.factor = pow(dt.reflect_dot_eye, m.shininess);
			dt.spec = multiply_col(hada_col(light.intens, m.spec), dt.factor);
		}
	}
	return (sum_colors(sum_colors(dt.ambient, dt.diffu), dt.spec));
}
