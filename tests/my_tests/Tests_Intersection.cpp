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

TEST(TesterRay, ComputePointFromDistance) {
	double *origin = point(2, 3, 4);
	double *direction = vector(1, 0, 0);
	t_ray r = create_ray(origin, direction);

	double *pos0 = pos_ray(r, 0);
	double *pos1 = pos_ray(r, 1);
	double *posNeg1 = pos_ray(r, -1);
	double *pos2_5 = pos_ray(r, 2.5);

	EXPECT_TRUE(equal(pos0[0], 2) && equal(pos0[1], 3) && equal(pos0[2], 4) && equal(pos0[3], 1));
	EXPECT_TRUE(equal(pos1[0], 3) && equal(pos1[1], 3) && equal(pos1[2], 4) && equal(pos1[3], 1));
	EXPECT_TRUE(equal(posNeg1[0], 1) && equal(posNeg1[1], 3) && equal(posNeg1[2], 4) && equal(posNeg1[3], 1));
	EXPECT_TRUE(equal(pos2_5[0], 4.5) && equal(pos2_5[1], 3) && equal(pos2_5[2], 4) && equal(pos2_5[3], 1));

	free(origin);
	free(direction);
	free(pos0);
	free(pos1);
	free(posNeg1);
	free(pos2_5);
}

TEST(TesterRay, RayIntersectsSphereAtTwoPoints) {
	double *origin = point(0, 0, -5);
	double *direction = vector(0, 0, 1);
	t_ray r = create_ray(origin, direction);
	t_sphere *s = create_sphere();

	t_intersect *lst = intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, 4.0));
	EXPECT_TRUE(equal(lst->t2, 6.0));
	EXPECT_TRUE(equal(lst->count, 2));

	free(origin);
	free(direction);
	free(s);
	free(lst);
}

TEST(TesterRay, RayIntersectsSphereAtTangent) {
	double *origin = point(0, 1, -5);
	double *direction = vector(0, 0, 1);
	t_ray r = create_ray(origin, direction);
	t_sphere *s = create_sphere();

	t_intersect *lst = intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, 5.0));
	EXPECT_TRUE(equal(lst->t2, 5.0));
	EXPECT_TRUE(equal(lst->count, 2));

	free(origin);
	free(direction);
	free(s);
	free(lst);
}

TEST(TesterRay, RayMissesSphere) {
	double *origin = point(0, 2, -5);
	double *direction = vector(0, 0, 1);
	t_ray r = create_ray(origin, direction);
	t_sphere *s = create_sphere();

	t_intersect *lst = intersect(s, r);

	EXPECT_EQ(lst->count, 0);

	free(origin);
	free(direction);
	free(s);
	free(lst);
}

TEST(TesterRay, RayOriginatesInsideSphere) {
	double *origin = point(0, 0, 0);
	double *direction = vector(0, 0, 1);
	t_ray r = create_ray(origin, direction);
	t_sphere *s = create_sphere();

	t_intersect *lst = intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, -1.0));
	EXPECT_TRUE(equal(lst->t2, 1.0));
	EXPECT_EQ(lst->count, 2);


	free(origin);
	free(direction);
	free(s);
	free(lst);
}

TEST(TesterRay, SphereIsBehindRay) {
	double *origin = point(0, 0, 5);
	double *direction = vector(0, 0, 1);
	t_ray r = create_ray(origin, direction);
	t_sphere *s = create_sphere();

	t_intersect *lst = intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, -6.0));
	EXPECT_TRUE(equal(lst->t2, -4.0));
	EXPECT_EQ(lst->count, 2);


	free(origin);
	free(direction);
	free(s);
	free(lst);
}

TEST(TesterRay, IntersectionEncapsulatesTAndObject) {
	t_sphere *s = create_sphere();
	t_lst_inter *dest;

	dest = NULL;
	intersections(3.5, s, &dest);

	EXPECT_TRUE(equal(dest->pos, 3.5));
	EXPECT_EQ(dest->sphere->origin, s->origin);
	EXPECT_EQ(dest->sphere->radius, s->radius);

	free(s);
	free(dest);
}

TEST(TesterRay, AggregatingIntersections) {
	t_sphere *s = create_sphere();
	t_lst_inter *dest;

	dest = NULL;
	intersections(1, s, &dest);
	intersections(2, s, &dest);

	EXPECT_EQ(lst_count(dest), 2);
	EXPECT_TRUE(equal(dest->pos, 1));
	EXPECT_TRUE(equal(dest->next->pos, 2));

	free(s);
	free(dest->next);
	free(dest);
}

TEST(TesterRay, IntersectSetsObjectOnIntersection) {
	double *origin = point(0, 0, -5);
	double *direction = vector(0, 0, 1);
	t_ray r = create_ray(origin, direction);
	t_sphere *s = create_sphere();
	t_lst_inter *dest;

	dest = NULL;
	t_intersect *xs = intersect(s, r);
	intersections(xs->t1, s, &dest);
	intersections(xs->t2, s, &dest);


	EXPECT_EQ(xs->count, 2);
	EXPECT_EQ(lst_count(dest), 2);
	EXPECT_EQ(xs->sphere, s);
	EXPECT_EQ(dest->sphere, s);
	EXPECT_EQ(dest->next->sphere, s);

	EXPECT_TRUE(equal(dest->pos, xs->t1));
	EXPECT_TRUE(equal(dest->next->pos, xs->t2));


	free(origin);
	free(direction);
	free(s);
	free(dest->next);
	free(dest);
	free(xs);
}


TEST(TesterRay, OrdenadedNumbers) {
	t_sphere *s = create_sphere();
	t_lst_inter *dest;

	dest = NULL;
	intersections(3, s, &dest);
	intersections(2, s, &dest);
	intersections(1, s, &dest);

	EXPECT_EQ(lst_count(dest), 3);
	EXPECT_TRUE(equal(dest->pos, 1));
	EXPECT_TRUE(equal(dest->next->pos, 2));
	EXPECT_TRUE(equal(dest->next->next->pos, 3));

	free(s);
	free(dest->next->next);
	free(dest->next);
	free(dest);
}