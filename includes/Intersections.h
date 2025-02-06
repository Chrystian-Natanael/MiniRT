/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:06:07 by tmalheir          #+#    #+#             */
/*   Updated: 2025/02/06 09:36:34 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "Matrices.h"
# include "Objects.h"

typedef struct s_ray
{
	double			*src;
	double			*dir;
}					t_ray;

typedef struct s_inter
{
	double			pos;
	t_shape			*shape;
	struct s_inter	*next;
	struct s_inter	*prev;
}					t_inter;

typedef struct s_sp_inter
{
	t_sp			*sp;
	int				count;
	double			t1;
	double			t2;
}					t_sp_inter;

typedef struct s_pl_inter
{
	t_pl			*pl;
	int				count;
	double			t;
}					t_pl_inter;

typedef struct s_coef
{
	double			a;
	double			b;
	double			c;
	double			discrim;
}					t_coef;

t_ray		create_ray(double *src, double *dir);
double		*pos_ray(t_ray ray, double time);

void		*intersect(t_shape *shape, t_ray ray);
t_sp_inter	*intersect_sphere(t_shape *shape, t_ray ray);
t_pl_inter	*intersect_plane(t_shape *shape, t_ray ray);

t_sp_inter	*calc_intersection(t_coef coef);
t_coef		calc_coef(t_ray ray);
void		create_t_inter(t_shape *shape, void *lst, t_inter **dest);
void		intersections(double pos, t_shape *s, t_inter **dest);

void		append_to_end(t_inter *tmp, t_inter *new1);
void		insert_before(t_inter *tmp, t_inter *new_node);
void		insert_into_list(t_inter **head, t_inter *n1);
int			lst_count(t_inter *lst);

t_inter		*hit(t_inter *list);

t_ray		transform(t_ray ray, t_matrix action);

#endif