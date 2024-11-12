#include "pt.h"

t_projectile *tick(t_env env, t_projectile projectile) {
	t_projectile *new_projectile;

	double *new_point = sum(projectile.position, projectile.velocity);
	double *new_velocity = sum(sum(projectile.velocity, env.gravity), env.wind);
	new_projectile = allocate(sizeof(t_projectile));
	new_projectile->position = new_point;
	new_projectile->velocity = new_velocity;
	return (new_projectile);
}
