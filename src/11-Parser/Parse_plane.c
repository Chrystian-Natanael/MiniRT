/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:38:49 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/06 16:55:35 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Objects.h"
#include "Tuples.h"
#include <math.h>

t_matrix	get_matrix(t_matrix scale, t_matrix rotate, t_matrix translate)
{
	t_matrix	result;

	result = multiply_mtx(multiply_mtx(scale, rotate), translate);
	return (result);
}

t_matrix	rotate_mtx(double *pos, double *norm, t_obj **obj)
{
	double	radius;
	double	x_angle;
	double	z_angle;

	x_angle = 0;
	z_angle = 0;
	calculate_rotation_angles(norm, &x_angle, &z_angle);
	radius = 1;
	if ((t_sp *)(*obj)->shape->id == SPHERE)
		radius = ((t_sp *)(*obj)->shape->obj)->radius;
	else if ((*obj)->shape->id == CYLINDER)
		radius = ((t_cl *)(*obj)->shape->obj)->radius;
	return (get_matrix(translate(pos[0], pos[1], pos[2]),
			get_rot_matrix(x_angle, z_angle),
			scale(radius, radius, radius)));
}

void	set_plane(t_obj **pl, char *pos, char *normal, char *col)
{
	double	*pl_pos;
	double	*pl_norm;
	double	*norm_plane;
	double	*norm_point;
	double	*pl_col;

	pl_pos = allocate(sizeof(double) * 3);
	pl_pos = pos_to_double(pos);
	norm_point = point(pl_pos[0], pl_pos[1], pl_pos[2]);
	pl_norm = allocate(sizeof(double) * 3);
	pl_norm = pos_to_double(normal);
	norm_plane = norm(vector(pl_norm[0], pl_norm[1], pl_norm[2]));
	pl_col = allocate(sizeof(double) * 3);
	pl_col = normalize_rgb_to_double(col);
	((t_pl *)(*pl)->shape->obj)->src = pl_pos;
	(*pl)->shape->material.color = create_color
		(pl_col[0], pl_col[1], pl_col[2]);
	set_transf(&(*pl)->shape, rotate_mtx(pl_pos, norm_plane, pl));
}

bool	parse_plane(char *line, t_world *world)
{
	char		**info;
	t_pool_set	*set;
	t_obj		*pl;

	info = ft_split(line, ' ');
	if (!check_count(info, 4) || !parse_pos(info[1]) || !parse_dir(info[2])
		|| !parse_color(info[3]))
		return (true_or_false(info, false));
	set = get_pool();
	pl = (t_obj *)alloc_pool(sizeof(t_obj), set->the_pool);
	init_shape(PLANE, &pl->shape);
	set_plane(&pl, info[1], info[2], info[3]);
	insert_into_obj_list(&world->obj_lst, pl);
	return (true_or_false(info, true));
}
