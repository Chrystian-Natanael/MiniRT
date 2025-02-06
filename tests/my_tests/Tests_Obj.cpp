#include <gtest/gtest.h>
#include <cmath>

extern "C" {
	#include "Matrices.h"
	#include "Utils.h"
	#include "Light_and_Shading.h"
	#include "Tuples.h"
	#include "Intersections.h"
	#include "Objects.h"
	#include <stdbool.h>
}

class FixtureObj : public ::testing::Test {
protected:
	t_pool_set *set;

	void SetUp() override
	{
		set = get_pool();
		set->the_pool = create_pool(500000);
	}

	void TearDown() override
	{
		deallocate(set->the_pool);
	}
};

TEST_F(FixtureObj, NormalOfPlaneIsConstantEverywhere) {
	t_shape *plane;

	plane = NULL;
	init_shape(PLANE, &plane);

	double *n1 = normal_at(plane, point(0, 0, 0));
	double *n2 = normal_at(plane, point(10, 0, -10));
	double *n3 = normal_at(plane, point(-5, 0, 150));

	double *expected_normal = vector(0, 1, 0);

	EXPECT_TRUE(equal(n1[X], expected_normal[X]));
	EXPECT_TRUE(equal(n1[Y], expected_normal[Y]));
	EXPECT_TRUE(equal(n1[Z], expected_normal[Z]));

	EXPECT_TRUE(equal(n2[X], expected_normal[X]));
	EXPECT_TRUE(equal(n2[Y], expected_normal[Y]));
	EXPECT_TRUE(equal(n2[Z], expected_normal[Z]));

	EXPECT_TRUE(equal(n3[X], expected_normal[X]));
	EXPECT_TRUE(equal(n3[Y], expected_normal[Y]));
	EXPECT_TRUE(equal(n3[Z], expected_normal[Z]));
}

TEST_F(FixtureObj, IntersectWithRayParallelToPlane) {
	t_shape *plane;

	plane = NULL;
	init_shape(PLANE, &plane);

	t_ray ray = create_ray(point(0, 10, 0), vector(0, 0, 1));
	t_pl_inter *xs = (t_pl_inter *)intersect(plane, ray);
	EXPECT_EQ(xs, nullptr);
}

TEST_F(FixtureObj, IntersectWithCoplanarRay) {
	t_shape *plane;

	plane = NULL;
	init_shape(PLANE, &plane);

	t_ray ray = create_ray(point(0, 0, 0), vector(0, 0, 1));
	t_pl_inter *xs = (t_pl_inter *)intersect(plane, ray);
	EXPECT_EQ(xs, nullptr);
}

TEST_F(FixtureObj, IntersectWithRayFromAbove) {
	t_shape *plane;

	plane = NULL;
	init_shape(PLANE, &plane);

	t_ray ray = create_ray(point(0, 1, 0), vector(0, -1, 0));
	t_pl_inter *xs = (t_pl_inter *)intersect(plane, ray);

	ASSERT_NE(xs, nullptr);
	EXPECT_EQ(xs->count, 1);
	EXPECT_DOUBLE_EQ(xs->t, 1.0);
	EXPECT_EQ(xs->pl->src[X], ((t_pl *)plane->obj)->src[X]);
	EXPECT_EQ(xs->pl->src[Y], ((t_pl *)plane->obj)->src[Y]);
	EXPECT_EQ(xs->pl->src[Z], ((t_pl *)plane->obj)->src[Z]);
}

TEST_F(FixtureObj, IntersectWithRayFromBelow) {
	t_shape *plane;

	plane = NULL;
	init_shape(PLANE, &plane);

	t_ray ray = create_ray(point(0, -1, 0), vector(0, 1, 0));
	t_pl_inter *xs = (t_pl_inter *)intersect(plane, ray);

	ASSERT_NE(xs, nullptr);
	EXPECT_EQ(xs->count, 1);
	EXPECT_DOUBLE_EQ(xs->t, 1.0);

	EXPECT_EQ(xs->pl->src[X], ((t_pl *)plane->obj)->src[X]);
	EXPECT_EQ(xs->pl->src[Y], ((t_pl *)plane->obj)->src[Y]);
	EXPECT_EQ(xs->pl->src[Z], ((t_pl *)plane->obj)->src[Z]);
}
