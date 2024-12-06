#include <cmath>
#include <gtest/gtest.h>

extern "C"
{
#include "Intersections.h"
#include "Matrices.h"
#include "Tuples.h"
#include "Utils.h"
}

TEST(TesterRay, CreateAndQueryRay)
{
	double *src = point(1, 2, 3);
	double *dir = vector(4, 5, 6);
	t_ray r = create_ray(src, dir);

	ASSERT_NE(r.src, nullptr);
	ASSERT_NE(r.dir, nullptr);

	EXPECT_TRUE(equal(r.src[0], src[0]));
	EXPECT_TRUE(equal(r.src[1], src[1]));
	EXPECT_TRUE(equal(r.src[2], src[2]));
	EXPECT_TRUE(equal(r.src[3], src[3]));

	EXPECT_TRUE(equal(r.dir[0], dir[0]));
	EXPECT_TRUE(equal(r.dir[1], dir[1]));
	EXPECT_TRUE(equal(r.dir[2], dir[2]));
	EXPECT_TRUE(equal(r.dir[3], dir[3]));

	free(src);
	free(dir);
}

TEST(TesterRay, ComputePointFromDistance)
{
	double *src = point(2, 3, 4);
	double *dir = vector(1, 0, 0);
	t_ray r = create_ray(src, dir);

	double *pos0 = pos_ray(r, 0);
	double *pos1 = pos_ray(r, 1);
	double *posNeg1 = pos_ray(r, -1);
	double *pos2_5 = pos_ray(r, 2.5);

	EXPECT_TRUE(equal(pos0[0], 2) && equal(pos0[1], 3) && equal(pos0[2], 4) && equal(pos0[3], 1));
	EXPECT_TRUE(equal(pos1[0], 3) && equal(pos1[1], 3) && equal(pos1[2], 4) && equal(pos1[3], 1));
	EXPECT_TRUE(equal(posNeg1[0], 1) && equal(posNeg1[1], 3) && equal(posNeg1[2], 4) && equal(posNeg1[3], 1));
	EXPECT_TRUE(equal(pos2_5[0], 4.5) && equal(pos2_5[1], 3) && equal(pos2_5[2], 4) && equal(pos2_5[3], 1));

	free(src);
	free(dir);
	free(pos0);
	free(pos1);
	free(posNeg1);
	free(pos2_5);
}

TEST(TesterRay, RayIntersectsSphereAtTwoPoints)
{
	double *src = point(0, 0, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_sp *s = create_sp();

	t_sp_inter *lst = intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, 4.0));
	EXPECT_TRUE(equal(lst->t2, 6.0));
	EXPECT_TRUE(equal(lst->count, 2));

	free(src);
	free(dir);
	free(s);
	free(lst);
}

TEST(TesterRay, RayIntersectsSphereAtTangent)
{
	double *src = point(0, 1, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_sp *s = create_sp();

	t_sp_inter *lst = intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, 5.0));
	EXPECT_TRUE(equal(lst->t2, 5.0));
	EXPECT_TRUE(equal(lst->count, 2));

	free(src);
	free(dir);
	free(s);
	free(lst);
}

TEST(TesterRay, RayMissesSphere)
{
	double *src = point(0, 2, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_sp *s = create_sp();

	t_sp_inter *lst = intersect(s, r);

	EXPECT_EQ(lst->count, 0);

	free(src);
	free(dir);
	free(s);
	free(lst);
}

TEST(TesterRay, RaysrcatesInsideSphere)
{
	double *src = point(0, 0, 0);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_sp *s = create_sp();

	t_sp_inter *lst = intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, -1.0));
	EXPECT_TRUE(equal(lst->t2, 1.0));
	EXPECT_EQ(lst->count, 2);

	free(src);
	free(dir);
	free(s);
	free(lst);
}

TEST(TesterRay, SphereIsBehindRay)
{
	double *src = point(0, 0, 5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_sp *s = create_sp();

	t_sp_inter *lst = intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, -6.0));
	EXPECT_TRUE(equal(lst->t2, -4.0));
	EXPECT_EQ(lst->count, 2);

	free(src);
	free(dir);
	free(s);
	free(lst);
}

TEST(TesterRay, IntersectionEncapsulatesTAndObject)
{
	t_sp *s = create_sp();
	t_inter *dest;

	dest = NULL;
	intersections(3.5, s, &dest);

	EXPECT_TRUE(equal(dest->pos, 3.5));
	EXPECT_EQ(dest->sp->src, s->src);
	EXPECT_EQ(dest->sp->radius, s->radius);

	free(s);
	free(dest);
}

TEST(TesterRay, AggregatingIntersections)
{
	t_sp *s = create_sp();
	t_inter *dest;

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

TEST(TesterRay, IntersectSetsObjectOnIntersection)
{
	double *src = point(0, 0, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_sp *s = create_sp();
	t_inter *dest;

	dest = NULL;
	t_sp_inter *xs = intersect(s, r);
	intersections(xs->t1, s, &dest);
	intersections(xs->t2, s, &dest);

	EXPECT_EQ(xs->count, 2);
	EXPECT_EQ(lst_count(dest), 2);
	EXPECT_EQ(xs->sp, s);
	EXPECT_EQ(dest->sp, s);
	EXPECT_EQ(dest->next->sp, s);

	EXPECT_TRUE(equal(dest->pos, xs->t1));
	EXPECT_TRUE(equal(dest->next->pos, xs->t2));

	free(src);
	free(dir);
	free(s);
	free(dest->next);
	free(dest);
	free(xs);
}

TEST(TesterRay, OrdenadedNumbers)
{
	t_sp *s = create_sp();
	t_inter *dest;

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

TEST(TesterRay, HitWhenAllIntersectionsHavePositiveT)
{
	t_sp *s = create_sp();
	t_inter *dest;

	dest = NULL;
	intersections(1, s, &dest);
	intersections(2, s, &dest);

	t_inter *i = hit(dest);

	EXPECT_EQ(i->pos, 1);

	free(s);
	free(dest->next);
	free(dest);
}

TEST(TesterRay, HitWhenSomeIntersectionsHaveNegativeT)
{
	t_sp *s = create_sp();
	t_inter *dest;

	dest = NULL;
	intersections(-1, s, &dest);
	intersections(1, s, &dest);

	t_inter *i = hit(dest);

	EXPECT_EQ(i->pos, 1);

	free(s);
	free(dest->next);
	free(dest);
}

TEST(TesterRay, HitWhenAllIntersectionsHaveNegativeT)
{
	t_sp *s = create_sp();
	t_inter *dest;

	dest = NULL;
	intersections(-1, s, &dest);
	intersections(-2, s, &dest);

	t_inter *i = hit(dest);

	EXPECT_EQ(i, nullptr);

	free(s);
	free(dest->next);
	free(dest);
}

TEST(TesterRay, HitIsAlwaysLowestNonnegativeIntersection)
{
	t_sp *s = create_sp();
	t_inter *dest;

	dest = NULL;
	intersections(5, s, &dest);
	intersections(7, s, &dest);
	intersections(-3, s, &dest);
	intersections(2, s, &dest);

	t_inter *i = hit(dest);

	EXPECT_EQ(i->pos, 2);
	EXPECT_EQ(i->next->pos, 5);
	EXPECT_EQ(i->next->next->pos, 7);

	free(s);
	free(dest->next->next->next);
	free(dest->next->next);
	free(dest->next);
	free(dest);
}

TEST(TesterRay, TranslatingARay)
{
	double *src = point(1, 2, 3);
	double *dir = vector(0, 1, 0);
	t_ray r = create_ray(src, dir);
	t_matrix m = translate(3, 4, 5);

	t_ray r2 = transform(r, m);

	double *expected_src = point(4, 6, 8);
	double *expected_dir = vector(0, 1, 0);

	EXPECT_TRUE(equal(r2.src[X], expected_src[X]));
	EXPECT_TRUE(equal(r2.src[Y], expected_src[Y]));
	EXPECT_TRUE(equal(r2.src[Z], expected_src[Z]));
	EXPECT_TRUE(equal(r2.dir[X], expected_dir[X]));
	EXPECT_TRUE(equal(r2.dir[Y], expected_dir[Y]));
	EXPECT_TRUE(equal(r2.dir[Z], expected_dir[Z]));

	free(src);
	free(dir);
	free(expected_src);
	free(expected_dir);
}

TEST(TesterRay, ScalingARay)
{
	double *src = point(1, 2, 3);
	double *dir = vector(0, 1, 0);
	t_ray r = create_ray(src, dir);
	t_matrix m = scale(2, 3, 4);

	t_ray r2 = transform(r, m);

	double *expected_src = point(2, 6, 12);
	double *expected_dir = vector(0, 3, 0);

	EXPECT_EQ(r2.src[X], expected_src[X]);
	EXPECT_EQ(r2.src[Y], expected_src[Y]);
	EXPECT_EQ(r2.src[Z], expected_src[Z]);
	EXPECT_EQ(r2.dir[X], expected_dir[X]);
	EXPECT_EQ(r2.dir[Y], expected_dir[Y]);
	EXPECT_EQ(r2.dir[Z], expected_dir[Z]);

	free(src);
	free(dir);
	free(expected_src);
	free(expected_dir);
}

TEST(TesterSphere, DefaultTransformation)
{
	t_sp *s = create_sp();
	t_matrix identity = id_mtx();

	EXPECT_TRUE(comp_mtx(s->transf, identity));

	free(s);
}

TEST(TesterSphere, ChangingTransformation)
{
	t_sp *s = create_sp();
	t_matrix t = translate(2, 3, 4);

	set_transf(s, t);

	EXPECT_TRUE(comp_mtx(s->transf, t));

	free(s);
}

TEST(TesterSphere, IntersectingScaledSphereWithRay)
{
	double *src = point(0, 0, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_sp *s = create_sp();
	t_matrix scaling = scale(2, 2, 2);

	set_transf(s, scaling);

	t_sp_inter *xs = intersect(s, r);

	EXPECT_EQ(xs->count, 2);
	EXPECT_EQ(xs->t1, 3);
	EXPECT_EQ(xs->t2, 7);

	free(src);
	free(dir);
	free(s);
	free(xs);
}

TEST(TesterSphere, IntersectingTranslatedSphereWithRay)
{
	double *src = point(0, 0, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_sp *s = create_sp();
	t_matrix translation = translate(5, 0, 0);

	set_transf(s, translation);
	t_sp_inter *xs = intersect(s, r);

	EXPECT_EQ(xs->count, 0);

	free(src);
	free(dir);
	free(s);
	free(xs);
}
