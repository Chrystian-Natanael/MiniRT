#include "pt.h"
#include <math.h>
#include "Codam.h"

int	main(void) {
	init_pools();

	t_paint			paint;

	mlx_t				*mlx;
	mlx_image_t	*image;


	t_camera		cam;

	t_world			*w;
	w = world();
	t_pool_set *set = get_pools();

	// floor
	create_obj_lst(w);
	set_transf(w->obj_lst->sp, scale(10, 0.01, 10));
	w->obj_lst->sp->material.color = create_color(1, 0.9, 0.9);
	w->obj_lst->sp->material.spec = create_color(0, 0, 0);


	// Left wall
	create_obj_lst(w);
	w->obj_lst->next->sp->material.color = create_color(1, 0.9, 0.9);
	w->obj_lst->next->sp->material.spec = create_color(0, 0, 0);
	set_transf(w->obj_lst->next->sp, multiply_mtx(multiply_mtx(multiply_mtx(translate(0, 0, 5), rotate_y(-3.14159 / 4)), rotate_x(3.14159/2)), scale(10, 0.01, 10)));

	// right wall
	create_obj_lst(w);
	w->obj_lst->next->next->sp->material.color = create_color(1, 0.9, 0.9);
	w->obj_lst->next->next->sp->material.spec = create_color(0, 0, 0);
	set_transf(w->obj_lst->next->next->sp, multiply_mtx(multiply_mtx(multiply_mtx(translate(0, 0, 5), rotate_y(3.14159/4)), rotate_x(3.14159 / 2)), scale(10, 0.01, 10)));

	// Large Sphere
	create_obj_lst(w);
	set_transf(w->obj_lst->next->next->next->sp, translate(-0.5, 1, 0.5));
	w->obj_lst->next->next->next->sp->material.color = create_color(1, 1, 1);
	w->obj_lst->next->next->next->sp->material.diffu = create_color(0.7, 0.7, 0.7);
	w->obj_lst->next->next->next->sp->material.spec = create_color(0.3, 0.3, 0.3);


	// Smaller green Sphere
	create_obj_lst(w);
	set_transf(w->obj_lst->next->next->next->next->sp, multiply_mtx(translate(1.5, 0.5, -0.5), scale(0.5, 0.5, 0.5)));
	w->obj_lst->next->next->next->next->sp->material.color = create_color(1, 1, 1);
	w->obj_lst->next->next->next->next->sp->material.diffu = create_color(0.7, 0.7, 0.7);
	w->obj_lst->next->next->next->next->sp->material.spec = create_color(0.3, 0.3, 0.3);

	// Smallest Sphere
	create_obj_lst(w);
	set_transf(w->obj_lst->next->next->next->next->next->sp, multiply_mtx(translate(-1.5, 0.33, -0.75), scale(0.33, 0.33, 0.33)));
	w->obj_lst->next->next->next->next->next->sp->material.color = create_color(1, 1, 1);
	w->obj_lst->next->next->next->next->next->sp->material.diffu = create_color(0.7, 0.7, 0.7);
	w->obj_lst->next->next->next->next->next->sp->material.spec = create_color(0.3, 0.3, 0.3);

	// LIGHT SRC WHITE
	w->lights_lst = (t_lights *)alloc_pool(sizeof(t_lights), set->colors);
	w->lights_lst->light_src = pt_light(point(-10, 10, -10), create_color(1, 1, 1));

	// LIGHT SRC 2
	t_pt_light light_2 = pt_light(point(5, -5, -5), create_color(1, 0, 0));
	insert_into_light_list(&w->lights_lst, light_2);

	// LIGHT SRC 3
	t_pt_light light_3 = pt_light(point(-10, 10, -6), create_color(0, 0, 1));
	insert_into_light_list(&w->lights_lst, light_3);

	// CAM CONFIG
	cam = camera(800, 800, 3.14159 / 3);
	cam.transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), vector(0, 1, 0));

	printf("0\n");
	// RENDER
	paint = render_canva(cam, w);

	printf("1\n");
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	mlx = mlx_init(cam.hsize, cam.vsize, "PT7", true);
	printf("2\n");
	image = canva2image(paint, mlx);
	printf("3\n");

	mlx_image_to_window(mlx, image, 0, 0);

	mlx_loop(mlx);
	mlx_terminate(mlx);
	quit(0);
}
