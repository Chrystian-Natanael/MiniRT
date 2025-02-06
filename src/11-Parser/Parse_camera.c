/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:06:00 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/06 11:19:59 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Canvas.h"
#include "Scenes.h"
#include "math.h"

static bool	check_fov(char *str)
{
	if (!is_double(str) || (ft_atod(str) < 0 || ft_atod(str) > 180))
		return (false);
	return (true);
}

bool	dir_in_range(char *str)
{
	double	nbr;

	nbr = ft_atod(str);
	if (nbr < -1.0 || nbr > 1.0)
		return (false);
	return (true);
}

bool	parse_dir(char *str)
{
	int		idx;
	char	**dir;

	idx = 0;
	dir = ft_split(str, ',');
	if (!check_count(dir, 3))
		return (true_or_false(dir, false));
	while (dir[idx])
	{
		if (!is_double(dir[idx]) || !dir_in_range(dir[idx]))
			return (true_or_false(dir, false));
		idx++;
	}
	return (true_or_false(dir, true));
}

bool	parse_camera(char *line, t_world *world)
{
	double	*from;
	double	*dir;
	char	**info;

	world->scene.has_camera += 1;
	if (world->scene.has_camera > 1)
		error("Error\n", "Only one camera allowed", "", 1);
	info = ft_split(line, ' ');
	if (!check_count(info, 4) || !parse_pos(info[1]) || !parse_dir(info[2])
		|| !check_fov(info[3]))
		return (true_or_false(info, false));
	from = allocate(sizeof(double) * 3);
	from = pos_to_double(info[1]);
	world->scene.camera_from = point(from[X], from[Y], from[Z]);
	dir = allocate(sizeof(double) * 3);
	dir = pos_to_double(info[2]);
	world->scene.camera_to = sum
		(world->scene.camera_from, norm(vector(dir[X], dir[Y], dir[Z])));
	world->camera = camera(WIDHT, HEIGHT, (ft_atod(info[3])) * (PI / 180));
	world->camera.transform = view_transform
		(world->scene.camera_from, world->scene.camera_to, world->camera.up);
	return (true_or_false(info, true));
}
