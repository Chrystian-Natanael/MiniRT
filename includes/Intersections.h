/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intersections.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 11:06:07 by tmalheir          #+#    #+#             */
/*   Updated: 2024/11/27 15:31:46 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECTIONS_H
# define INTERSECTIONS_H

# include "Sphere.h"

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

t_lst_inter				*intersect(t_sphere *sphere, t_ray ray);

void					add2list(t_lst_inter **head, t_intersect value,
							t_sphere *s);

void					append_to_end(t_lst_inter *tmp, t_lst_inter *new1,
							t_lst_inter *new2);
void					insert_before(t_lst_inter *tmp, t_lst_inter *new_node);
void					insert_into_list(t_lst_inter **head, t_lst_inter *n1,
							t_lst_inter *n2);
void					initialize_head(t_lst_inter **head, t_intersect value,
							t_sphere *s);

#endif