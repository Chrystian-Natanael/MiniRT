#include "pt.h"

int main(void) {
	t_env env;
	t_projectile *projectile;
	int idx = 1;

	projectile = allocate(sizeof(t_projectile));
	projectile->position = point(0, 1, 0);
	projectile->velocity = norm(vector(1, 1, 0));

	env.gravity = vector(0, -0.1, 0);
	env.wind = vector(-0.01, 0, 0);

	while(projectile->position[Y] >= 0) {
		printf("Point is: x[%f] y[%f] z[%f]\nTick is: %i\n", projectile->position[X], projectile->position[Y], projectile->position[Z], idx);
		projectile = tick(env, *projectile);
		idx++;
	}
	printf("Point is: x[%f] y[%f] z[%f]\nTick is: %i\n", projectile->position[X], projectile->position[Y], projectile->position[Z], idx);
	quit(0);
}	