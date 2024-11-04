#ifndef TUPLES_H
# define TUPLES_H

#include "garbage_collector.h"
#include <stdbool.h>
#include <math.h>

#define MAX_DIFF 0.00001

typedef enum e_tuple_type
{
	VECTOR,
	POINT
} t_tuple_type;

double	*point(double x, double y, double z);
double	*vector(double x, double y, double z);
bool	equal(double nbr1, double nbr2);

double	*sum(double *tpl1, double *tpl2);
double	*sub(double *tpl1, double *tpl2);

#endif // !TUPLES_H