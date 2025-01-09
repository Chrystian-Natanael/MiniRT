/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Shade.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 13:56:07 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/09 12:14:43 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intersections.h"
#include "Scenes.h"

t_colors	shade_hit(t_world *w, t_comp comps)
{
	t_colors	shade_color;
	t_lights	*aux;
	t_pt_pos	pt;

	aux = w->lights_lst;
	pt.pos = comps.point;
	pt.in_shadow = comps.in_shadow;
	shade_color = lighting(comps.sp->material, aux->light_src, pt, comps.sig);
	aux = aux->next;
	while (aux)
	{
		shade_color = sum_colors(shade_color, lighting(comps.sp->material,
					aux->light_src, pt, comps.sig));
		aux = aux->next;
	}
	return (shade_color);
}

/**
 * @brief Computes the color at the intersection point of a ray with the world
 *
 * This function traces a ray through the world and calculates the color at the
 * point where the ray first intersects an object in the world. If no
 * intersection is found, it returns black. If an intersection is found, it
 * computes shading, taking into account whether the point is in shadow and the
 * material properties of the intersected object.
 *
 * @param w A pointer to the world configuration, which contains the objects,
 * and lights lists.
 * @param r The ray to trace through the world.
 * @return The color at the point where the ray intersects an object, or black
 * if no intersection is found.
 */
t_colors	color_at(t_world *w, t_ray r)
{
	t_colors	color_at_hit;
	t_comp		*comps;
	t_inter		*nearest_hit;
	t_inter		*hits;

	color_at_hit = create_color(0, 0, 0);
	hits = intersect_world(w, r);
	nearest_hit = hit(hits);
	if (nearest_hit)
	{
		comps = prepare_computations(nearest_hit, r);
		comps->in_shadow = is_shadowed(w, comps->over_point);
		color_at_hit = shade_hit(w, *comps);
	}
	return (color_at_hit);
}
