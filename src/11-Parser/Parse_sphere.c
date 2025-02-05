/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 14:38:49 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/05 16:49:26 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Parser.h"
#include "Objects.h"

t_matrix	rotate_mtx(double *pos, double *norm, t_obj **obj);

void	set_sphere(t_obj **sp, char *diam, double *col, double *pos)
{
	double	radius;

	radius = ft_atod(diam) / 2;
	((t_sp *)(*sp)->shape->obj)->radius = radius;
	((t_sp *)(*sp)->shape->obj)->src = pos;
	(*sp)->shape->material.color = create_color(col[0], col[1], col[2]);
	// set_transf(&(*sp)->shape, multiply_mtx(translate(pos[X], pos[Y], pos[Z]), \
	// scale(radius, radius, radius)));
	set_transf(&(*sp)->shape, rotate_mtx(pos, point(0, 1, 0), sp));
}

bool	parse_sphere(char *line, t_world *world)
{
	double		*norm_col;
	double		*pos; // cordenadas
	char		**info; // [0] = sp, [1] = pos, [2] = diametro, [3] = cor
	t_pool_set	*set;
	t_obj		*sp;

	info = ft_split(line, ' ');

	// validando
	if (!check_count(info, 4) || !parse_pos(info[1]) || !is_double(info[2])
		|| !parse_color(info[3]))
		return (true_or_false(info, false));

	// convertendo a cor
	norm_col = allocate(sizeof(double) * 3);
	norm_col = normalize_rgb_to_double(info[3]);

	// convertendo a posicao
	pos = allocate(sizeof(double) * 3);
	pos = pos_to_double(info[1]);

	set = get_pool();
	sp = (t_obj *)alloc_pool(sizeof(t_obj), set->the_pool);
	init_shape(SPHERE, &sp->shape);
	set_sphere(&sp, info[2], norm_col, pos);
	insert_into_obj_list(&world->obj_lst, sp);
	return (true_or_false(info, true));
}

// sp  3,1,0 2 255,51,255