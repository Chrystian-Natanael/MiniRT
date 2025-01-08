#include "pt.h"

int	main(void)
{
	double		*p_ray_src;
	double		*v_ray_src;
	double		wall_z;
	double		wall_size;
	int			canvas_px;
	double		pixel_size;
	double		half;
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_colors	color;
	t_sp		*sp;
	int			y;
	int			x;
	double		world_y;
	double		world_x;
	double		*wall_hit;
	t_ray		ray;
	t_sp_inter	*val;
	t_inter		*lst;

	init_pools();
	p_ray_src = point(0, 0, -5);
	v_ray_src = vector(0, 0, -5);
	wall_z = -1;
	wall_size = 10.0;
	canvas_px = 1000;
	pixel_size = wall_size / (double)canvas_px;
	half = wall_size / 2;
	mlx = mlx_init(canvas_px, canvas_px, "Puttingtogether5", true);
	image = mlx_new_image(mlx, canvas_px, canvas_px);
	mlx_image_to_window(mlx, image, 0, 0);
	color = create_color(0, 0, 1);
	sp = create_sp();
	set_transf(sp, scale(2, 2, 2));
	y = -1;
	while (++y < canvas_px)
	{
		world_y = half - (pixel_size * y);
		x = -1;
		while (++x < canvas_px)
		{
			world_x = -half + (pixel_size * x);
			wall_hit = vector(world_x, world_y, wall_z);
			ray = create_ray(p_ray_src, norm(sub(wall_hit, v_ray_src)));
			val = intersect(sp, ray);
			lst = NULL;
			intersections(val->t1, sp, &lst);
			intersections(val->t2, sp, &lst);
			if (hit(lst))
				mlx_put_pixel(image, x, y, rgb2hex(color));
			;
		}
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	quit(0);
}
