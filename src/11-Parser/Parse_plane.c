/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_plane.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:38:49 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/05 16:35:28 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Objects.h"
#include <math.h>


int	sign(int number)
{
	if (number > 0)
		return (1);
	else if (number < 0)
		return (-1);
	else
		return (0);
}

void	calculate_rotation_angles(double *norm, double *x, double *z)
{
	if (fabs(norm[1]) == 1)
	{
		*x = 0;
		*z = 0;
	}
	else if (fabs(norm[2]) == 1)
	{
		*x = sign(norm[2]) * (90 * M_PI / 180);
		*z = 0;
	}
	else if (fabs(norm[0]) == 1)
	{
		*x = 0;
		*z = sign(norm[0]) * (90 * M_PI / 180);
	}
	else
	{
		if (!equal(norm[0], MAX_DIFF))
			*x = acos(norm[0]);
		if (!equal(norm[2], MAX_DIFF))
			*z = acos(norm[2]);
	}
}



t_matrix	get_matrix(t_matrix scale, t_matrix rotate, t_matrix translate)
{
	t_matrix	result;

	result = multiply_mtx(multiply_mtx(scale, rotate), translate);
	return (result);
}

t_matrix	get_rot_matrix(double x, double z)
{
	t_matrix	result;

	result = multiply_mtx(rotate_x(x), rotate_z(z));
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
	// else if ((t_pl *)(*pl)->shape->id == CYLINDER)
	// 	radius = shape.cylinder_shape.radius;
	return (
		get_matrix(
			translate(pos[0], pos[1], pos[2]),
			get_rot_matrix(x_angle, z_angle),
			scale(radius, radius, radius)
		)
	);
}



void	set_plane(t_obj **pl, double *norm, double *col, double *pos)
{
	((t_pl *)(*pl)->shape->obj)->src = pos;
	(*pl)->shape->material.color = create_color(col[0], col[1], col[2]);
	set_transf(&(*pl)->shape, rotate_mtx(pos, norm, pl));
}

bool	parse_plane(char *line, t_world *world)
{
	double		*norm_col;
	double		*pos;
	double		*norm;
	char		**info;
	t_pool_set	*set;
	t_obj		*pl;

	info = ft_split(line, ' ');

	// validando
	if (!check_count(info, 4) || !parse_pos(info[1]) || !parse_dir(info[2])
		|| !parse_color(info[3]))
		return (true_or_false(info, false));

	// convertendo a cor
	norm_col = allocate(sizeof(double) * 3);
	norm_col = normalize_rgb_to_double(info[3]);

	// convertendo a posicao
	pos = allocate(sizeof(double) * 3);
	pos = pos_to_double(info[1]);
	pos = point(pos[0], pos[1], pos[2]);

	norm = allocate(sizeof(double) * 3);
	norm = pos_to_double(info[2]);
	norm = vector(norm[0], norm[1], norm[2]);

	set = get_pool();
	pl = (t_obj *)alloc_pool(sizeof(t_obj), set->the_pool);
	init_shape(PLANE, &pl->shape);
	set_plane(&pl, norm, norm_col, pos);
	insert_into_obj_list(&world->obj_lst, pl);
	return (true_or_false(info, true));
}
