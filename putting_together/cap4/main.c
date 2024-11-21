#include "pt.h"

int main(void) {
    t_colors *color_center = create_color(1, 0, 0);
    t_colors *color_hour = create_color(1, 1, 1);

	double *center = point(WIDTH/2, HEIGHT/2, 0);

	t_matrix trans_origin = translation(center[X], center[Y], center[Z]);

	int radius = 200;

	mlx_t		*mlx = mlx_init(WIDTH, HEIGHT, "Puttingtogether4", true);
	mlx_image_t	*image = mlx_new_image(mlx, WIDTH, HEIGHT);

	mlx_image_to_window(mlx, image, 0, 0);
	mlx_put_pixel(image, double_to_int(center[X]), double_to_int(center[Y]), rgb_to_hexa(*color_center));
	for (int hour = 0 ; hour <= 12 ; hour++) {
		t_matrix rot_z = rotation_z((M_PI / 6) * hour);
		double *p = point(0, radius, 0);
		double *transp_p = matrix_tuple_multiply(matrix_multiply(trans_origin, rot_z), p);
		mlx_put_pixel(image, double_to_int(transp_p[X]), double_to_int(transp_p[Y]), rgb_to_hexa(*color_hour));
	}

    mlx_loop(mlx);
    mlx_terminate(mlx);
    quit(0);
}
