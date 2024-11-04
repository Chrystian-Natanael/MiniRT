#include "Tuples.h"

double	*sub(double *tpl1, double *tpl2)
{
	int		idx;
	double	*res;

	res = allocate(sizeof(double) * 4);
	idx = -1;
	while (++idx < 4)
		res[idx] = tpl1[idx] - tpl2[idx];
	return (res);
}