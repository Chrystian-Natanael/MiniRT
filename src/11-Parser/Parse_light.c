/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:36:02 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/06 11:22:56 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Tuples.h"

bool	parse_light(char *line, t_world *world)
{
	double		*norm_col;
	double		*pos;
	char		**info;
	t_pt_light	light;

	world->scene.has_light += 1;
	if (world->scene.has_light > 1)
		error("Error\n", "Only one light allowed", "", 1);
	info = ft_split(line, ' ');
	if (!check_count(info, 4) || !parse_pos(info[1]) || !is_double(info[2])
		|| !in_range_double(info[2]) || !parse_color(info[3]))
		return (true_or_false(info, false));
	norm_col = allocate(sizeof(double) * 3);
	norm_col = normalize_rgb_to_double(info[3]);
	world->scene.light = multiply_col
		(create_color(norm_col[0], norm_col[1], norm_col[2]), ft_atod(info[2]));
	pos = allocate(sizeof(double) * 3);
	pos = pos_to_double(info[1]);
	world->scene.light_pos = create_tp(pos[X], pos[Y], pos[Z], POINT);
	light = pt_light(world->scene.light_pos, create_color
			(norm_col[X], norm_col[Y], norm_col[Z]));
	insert_into_light_list(&world->lights_lst, light);
	return (true_or_false(info, true));
}
