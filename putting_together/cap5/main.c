#include "pt.h"

int	main(void)
{
	double		*p_ray_origin;
	double		*v_ray_origin;
	double		wall_z;
	double		wall_size;
	int			canvas_pixels;
	double		pixel_size;
	double		half;
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_colors	*color;
	t_sphere	*sphere;
	int			y;
	int			x;
	double		world_y;
	double		world_x;
	double		*wall_hit;
	t_ray		ray;
	t_intersect	*val;
	t_lst_inter	*lst;

	p_ray_origin = point(0, 0, -5);
	v_ray_origin = vector(0, 0, -5);
	wall_z = -1;
	wall_size = 10.0;
	canvas_pixels = 1000;
	pixel_size = wall_size / (double)canvas_pixels;
	half = wall_size / 2;
	mlx = mlx_init(canvas_pixels, canvas_pixels, "Puttingtogether5", true);
	image = mlx_new_image(mlx, canvas_pixels, canvas_pixels);
	mlx_image_to_window(mlx, image, 0, 0);
	color = create_color(0, 0, 1);
	sphere = create_sphere();
	set_transform(sphere, scale(2, 2, 2));
	y = -1;
	while (++y < canvas_pixels)
	{
		world_y = half - (pixel_size * y);
		x = -1;
		while (++x < canvas_pixels)
		{
			world_x = -half + (pixel_size * x);
			wall_hit = vector(world_x, world_y, wall_z);
			ray = create_ray(p_ray_origin, norm(sub(wall_hit, v_ray_origin)));
			val = intersect(sphere, ray);
			lst = NULL;
			intersections(val->t1, sphere, &lst);
			intersections(val->t2, sphere, &lst);
			if (hit(lst))
				mlx_put_pixel(image, x, y, rgb2hex(*color));;
		}

	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	quit(0);
}
