/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cnatanae <cnatanae@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:58:24 by cnatanae          #+#    #+#             */
/*   Updated: 2025/01/21 20:05:47 by cnatanae         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MiniRT.h"
#include <math.h>

int	main(void)
{
	// init_pools();

	mlx_t				*mlx;
	mlx_image_t			*image;
	t_paint				paint;


	t_camera		cam;

	t_world			*w;
	w = world();

	t_pool_set *set = get_pools();

	printf("0\n");
	// floor
	t_obj *floor = (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(PLANE, &floor->shape);
	floor->shape->material.color = create_color(1, 1, 1);
	set_transf(&floor->shape, multiply_mtx(translate(0.0, 0, 5), rotate_x(M_PI / 3)));
	insert_into_obj_list(&w->obj_lst, floor);

	// // Cylinder 1
	// t_obj *cl= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	// init_shape(CYLINDER, &cl->shape);
	// cl->shape->material.color = create_color(1.22, 0.096, 0.88);
	// cl->shape->material.diffu = create_color(0.7, 0.7, 0.7);
	// cl->shape->material.spec = create_color(0.3, 0.3, 0.3);
	// ((t_cl *)cl->shape->obj)->max = 0.6;
	// ((t_cl *)cl->shape->obj)->min = 0;
	// ((t_cl *)cl->shape->obj)->closed = true;
	// set_transf(&cl->shape, multiply_mtx(scale(2, 2, 2), rotate_x(3.141519 / 2)));
	// // set_transf(&cl->shape, scale(2, 2, 2));
	// // set_transf(&cl->shape, translate(-1.9, 3, 0.2));
	// insert_into_obj_list(&w->obj_lst, cl);


	// LIGHT SRC WHITE
	w->lights_lst = (t_lights *)alloc_pool(sizeof(t_lights), set->colors);
	w->lights_lst->light_src = pt_light(point(-10, 10, -10), create_color(1, 1, 1));

	printf("1\n");
	// CAM CONFIG
	cam = camera(300, 300, 3.14159 / 3);
	cam.transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));

	printf("2\n");
	// RENDER
	paint = render_canva(cam, w);

	printf("3\n");

	// canva2ppm(paint, "12comscalesp.ppm");
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(cam.hsize, cam.vsize, "PT8", true);
	image = canva2image(paint, mlx);

	printf("4\n");

	mlx_image_to_window(mlx, image, 0, 0);


	mlx_loop(mlx);
	mlx_terminate(mlx);
	quit(0);
}
