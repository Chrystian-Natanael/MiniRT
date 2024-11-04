#include "Tuples.h"

double	*point(double x, double y, double z)
{
	double *point;

	point = allocate(sizeof(double) * 4);
	point[0] = x;
	point[1] = y;
	point[2] = z;
	point[3] = POINT;
	return (point);
}

double	*vector(double x, double y, double z)
{
	double *vector;

	vector = allocate(sizeof(double) * 4);
	vector[0] = x;
	vector[1] = y;
	vector[2] = z;
	vector[3] = VECTOR;
	return (vector);
}

bool	equal(double nbr1, double nbr2)
{
	if (fabs(nbr1 - nbr2) < MAX_DIFF)
		return (true);
	return (false);
}