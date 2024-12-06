/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:06:07 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/06 10:18:48 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "Matrices.h"
# include "Sphere.h"

typedef struct s_ray
{
	double			*src;
	double			*dir;
}					t_ray;

typedef struct s_inter
{
	double			pos;
	t_sp			*sp;
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

typedef struct s_coef
{
	double			a;
	double			b;
	double			c;
	double			discrim;
}					t_coef;

t_ray				create_ray(double *src, double *dir);
double				*pos_ray(t_ray ray, double time);

t_sp_inter			*intersect(t_sp *sp, t_ray ray);

void				intersections(double pos, t_sp *s, t_inter **dest);

void				append_to_end(t_inter *tmp, t_inter *new1);
void				insert_before(t_inter *tmp, t_inter *new_node);
void				insert_into_list(t_inter **head, t_inter *n1);
int					lst_count(t_inter *lst);

t_inter				*hit(t_inter *list);

t_ray				transform(t_ray ray, t_matrix action);

#endif