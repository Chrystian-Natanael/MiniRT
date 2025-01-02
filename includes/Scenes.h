/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scenes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:15:09 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/02 10:51:14 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENES_H
# define SCENES_H

# include "Sphere.h"
# include "Light_and_Shading.h"
# include "Intersections.h"

typedef struct s_obj
{
	t_sp			*sp;
	struct s_obj	*next;
	struct s_obj	*prev;
}					t_obj;

typedef struct s_lights
{
	t_pt_light		light_src;
	t_sight			sig;
	struct s_lights	*next;
	struct s_lights	*prev;
}					t_lights;

typedef struct s_world
{
	t_obj		*obj_lst;
	t_lights	*lights_lst;
}				t_world;

t_world	*world(void);

void	create_obj_lst(t_world *world);
t_world	*default_world(void);
t_inter	*intersect_world(t_world *w, t_ray ray);

#endif
