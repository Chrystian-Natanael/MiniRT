/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmalheir <tmalheir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:06:07 by tmalheir          #+#    #+#             */
/*   Updated: 2024/12/04 10:05:31 by tmalheir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "Sphere.h"
# include "Matrices.h"

typedef struct s_ray
{
	double				*origin;
	double				*direction;
}						t_ray;

typedef struct s_lst_inter
{
	double				pos;
	t_sphere			*sphere;
	struct s_lst_inter	*next;
	struct s_lst_inter	*prev;
}						t_lst_inter;

typedef struct s_intersect
{
	t_sphere			*sphere;
	int					count;
	double				t1;
	double				t2;
}						t_intersect;

typedef struct s_coef
{
	double				a;
	double				b;
	double				c;
	double				discrim;
}						t_coef;

t_ray					create_ray(double *origin, double *direction);
double					*pos_ray(t_ray ray, double time);

t_intersect				*intersect(t_sphere *sphere, t_ray ray);

// void					add2list(t_lst_inter **head, t_intersect value,
// 							t_sphere *s);

void					intersections(double pos, t_sphere *s,
							t_lst_inter **dest);

void					append_to_end(t_lst_inter *tmp, t_lst_inter *new1);
void					insert_before(t_lst_inter *tmp, t_lst_inter *new_node);
void					insert_into_list(t_lst_inter **head, t_lst_inter *n1);
// void					initialize_head(t_lst_inter **head, t_intersect value,
							// t_sphere *s);
int						lst_count(t_lst_inter *lst);

t_lst_inter				*hit(t_lst_inter *list);

t_ray					transform(t_ray ray, t_matrix action);

#endif