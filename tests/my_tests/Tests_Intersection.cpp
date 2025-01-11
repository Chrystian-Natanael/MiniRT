#include <cmath>
#include <gtest/gtest.h>

extern "C"
{
#include "Intersections.h"
#include "Matrices.h"
#include "Tuples.h"
#include "Utils.h"
#include "Scenes.h"
#include "Objects.h"
}

class FixtureInter : public ::testing::Test {
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

TEST_F(FixtureInter, TstRay_CreateAndQueryRay)
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

}

TEST_F(FixtureInter, TstRay_ComputePointFromDistance)
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

}

TEST_F(FixtureInter, TstRay_RayIntersectsSphereAtTwoPoints)
{
	double *src = point(0, 0, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_shape *s;

	init_shape(SPHERE, &s);

	t_sp_inter *lst = (t_sp_inter *)intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, 4.0));
	EXPECT_TRUE(equal(lst->t2, 6.0));
	EXPECT_TRUE(equal(lst->count, 2));

}

TEST_F(FixtureInter, TstRay_RayIntersectsSphereAtTangent)
{
	double *src = point(0, 1, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_shape *s;

	init_shape(SPHERE, &s);

	t_sp_inter *lst = (t_sp_inter *)intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, 5.0));
	EXPECT_TRUE(equal(lst->t2, 5.0));
	EXPECT_TRUE(equal(lst->count, 2));

}

TEST_F(FixtureInter, TstRay_RayMissesSphere)
{
	double *src = point(0, 2, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_shape *s;

	init_shape(SPHERE, &s);

	t_sp_inter *lst = (t_sp_inter *)intersect(s, r);

	EXPECT_EQ(lst->count, 0);

}

TEST_F(FixtureInter, TstRay_RaysrcatesInsideSphere)
{
	double *src = point(0, 0, 0);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_shape *s;

	init_shape(SPHERE, &s);

	t_sp_inter *lst = (t_sp_inter *)intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, -1.0));
	EXPECT_TRUE(equal(lst->t2, 1.0));
	EXPECT_EQ(lst->count, 2);

}

TEST_F(FixtureInter, TstRay_SphereIsBehindRay)
{
	double *src = point(0, 0, 5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_shape	*s;

	init_shape(SPHERE, &s);

	t_sp_inter *lst = (t_sp_inter *)intersect(s, r);

	EXPECT_TRUE(equal(lst->t1, -6.0));
	EXPECT_TRUE(equal(lst->t2, -4.0));
	EXPECT_EQ(lst->count, 2);

}

TEST_F(FixtureInter, TstRay_IntersectionEncapsulatesTAndObject)
{
	t_shape *s;
	t_inter *dest;

	init_shape(SPHERE, &s);

	dest = NULL;
	intersections(3.5, s, &dest);

	EXPECT_TRUE(equal(dest->pos, 3.5));

	EXPECT_EQ(((t_sp *)dest->shape->obj)->src, ((t_sp *)s->obj)->src);
	EXPECT_EQ(((t_sp *)dest->shape->obj)->radius, ((t_sp *)s->obj)->radius);

}

TEST_F(FixtureInter, TstRay_AggregatingIntersections)
{
	t_inter *dest;
	t_shape	*s;

	init_shape(SPHERE, &s);

	dest = NULL;
	intersections(1, s, &dest);
	intersections(2, s, &dest);

	EXPECT_EQ(lst_count(dest), 2);
	EXPECT_TRUE(equal(dest->pos, 1));
	EXPECT_TRUE(equal(dest->next->pos, 2));

}

TEST_F(FixtureInter, TstRay_IntersectSetsObjectOnIntersection)
{
	double *src = point(0, 0, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_inter *dest;
	t_shape	*s;

	init_shape(SPHERE, &s);

	dest = NULL;
	t_sp_inter *xs = (t_sp_inter *)intersect(s, r);
	intersections(xs->t1, s, &dest);
	intersections(xs->t2, s, &dest);

	EXPECT_EQ(xs->count, 2);
	EXPECT_EQ(lst_count(dest), 2);
	EXPECT_EQ(xs->sp->radius, ((t_sp *)s->obj)->radius);
	EXPECT_EQ(xs->sp->src, ((t_sp *)s->obj)->src);
	EXPECT_EQ(dest->shape, s);
	EXPECT_EQ(dest->next->shape, s);

	EXPECT_TRUE(equal(dest->pos, xs->t1));
	EXPECT_TRUE(equal(dest->next->pos, xs->t2));

}

TEST_F(FixtureInter, TstRay_OrdenadedNumbers)
{
	t_shape	*s;

	init_shape(SPHERE, &s);
	t_inter *dest;

	dest = NULL;
	intersections(3, s, &dest);
	intersections(2, s, &dest);
	intersections(1, s, &dest);

	EXPECT_EQ(lst_count(dest), 3);
	EXPECT_TRUE(equal(dest->pos, 1));
	EXPECT_TRUE(equal(dest->next->pos, 2));
	EXPECT_TRUE(equal(dest->next->next->pos, 3));

}

TEST_F(FixtureInter, TstRay_HitWhenAllIntersectionsHavePositiveT)
{
	t_shape	*s;

	init_shape(SPHERE, &s);
	t_inter *dest;

	dest = NULL;
	intersections(1, s, &dest);
	intersections(2, s, &dest);

	t_inter *i = hit(dest);

	EXPECT_EQ(i->pos, 1);

}

TEST_F(FixtureInter, TstRay_HitWhenSomeIntersectionsHaveNegativeT)
{
	t_shape	*s;

	init_shape(SPHERE, &s);
	t_inter *dest;

	dest = NULL;
	intersections(-1, s, &dest);
	intersections(1, s, &dest);

	t_inter *i = hit(dest);

	EXPECT_EQ(i->pos, 1);

}

TEST_F(FixtureInter, TstRay_HitWhenAllIntersectionsHaveNegativeT)
{
	t_shape	*s;

	init_shape(SPHERE, &s);
	t_inter *dest;

	dest = NULL;
	intersections(-1, s, &dest);
	intersections(-2, s, &dest);

	t_inter *i = hit(dest);

	EXPECT_EQ(i, nullptr);

}

TEST_F(FixtureInter, TstRay_HitIsAlwaysLowestNonnegativeIntersection)
{
	t_shape	*s;

	init_shape(SPHERE, &s);
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

}

TEST_F(FixtureInter, TstRay_TranslatingARay)
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

}

TEST_F(FixtureInter, TstRay_ScalingARay)
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

}

TEST_F(FixtureInter, TstSp_DefaultTransformation)
{
	t_shape	*s;

	init_shape(SPHERE, &s);
	t_matrix identity = id_mtx();

	EXPECT_TRUE(comp_mtx(s->transf, identity));

}

TEST_F(FixtureInter, TstSp_ChangingTransformation)
{
	t_shape	*s;

	init_shape(SPHERE, &s);
	t_matrix t = translate(2, 3, 4);

	set_transf(&s, t);

	EXPECT_TRUE(comp_mtx(s->transf, t));

}

TEST_F(FixtureInter, TstSp_IntersectingScaledSphereWithRay)
{
	double *src = point(0, 0, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_shape	*s;

	init_shape(SPHERE, &s);
	t_matrix scaling = scale(2, 2, 2);

	set_transf(&s, scaling);

	t_sp_inter *xs = (t_sp_inter *)intersect(s, r);

	EXPECT_EQ(xs->count, 2);
	EXPECT_EQ(xs->t1, 3);
	EXPECT_EQ(xs->t2, 7);

}

TEST_F(FixtureInter, TstSp_IntersectingTranslatedSphereWithRay)
{
	double *src = point(0, 0, -5);
	double *dir = vector(0, 0, 1);
	t_ray r = create_ray(src, dir);
	t_shape	*s;

	init_shape(SPHERE, &s);
	t_matrix translation = translate(5, 0, 0);

	set_transf(&s, translation);
	t_sp_inter *xs = (t_sp_inter *)intersect(s, r);

	EXPECT_EQ(xs->count, 0);

}

TEST_F(FixtureInter, HitShouldOffsetThePoint)
{
	t_ray r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_shape	*s;

	s = NULL;
	init_shape(SPHERE, &s);
	t_matrix translation = translate(0, 0, 1);

	set_transf(&s, translation);
	t_sp_inter *val = (t_sp_inter *)intersect(s, r);
	t_inter	*lst = NULL;
	intersections(val->t1, s, &lst);
	intersections(val->t2, s, &lst);
	t_comp	*comps = prepare_computations(lst, r);

	EXPECT_LT(comps->over_point[Z], (-(0.00001)/2));
	EXPECT_GT(comps->point[Z], comps->over_point[Z]);
}
