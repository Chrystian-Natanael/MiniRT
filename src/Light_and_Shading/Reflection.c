/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reflection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:47:07 by cnatanae          #+#    #+#             */
/*   Updated: 2024/12/09 11:58:58 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Light_and_Shading.h"

double	*reflect(double *in, double *normal)
{
	double	*reflection;

	reflection = multiply(normal, 2);
	reflection = multiply(reflection, dot_prod(in, normal));
	return (sub(in, reflection));
}

t_pt_light	pt_light(double *pos, t_colors *intensity)
{
	t_pt_light	light;

	light.pos = pos;
	light.intensity = intensity;
	return (light);
}

t_colors	*lighting(t_material m, t_pt_light light, double *pos, t_sight sig)
{
	t_light_aux	data;

	data.effective_color = hada_colors(m.color, light.intensity);
	data.lightv = norm(sub(light.pos, pos));
	data.ambient = hada_colors(data.effective_color, m.ambient);
	data.light_dot_normal = dot_prod(data.lightv, sig.normal);
	if (data.light_dot_normal < 0)
	{
		data.diffuse = create_color(0, 0, 0);
		data.specular = create_color(0, 0, 0);
	}
	else
	{
		data.diffuse = multiply_colors(hada_colors(m.diffuse, data.effective_color), data.light_dot_normal);
		data.reflectv = reflect(negate_vector(data.lightv), sig.normal);
		data.reflect_dot_eye = dot_prod(data.reflectv, sig.eye);
		if (data.reflect_dot_eye < 1)
			data.specular = create_color(0, 0, 0);
		else
		{
			data.factor = pow(data.reflect_dot_eye, m.shininess);
			data.specular = multiply_colors(hada_colors(light.intensity, m.specular), data.factor);
		}
	}
	return (sum_colors(sum_colors(data.ambient, data.diffuse), data.specular));
}
