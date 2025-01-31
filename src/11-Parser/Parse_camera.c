/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/31 10:06:00 by tmalheir          #+#    #+#             */
/*   Updated: 2025/01/31 11:23:39 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"

// static bool	dir_is_norm(double *dir)
// {
// 	if (equal(mag(dir)))

// }

// static bool	dir_in_range(char *str)
// {
// 	double	nbr;

// 	nbr = ft_atod(str);
// 	if (nbr < - 1.0 || nbr > 1.0)
// 		return (false);
// 	return (true);
// }

// static bool	parse_dir(char *str)
// {
// 	int		idx;
// 	char	**dir;

// 	idx = 0;
// 	dir = ft_split(str, ',');
// 	if (!check_count(dir, 3))
// 		return (true_or_false(dir, false));
// 	while (dir[idx])
// 	{
// 		if (!is_double(dir[idx]) || !dir_in_range(dir[idx]))
// 			return (true_or_false(dir, false));
// 		idx++;
// 	}
// 	return (true_or_false(dir, true));
// }

// bool	parse_camera(char *line, t_world *world)
// {
// 	double		*view_pt;
// 	double		*dir;
// 	char		**info;

// 	info = ft_split(line, ' ');
// 	if (!check_count(info, 4) || !parse_pos(info[1]) || !parse_dir(info[2]));
// 		return (true_or_false(info, false));
// 	view_pt = allocate(sizeof(double) * 3);
// 	view_pt = pos_to_double(info[1]);
// 	world->scene.camera_pos = point(view_pt[X], view_pt[Y], view_pt[Z]);
// 	world->scene.has_camera += world->scene.has_camera + 1;
// 	if (world->scene.has_camera > 1)
// 	{
// 		warning("Error\n", "Only one camera allowed", "");
// 		return (true_or_false(info, false));
// 	}
// 	dir = allocate(sizeof(double) * 3);
// 	dir = pos_to_double(info[2]);
// 	world->scene.camera_dir = vector(dir[X], dir[Y], dir[Z]);
// 	return (true_or_false(info, true));
// }
