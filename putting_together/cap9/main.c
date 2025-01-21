#include "pt.h"
#include <math.h>
#include "Codam.h"

int	main(void) {
	init_pools();

	mlx_t				*mlx;
	mlx_image_t			*image;
	t_paint				paint;


	t_camera		cam;

	t_world			*w;
	w = world();

	t_pool_set *set = get_pools();

	// floor
	t_obj *floor= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(PLANE, &floor->shape);
	floor->shape->material.pattern = checker_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	// floor->shape->material.color = create_color(0.3, 0, 1);
	insert_into_obj_list(&w->obj_lst, floor);

	// Large Sphere
	t_obj *sp1= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(SPHERE, &sp1->shape);
	set_transf(&sp1->shape, translate(-2.0, 1, 1.2));
	// sp1->shape->material.pattern = checker_pattern(create_color(1, 1, 1), create_color(0, 0, 0));
	sp1->shape->material.pattern = gradient_pattern(create_color(0, 1, 0), create_color(0, 0, 1));
	sp1->shape->material.color = create_color(0.2, 0.2, 0.3);
	sp1->shape->material.diffu = create_color(0.7, 0.7, 0.7);
	sp1->shape->material.spec = create_color(0.3, 0.3, 0.3);
	insert_into_obj_list(&w->obj_lst, sp1);

	// Large Sphere 2
	t_obj *sp2= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(SPHERE, &sp2->shape);
	set_transf(&sp2->shape, translate(-1, 0.9, 3));
	sp2->shape->material.pattern = stripe_pattern(create_color(1, 1, 1), create_color(1, 0, 0));
	set_pattern_transf(&sp2->shape->material.pattern, scale(.1, .1, .1));
	// sp2->shape->material.color = create_color(1, 1, 1);
	sp2->shape->material.diffu = create_color(0.7, 0.7, 0.7);
	sp2->shape->material.spec = create_color(0.3, 0.3, 0.3);
	insert_into_obj_list(&w->obj_lst, sp2);

	// Large Sphere 3
	t_obj *sp3= (t_obj *)alloc_pool(sizeof(t_obj), set->objects);
	init_shape(SPHERE, &sp3->shape);
	set_transf(&sp3->shape, translate(-0.09, 1.0, 5));
	sp3->shape->material.color = create_color(0.2, 0.02, 0.06);
	sp3->shape->material.diffu = create_color(0.7, 0.7, 0.7);
	sp3->shape->material.spec = create_color(0.3, 0.3, 0.3);
	insert_into_obj_list(&w->obj_lst, sp3);


	// LIGHT SRC WHITE
	w->lights_lst = (t_lights *)alloc_pool(sizeof(t_lights), set->colors);
	w->lights_lst->light_src = pt_light(point(-10, 10, -10), create_color(1, 1, 1));

	// LIGHT SRC 2
	t_pt_light light_2 = pt_light(point(5, -5, -5), create_color(0, 0, 1));
	insert_into_light_list(&w->lights_lst, light_2);

	// CAM CONFIG
	cam = camera(700, 700, 3.14159 / 3);
	cam.transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));

	// RENDER
	paint = render_canva(cam, w);


	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(cam.hsize, cam.vsize, "PT8", true);
	image = canva2image(paint, mlx);


	mlx_image_to_window(mlx, image, 0, 0);


	mlx_loop(mlx);
	mlx_terminate(mlx);
	quit(0);
}

