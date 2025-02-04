/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:58:24 by cnatanae          #+#    #+#             */
/*   Updated: 2025/02/04 12:08:15 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"

int	main(int argc, char **argv)
{
	t_world		*world;
	t_paint		paint;
	t_camera	cam;
	mlx_t		*mlx;
	mlx_image_t	*image;

	world = parser(argc, argv);

	t_pool_set *set = get_pools();

	// sp1
	t_obj *sp1= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(SPHERE, &sp1->shape);
	sp1->shape->material.color = create_color(0.3, 0, 1);
	insert_into_obj_list(&world->obj_lst, sp1);

	// sp2
	t_obj *sp2= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(SPHERE, &sp2->shape);
	sp2->shape->material.color = create_color(0.3, 0, 1);
	insert_into_obj_list(&world->obj_lst, sp2);

	// sp3
	t_obj *sp3= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(SPHERE, &sp3->shape);
	sp3->shape->material.color = create_color(0.3, 0, 1);
	sp3->shape->material.pattern = stripe_pattern(create_color(1, 1, 1), create_color(1, 0, 0));
	set_pattern_transf(&sp3->shape->material.pattern, scale(.1, .1, .1));
	insert_into_obj_list(&world->obj_lst, sp3);

	// pl1
	t_obj *pl1= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(PLANE, &pl1->shape);
	pl1->shape->material.color = create_color(0.3, 0, 1);
	insert_into_obj_list(&world->obj_lst, pl1);

	// pl2
	t_obj *pl2= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(PLANE, &pl2->shape);
	pl2->shape->material.color = create_color(0.3, 0, 1);
	insert_into_obj_list(&world->obj_lst, pl2);

	// pl3
	t_obj *pl3= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(PLANE, &pl3->shape);
	pl3->shape->material.color = create_color(0.3, 0, 1);
	insert_into_obj_list(&world->obj_lst, pl3);

	// pl4
	t_obj *pl4= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(PLANE, &pl4->shape);
	pl4->shape->material.color = create_color(0.3, 0, 1);
	insert_into_obj_list(&world->obj_lst, pl4);

	// LIGHT SRC 1
	t_pt_light light_1 = pt_light(point(5, -5, -5), create_color(1, 1, 1));
	insert_into_light_list(&world->lights_lst, light_1);

	// LIGHT SRC 2
	t_pt_light light_2 = pt_light(point(5, -5, -5), create_color(0, 0, 1));
	insert_into_light_list(&world->lights_lst, light_2);

	// LIGHT SRC 3
	t_pt_light light_3 = pt_light(point(5, -5, -5), create_color(0, 0, 1));
	insert_into_light_list(&world->lights_lst, light_3);

	// CAM CONFIG
	cam = camera(200, 200, 3.14159 / 3);
	cam.transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));

	// RENDER
	printf("test1\n");
	paint = render_canva(cam, world);
	printf("test2\n");

	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(cam.hsize, cam.vsize, "PT8", true);
	image = canva2image(paint, mlx);
	printf("test3\n");

	mlx_image_to_window(mlx, image, 0, 0);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	quit(0);
}
