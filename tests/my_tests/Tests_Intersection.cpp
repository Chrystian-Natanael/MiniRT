#include <gtest/gtest.h>
#include <cmath>

extern "C" {
	#include "Utils.h"
	#include "Intersections.h"
	#include "Tuples.h"
	#include "Matrices.h"
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

TEST(TesterRay, HitWhenAllIntersectionsHavePositiveT) {
	t_sphere *s = create_sphere();
	t_lst_inter *dest;

	dest = NULL;
	intersections(1, s, &dest);
	intersections(2, s, &dest);

	t_lst_inter *i = hit(dest);

	EXPECT_EQ(i->pos, 1);

	free(s);
	free(dest->next);
	free(dest);
}

TEST(TesterRay, HitWhenSomeIntersectionsHaveNegativeT) {
	t_sphere *s = create_sphere();
	t_lst_inter *dest;

	dest = NULL;
	intersections(-1, s, &dest);
	intersections(1, s, &dest);

	t_lst_inter *i = hit(dest);

	EXPECT_EQ(i->pos, 1);

	free(s);
	free(dest->next);
	free(dest);
}

TEST(TesterRay, HitWhenAllIntersectionsHaveNegativeT) {
	t_sphere *s = create_sphere();
	t_lst_inter *dest;

	dest = NULL;
	intersections(-1, s, &dest);
	intersections(-2, s, &dest);

	t_lst_inter *i = hit(dest);

	EXPECT_EQ(i, nullptr);

	free(s);
	free(dest->next);
	free(dest);
}

TEST(TesterRay, HitIsAlwaysLowestNonnegativeIntersection) {
	t_sphere *s = create_sphere();
	t_lst_inter *dest;

	dest = NULL;
	intersections(5, s, &dest);
	intersections(7, s, &dest);
	intersections(-3, s, &dest);
	intersections(2, s, &dest);

	t_lst_inter *i = hit(dest);

	EXPECT_EQ(i->pos, 2);
	EXPECT_EQ(i->next->pos, 5);
	EXPECT_EQ(i->next->next->pos, 7);

	free(s);
	free(dest->next->next->next);
	free(dest->next->next);
	free(dest->next);
	free(dest);
}

TEST(TesterRay, TranslatingARay) {
	double *origin = point(1, 2, 3);
	double *direction = vector(0, 1, 0);
	t_ray r = create_ray(origin, direction);
	t_matrix m = translate(3, 4, 5);

	t_ray r2 = transform(r, m);

	double *expected_origin = point(4, 6, 8);
	double *expected_direction = vector(0, 1, 0);

	EXPECT_TRUE(equal(r2.origin[X], expected_origin[X]));
	EXPECT_TRUE(equal(r2.origin[Y], expected_origin[Y]));
	EXPECT_TRUE(equal(r2.origin[Z], expected_origin[Z]));
	EXPECT_TRUE(equal(r2.direction[X], expected_direction[X]));
	EXPECT_TRUE(equal(r2.direction[Y], expected_direction[Y]));
	EXPECT_TRUE(equal(r2.direction[Z], expected_direction[Z]));

	free(origin);
	free(direction);
	free(expected_origin);
	free(expected_direction);
}

TEST(TesterRay, ScalingARay) {
	double *origin = point(1, 2, 3);
	double *direction = vector(0, 1, 0);
	t_ray r = create_ray(origin, direction);
	t_matrix m = scale(2, 3, 4);

	t_ray r2 = transform(r, m);

	double *expected_origin = point(2, 6, 12);
	double *expected_direction = vector(0, 3, 0);

	EXPECT_EQ(r2.origin[X], expected_origin[X]);
	EXPECT_EQ(r2.origin[Y], expected_origin[Y]);
	EXPECT_EQ(r2.origin[Z], expected_origin[Z]);
	EXPECT_EQ(r2.direction[X], expected_direction[X]);
	EXPECT_EQ(r2.direction[Y], expected_direction[Y]);
	EXPECT_EQ(r2.direction[Z], expected_direction[Z]);

	free(origin);
	free(direction);
	free(expected_origin);
	free(expected_direction);
}

TEST(TesterSphere, DefaultTransformation) {
	t_sphere *s = create_sphere();
	t_matrix identity = id_mtx();

	EXPECT_TRUE(comp_mtx(s->transform, identity));

	free(s);
}

TEST(TesterSphere, ChangingTransformation) {
	t_sphere *s = create_sphere();
	t_matrix t = translate(2, 3, 4);

	set_transform(s, t);

	EXPECT_TRUE(comp_mtx(s->transform, t));

	free(s);
}

TEST(TesterSphere, IntersectingScaledSphereWithRay) {
	double *origin = point(0, 0, -5);
	double *direction = vector(0, 0, 1);
	t_ray r = create_ray(origin, direction);
	t_sphere *s = create_sphere();
	t_matrix scaling = scale(2, 2, 2);

	set_transform(s, scaling);

	t_intersect *xs = intersect(s, r);

	EXPECT_EQ(xs->count, 2);
	EXPECT_EQ(xs->t1, 3);
	EXPECT_EQ(xs->t2, 7);

	free(origin);
	free(direction);
	free(s);
	free(xs);
}

TEST(TesterSphere, IntersectingTranslatedSphereWithRay) {
	double *origin = point(0, 0, -5);
	double *direction = vector(0, 0, 1);
	t_ray r = create_ray(origin, direction);
	t_sphere *s = create_sphere();
	t_matrix translation = translate(5, 0, 0);

	set_transform(s, translation);
	t_intersect *xs = intersect(s, r);

	EXPECT_EQ(xs->count, 0);

	free(origin);
	free(direction);
	free(s);
	free(xs);
}
