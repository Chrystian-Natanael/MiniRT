/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_Ambient_Bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 10:36:02 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/10 07:45:38 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser_Bonus.h"

bool	parse_ambient(char *line, t_world *world)
{
	double	*norm_col;
	char	**info;

	world->scene.has_ambient += 1;
	if (world->scene.has_ambient != 1)
		error("Error\n", "Only one ambient light allowed", "", 1);
	info = ft_split(line, ' ');
	if (!check_count(info, 3) || !is_double(info[1])
		|| !in_range_double(info[1]) || !parse_color(info[2]))
		return (true_or_false(info, false));
	norm_col = allocate(sizeof(double) * 3);
	norm_col = normalize_rgb_to_double(info[2]);
	world->scene.ambient = multiply_col(create_color
			(norm_col[0], norm_col[1], norm_col[2]), ft_atod(info[1]));
	return (true_or_false(info, true));
}
