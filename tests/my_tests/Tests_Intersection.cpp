#include <gtest/gtest.h>
#include <cmath>

extern "C" {
	#include "Utils.h"
	#include "Intersections.h"
	#include "Tuples.h"
}

TEST(TesterRay, CreateAndQueryRay) {
	double *origin = point(1, 2, 3);
	double *direction = vector(4, 5, 6);
	t_ray r = create_ray(origin, direction);

	ASSERT_NE(r.origin, nullptr);
	ASSERT_NE(r.direction, nullptr);

	EXPECT_TRUE(equal(r.origin[0], origin[0]));
	EXPECT_TRUE(equal(r.origin[1], origin[1]));
	EXPECT_TRUE(equal(r.origin[2], origin[2]));
	EXPECT_TRUE(equal(r.origin[3], origin[3]));

	EXPECT_TRUE(equal(r.direction[0], direction[0]));
	EXPECT_TRUE(equal(r.direction[1], direction[1]));
	EXPECT_TRUE(equal(r.direction[2], direction[2]));
	EXPECT_TRUE(equal(r.direction[3], direction[3]));

	free(origin);
	free(direction);
}
