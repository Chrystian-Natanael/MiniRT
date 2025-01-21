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

	void SetUp() override {
		init_pools();
		set = get_pools();
	}

	void TearDown() override {
		deallocate(set->colors->mem);
		deallocate(set->colors);
		deallocate(set->matrices->mem);
		deallocate(set->matrices);
		deallocate(set->objects->mem);
		deallocate(set->objects);
		deallocate(set);
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

TEST_F(FixtureObj, RayMissesCylinder) {
	struct {
		double *origin;
		double *direction;
	} examples[] = {
		{ point(1, 0, 0), vector(0, 1, 0) },
		{ point(0, 0, 0), vector(0, 1, 0) },
		{ point(0, 0, -5), vector(1, 1, 1) }
	};

	t_shape *cylinder;
	init_shape(CYLINDER, &cylinder);

	for (auto &example : examples) {
		t_ray ray = create_ray(example.origin, norm(example.direction));
		t_cl_inter *xs = (t_cl_inter *)intersect(cylinder, ray);
		EXPECT_EQ(xs, nullptr);
	}
}


TEST_F(FixtureObj, RayStrikesCylinder) {
	struct {
		double *origin;
		double *direction;
		double t1;
		double t2;
	} examples[] = {
		{ point(1, 0, -5), vector(0, 0, 1), 5, 5 },
		{ point(0, 0, -5), vector(0, 0, 1), 4, 6 },
		{ point(0.5, 0, -5), vector(0.1, 1, 1), 6.80798, 7.08872 }
	};

	t_shape *cylinder;
	init_shape(CYLINDER, &cylinder);

	for (auto &example : examples) {
		t_ray ray = create_ray(example.origin, norm(example.direction));
		t_cl_inter *xs = (t_cl_inter *)intersect(cylinder, ray);
		ASSERT_NE(xs, nullptr);
		EXPECT_EQ(xs->count, 2);
		EXPECT_TRUE(equal(xs->t1, example.t1));
		EXPECT_TRUE(equal(xs->t2, example.t2));
	}
}

TEST_F(FixtureObj, NormalVectorOnCylinder) {
	struct {
		double *point;
		double *expected_normal;
	} examples[] = {
		{ point(1, 0, 0), vector(1, 0, 0) },
		{ point(0, 5, -1), vector(0, 0, -1) },
		{ point(0, -2, 1), vector(0, 0, 1) },
		{ point(-1, 1, 0), vector(-1, 0, 0) }
	};

	t_shape *cylinder;
	init_shape(CYLINDER, &cylinder);

	for (auto &example : examples) {
		double *n = normal_at(cylinder, example.point);
		EXPECT_TRUE(equal(n[X], example.expected_normal[X]));
		EXPECT_TRUE(equal(n[Y], example.expected_normal[Y]));
		EXPECT_TRUE(equal(n[Z], example.expected_normal[Z]));
	}
}

TEST_F(FixtureObj, DefaultMinMaxForCylinder) {
	t_shape *cylinder;
	init_shape(CYLINDER, &cylinder);

	EXPECT_EQ(((t_cl *)cylinder->obj)->min, INT32_MIN);
	EXPECT_EQ(((t_cl *)cylinder->obj)->max, INT32_MAX);
}

TEST_F(FixtureObj, IntersectingConstrainedCylinder) {
	struct {
		double *point;
		double *direction;
		int count;
	} examples[] = {
		{ point(0, 1.5, 0), vector(0.1, 1, 0), 0 },
		{ point(0, 3, -5), vector(0, 0, 1), 0 },
		{ point(0, 0, -5), vector(0, 0, 1), 0 },
		{ point(0, 2, -5), vector(0, 0, 1), 0 },
		{ point(0, 1, -5), vector(0, 0, 1), 0 },
		{ point(0, 1.5, -2), vector(0, 0, 1), 2 }
	};

	t_shape *cylinder;
	init_shape(CYLINDER, &cylinder);
	((t_cl *)cylinder->obj)->min = 1;
	((t_cl *)cylinder->obj)->max = 2;

	for (auto &example : examples) {
		double *direction = norm(example.direction);
		t_ray r = create_ray(example.point, direction);
		t_cl_inter *xs = (t_cl_inter *)intersect(cylinder, r);
		EXPECT_EQ(xs->count, example.count);
	}
}

TEST_F(FixtureObj, DefaultClosedValueForCylinder) {
	t_shape *cylinder;
	init_shape(CYLINDER, &cylinder);

	EXPECT_FALSE(((t_cl *)cylinder->obj)->closed);
}


TEST_F(FixtureObj, IntersectingCapsOfClosedCylinder) {
	struct {
		double *point;
		double *direction;
		int count;
	} examples[] = {
		{ point(0, 3, 0), vector(0, -1, 0), 2 },
		{ point(0, 3, -2), vector(0, -1, 2), 2 },
		{ point(0, 4, -2), vector(0, -1, 1), 2 },
		{ point(0, 0, -2), vector(0, 1, 2), 2 },
		{ point(0, -1, -2), vector(0, 1, 1), 2 }
	};

	t_shape *cylinder;
	init_shape(CYLINDER, &cylinder);
	((t_cl *)cylinder->obj)->min = 1;
	((t_cl *)cylinder->obj)->max = 2;
	((t_cl *)cylinder->obj)->closed = true;

	for (auto &example : examples) {
		double *direction = norm(example.direction);
		t_ray r = create_ray(example.point, direction);
		t_cl_inter *xs = (t_cl_inter *)intersect(cylinder, r);
		EXPECT_EQ(xs->count, example.count);
	}
}

TEST_F(FixtureObj, NormalVectorOnCylinderEndCaps) {
	struct {
		double *point;
		double *expected_normal;
	} examples[] = {
		{ point(0, 1, 0), vector(0, -1, 0) },
		{ point(0.5, 1, 0), vector(0, -1, 0) },
		{ point(0, 1, 0.5), vector(0, -1, 0) },
		{ point(0, 2, 0), vector(0, 1, 0) },
		{ point(0.5, 2, 0), vector(0, 1, 0) },
		{ point(0, 2, 0.5), vector(0, 1, 0) }
	};

	t_shape *cylinder;
	init_shape(CYLINDER, &cylinder);
	((t_cl *)cylinder->obj)->min = 1;
	((t_cl *)cylinder->obj)->max = 2;
	((t_cl *)cylinder->obj)->closed = true;

	for (auto &example : examples) {
		double *n = normal_at(cylinder, example.point);
		EXPECT_TRUE(equal(n[X], example.expected_normal[X]));
		EXPECT_TRUE(equal(n[Y], example.expected_normal[Y]));
		EXPECT_TRUE(equal(n[Z], example.expected_normal[Z]));
	}
}
