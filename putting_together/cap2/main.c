#include "pt.h"

int	dtoi(double value)
{
	return ((int)round(value));
}

int	main(void)
{
	t_env			env;
	t_projectile	*projectile;
	t_colors		color1;
	mlx_t			*mlx;
	mlx_image_t		*image;

	color1 = create_color(1, 0, 0);
	projectile = allocate(sizeof(t_projectile));
	projectile->position = point(0, 1, 0);
	projectile->position[Y] = HEIGHT - projectile->position[Y];
	projectile->velocity = multiply(norm(vector(1, -1.8, 0)), 11.25);
	env.gravity = vector(0, 0.1, 0);
	env.wind = vector(-0.01, 0, 0);
	mlx = mlx_init(WIDHT, HEIGHT, "Puttingtogether2", true);
	image = mlx_new_image(mlx, WIDHT, HEIGHT);
	mlx_image_to_window(mlx, image, 0, 0);
	while (projectile->position[Y] <= HEIGHT)
	{
		mlx_put_pixel(image, dtoi(projectile->position[X]),
			dtoi(projectile->position[Y]), rgb2hex(color1));
		projectile = tick(env, *projectile);
	}
	mlx_loop(mlx);
}
