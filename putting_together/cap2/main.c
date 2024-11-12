#include "pt.h"

int	double_to_int(double value) {
	return ((int)round(value));
}

int main(void) {
	t_env			env;
	t_projectile	*projectile;
	t_colors		*color1 = create_color(1, 0, 0);


	projectile = allocate(sizeof(t_projectile));
	projectile->position = point(0, 1, 0);
	projectile->position[Y] = HEIGHT - projectile->position[Y];
	projectile->velocity = multiplication(norm(vector(1, -1.8, 0)), 11.25);
	env.gravity = vector(0, 0.1, 0);
	env.wind = vector(-0.01, 0, 0);

	mlx_t		*mlx = mlx_init(WIDTH, HEIGHT, "Puttingtogether2", true);
	mlx_image_t	*image = mlx_new_image(mlx, WIDTH, HEIGHT);

	mlx_image_to_window(mlx, image, 0, 0);
	while(projectile->position[Y] <= HEIGHT) {
		mlx_put_pixel(image, double_to_int(projectile->position[X]), double_to_int(projectile->position[Y]), rgb_to_hexa(*color1));
		projectile = tick(env, *projectile);
	}
	mlx_loop(mlx);
}
