/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_light.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:36:02 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/04 15:18:04 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

bool	parse_light(char *line, t_world *world)
{
	double		*norm_col;
	double		*pos;
	char		**info;

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
	world->scene.light_pos[X] = pos[X];
	world->scene.light_pos[Y] = pos[Y];
	world->scene.light_pos[Z] = pos[Z];
	return (true_or_false(info, true));
}
