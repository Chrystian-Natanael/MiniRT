/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Scenes.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 08:15:09 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/07 17:24:40 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENES_H
# define SCENES_H

# include "Objects.h"
# include "Light_and_Shading.h"
# include "Intersections.h"

typedef struct s_comp
{
	double	pos;
	t_shape	*shape;
	double	*point;
	double	*over_point;
	t_sight	sig;
	bool	inside;
	bool	in_shadow;
}			t_comp;

typedef struct s_obj
{
	t_shape			*shape;
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

typedef struct s_scene
{
	t_colors	ambient;
	int			has_ambient;
	double		*camera_from;
	double		*camera_to;
	int			has_camera;
	t_colors	light;
	double		*light_pos;
	int			has_light;
	bool		save_img;
	char		*file_name;
}			t_scene;

typedef struct s_camera
{
	double		hsize;
	double		vsize;
	double		field_view;
	double		pixel_sz;
	double		half_widht;
	double		half_heigth;
	double		*up;
	t_matrix	transform;
}				t_camera;

typedef struct s_world
{
	t_obj		*obj_lst;
	t_lights	*lights_lst;
	t_scene		scene;
	t_camera	camera;
}				t_world;

t_world		*world(void);

void		create_obj_lst(t_world *world, t_shape_id id);
void		insert_into_obj_list(t_obj **lst, t_obj *n1);
void		insert_into_light_list(t_lights **lst, t_pt_light n1);
t_world		*default_world(void);
t_inter		*intersect_world(t_world *w, t_ray ray);
t_comp		*prepare_computations(t_inter *intersec, t_ray ray);
t_colors	shade_hit(t_world *w, t_comp comps);
t_colors	color_at(t_world *w, t_ray r);
t_matrix	view_transform(double *from, double *to, double *up);
t_camera	camera(int hsize, int vsize, double field_view);
t_ray		ray_for_pixel(t_camera cam, double px, double py);
bool		is_shadowed(t_world *world, double *pos, t_pt_light light);

#endif
