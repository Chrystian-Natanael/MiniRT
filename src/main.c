#include <stdio.h>
#include "Tuples.h"

int main(void)
{
	double *p = point(4, -4, 3);
	double *v = vector(4, -4, 3);

	printf("X=%f, Y=%f, Z=%f, W=%f\n", p[0], p[1], p[2], p[3]);
	printf("X=%f, Y=%f, Z=%f, W=%f\n", v[0], v[1], v[2], v[3]);
	quit(0);
}
