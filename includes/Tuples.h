#ifndef TUPLES_H
# define TUPLES_H

#include "garbage_collector.h"

typedef enum e_tuple_type
{
	VECTOR,
	POINT
} t_tuple_type;

double	*point(double x, double y, double z);
double	*vector(double x, double y, double z);

#endif // !TUPLES_H