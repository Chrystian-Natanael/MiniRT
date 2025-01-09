/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Is_shadowed.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 14:15:19 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/09 12:14:25 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Scenes.h"

bool	is_shadowed(t_world *world, double *pos)
{
	double	dist_pt_to_light;
	double	*dir;
	t_ray	ray;
	t_inter	*hit_lst;
	t_inter	*hit_pt;

	dist_pt_to_light = mag(sub(world->lights_lst->light_src.pos, pos));
	dir = norm(sub(world->lights_lst->light_src.pos, pos));
	ray = create_ray(pos, dir);
	hit_lst = intersect_world(world, ray);
	hit_pt = hit(hit_lst);
	if (hit_pt && hit_pt->pos < dist_pt_to_light)
		return (true);
	return (false);
}
