#include "pt.h"

int	main(void)
{
	t_colors	color_center;
	t_colors	color_hour;
	double		*center;
	t_matrix	trans_src;
	int			radius;
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_matrix	rot_z;
	double		*p;
	double		*transp_p;

	color_center = create_color(1, 0, 0);
	color_hour = create_color(1, 1, 1);
	center = point(WIDTH / 2, HEIGHT / 2, 0);
	trans_src = translate(center[X], center[Y], center[Z]);
	radius = 200;
	mlx = mlx_init(WIDTH, HEIGHT, "Puttingtogether4", true);
	image = mlx_new_image(mlx, WIDTH, HEIGHT);
	mlx_image_to_window(mlx, image, 0, 0);
	mlx_put_pixel(image, dtoi(center[X]), dtoi(center[Y]),
		rgb2hex(color_center));
	for (int hour = 0; hour <= 12; hour++)
	{
		rot_z = rotate_z((M_PI / 6) * hour);
		p = point(0, radius, 0);
		transp_p = multiply_mtx_tp(multiply_mtx(trans_src, rot_z), p);
		mlx_put_pixel(image, dtoi(transp_p[X]), dtoi(transp_p[Y]),
			rgb2hex(color_hour));
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	quit(0);
}
