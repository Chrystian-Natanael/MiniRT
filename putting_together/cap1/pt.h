#ifndef PT_H
#define PT_H

# include <stdio.h>
# include "../../includes/Tuples.h"

typedef struct s_projectile {
	double	*position;
	double	*velocity;
}	t_projectile;

typedef struct s_env {
	double	*gravity;
	double	*wind;
}	t_env;

t_projectile *tick(t_env env, t_projectile projectile);

#endif // !PT_H