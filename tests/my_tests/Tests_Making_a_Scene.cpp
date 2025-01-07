#include <gtest/gtest.h>
#include <cmath>

extern "C"
{
#include "Matrices.h"
#include "Sphere.h"
#include "Light_and_Shading.h"
#include "Intersections.h"
#include "Scenes.h"
}

class FixtureWorld : public ::testing::Test
{
protected:
	t_pool_set *set;

	void SetUp() override
	{
		init_pools();
		set = get_pools();
	}

	void TearDown() override
	{
		deallocate(set->colors->mem);
		deallocate(set->colors);
		deallocate(set->matrices->mem);
		deallocate(set->matrices);
		deallocate(set->objects->mem);
		deallocate(set->objects);
		deallocate(set);
	}
};

TEST_F(FixtureWorld, CreatingWorld)
{
	t_world *w = world();

	EXPECT_EQ(w->obj_lst, nullptr);
	EXPECT_EQ(w->lights_lst, nullptr);
}

TEST_F(FixtureWorld, DefaultWorld)
{
	double *light_position = point(-10, 10, -10);
	t_colors *light_color = create_color(1, 1, 1);
	t_pt_light light = pt_light(light_position, light_color);

	t_sp *s1 = create_sp();
	s1->material.color = create_color(0.8, 1.0, 0.6);
	s1->material.diffu = create_color(0.7, 0.7, 0.7);
	s1->material.spec = create_color(0.2, 0.2, 0.2);

	t_sp *s2 = create_sp();
	s2->transf = scale(0.5, 0.5, 0.5);

	t_world *w = default_world();

	EXPECT_TRUE(equal(w->lights_lst->light_src.pos[X], light.pos[X]));
	EXPECT_TRUE(equal(w->lights_lst->light_src.pos[Y], light.pos[Y]));
	EXPECT_TRUE(equal(w->lights_lst->light_src.pos[Z], light.pos[Z]));
	EXPECT_TRUE(equal(w->lights_lst->light_src.intens->blue, light.intens->blue));
	EXPECT_TRUE(equal(w->lights_lst->light_src.intens->green, light.intens->green));
	EXPECT_TRUE(equal(w->lights_lst->light_src.intens->red, light.intens->red));

	EXPECT_TRUE(equal(w->obj_lst->sp->material.color->red, s1->material.color->red));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.color->green, s1->material.color->green));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.color->blue, s1->material.color->blue));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.diffu->red, s1->material.diffu->red));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.diffu->green, s1->material.diffu->green));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.diffu->blue, s1->material.diffu->blue));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.spec->red, s1->material.spec->red));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.spec->green, s1->material.spec->green));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.spec->blue, s1->material.spec->blue));

	EXPECT_TRUE(comp_mtx(s2->transf, w->obj_lst->next->sp->transf));
}

TEST_F(FixtureWorld, IntersectWorldWithRay)
{
	t_world *w = default_world();
	t_ray r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_inter *xs = intersect_world(w, r);

	ASSERT_EQ(lst_count(xs), 4);
	EXPECT_TRUE(equal(xs->pos, 4));
	EXPECT_TRUE(equal(xs->next->pos, 4.5));
	EXPECT_TRUE(equal(xs->next->next->pos, 5.5));
	EXPECT_TRUE(equal(xs->next->next->next->pos, 6));
}
// ------------------

TEST_F(FixtureWorld, PrecomputingStateOfIntersection)
{
	t_ray r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_sp *shape = create_sp();
	t_inter *i = NULL;
	intersections(4, shape, &i);
	t_comp *comps = prepare_computations(i, r);

	EXPECT_TRUE(equal(comps->pos, i->pos));
	EXPECT_EQ(comps->sp, i->sp);
	EXPECT_TRUE(equal(comps->point[X], 0));
	EXPECT_TRUE(equal(comps->point[Y], 0));
	EXPECT_TRUE(equal(comps->point[Z], -1));

	EXPECT_TRUE(equal(comps->sig.eye[X], 0));
	EXPECT_TRUE(equal(comps->sig.eye[Y], 0));
	EXPECT_TRUE(equal(comps->sig.eye[Z], -1));

	EXPECT_TRUE(equal(comps->sig.normal[X], 0));
	EXPECT_TRUE(equal(comps->sig.normal[Y], 0));
	EXPECT_TRUE(equal(comps->sig.normal[Z], -1));

	EXPECT_FALSE(comps->inside);
}

TEST_F(FixtureWorld, HitWhenIntersectionOccursOnInside)
{
	t_ray r = create_ray(point(0, 0, 0), vector(0, 0, 1));
	t_sp *shape = create_sp();
	t_inter *i = NULL;
	intersections(1, shape, &i);
	t_comp *comps = prepare_computations(i, r);

	EXPECT_TRUE(equal(comps->point[X], 0));
	EXPECT_TRUE(equal(comps->point[Y], 0));
	EXPECT_TRUE(equal(comps->point[Z], 1));

	EXPECT_TRUE(equal(comps->sig.eye[X], 0));
	EXPECT_TRUE(equal(comps->sig.eye[Y], 0));
	EXPECT_TRUE(equal(comps->sig.eye[Z], -1));

	EXPECT_TRUE(equal(comps->sig.normal[X], 0));
	EXPECT_TRUE(equal(comps->sig.normal[Y], 0));
	EXPECT_TRUE(equal(comps->sig.normal[Z], -1));

	EXPECT_TRUE(comps->inside);
}

TEST_F(FixtureWorld, ShadingAnIntersection)
{
	t_world *w = default_world();
	t_ray r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_obj *shape = w->obj_lst;
	t_inter *i = NULL;
	intersections(4, shape->sp, &i);
	t_comp *comps = prepare_computations(i, r);
	t_colors *c = shade_hit(w, *comps);

	EXPECT_TRUE(equal(c->red, 0.38066));
	EXPECT_TRUE(equal(c->green, 0.47583));
	EXPECT_TRUE(equal(c->blue, 0.2855));
}

TEST_F(FixtureWorld, ShadingAnIntersectionFromTheInside)
{
	t_world *w = default_world();
	w->lights_lst->light_src = pt_light(point(0, 0.25, 0), create_color(1, 1, 1));
	t_ray r = create_ray(point(0, 0, 0), vector(0, 0, 1));
	t_obj *shape = w->obj_lst->next;
	t_inter *i = NULL;
	intersections(0.5, shape->sp, &i);
	t_comp *comps = prepare_computations(i, r);
	t_colors *c = shade_hit(w, *comps);

	EXPECT_TRUE(equal(c->red, 0.90498));
	EXPECT_TRUE(equal(c->green, 0.90498));
	EXPECT_TRUE(equal(c->blue, 0.90498));
}

TEST_F(FixtureWorld, ColorWhenRayMisses)
{
	t_world *w = default_world();
	t_ray r = create_ray(point(0, 0, -5), vector(0, 1, 0));
	t_colors *c = color_at(w, r);

	EXPECT_TRUE(equal(c->red, 0));
	EXPECT_TRUE(equal(c->green, 0));
	EXPECT_TRUE(equal(c->blue, 0));
}

TEST_F(FixtureWorld, ColorWhenRayHits)
{
	t_world *w = default_world();
	t_ray r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_colors *c = color_at(w, r);

	EXPECT_TRUE(equal(c->red, 0.38066));
	EXPECT_TRUE(equal(c->green, 0.47583));
	EXPECT_TRUE(equal(c->blue, 0.2855));
}

TEST_F(FixtureWorld, ColorWithIntersectionBehindRay)
{
	t_world *w = default_world();
	t_obj *outer = w->obj_lst;
	outer->sp->material.ambient = create_color(1, 1, 1);
	t_obj *inner = w->obj_lst->next;
	inner->sp->material.ambient = create_color(1, 1, 1);
	t_ray r = create_ray(point(0, 0, 0.75), vector(0, 0, -1));
	t_colors *c = color_at(w, r);

	EXPECT_TRUE(equal(c->red, inner->sp->material.color->red));
	EXPECT_TRUE(equal(c->green, inner->sp->material.color->green));
	EXPECT_TRUE(equal(c->blue, inner->sp->material.color->blue));
}

// --------------

TEST_F(FixtureWorld, DefaultOrientationTransformationMatrix)
{
	double *from = point(0, 0, 0);
	double *to = point(0, 0, -1);
	double *up = vector(0, 1, 0);
	t_matrix t = view_transform(from, to, up);
	t_matrix identity = id_mtx();

	EXPECT_TRUE(comp_mtx(t, identity));
}

TEST_F(FixtureWorld, ViewTransformationLookingPositiveZ)
{
	double *from = point(0, 0, 0);
	double *to = point(0, 0, 1);
	double *up = vector(0, 1, 0);
	t_matrix t = view_transform(from, to, up);
	t_matrix expected = scale(-1, 1, -1);

	EXPECT_TRUE(comp_mtx(t, expected));
}

TEST_F(FixtureWorld, ViewTransformationMovesWorld)
{
	double *from = point(0, 0, 8);
	double *to = point(0, 0, 0);
	double *up = vector(0, 1, 0);
	t_matrix t = view_transform(from, to, up);
	t_matrix expected = translate(0, 0, -8);

	EXPECT_TRUE(comp_mtx(t, expected));
}

TEST_F(FixtureWorld, ArbitraryViewTransformation)
{
	double *from = point(1, 3, 2);
	double *to = point(4, -2, 8);
	double *up = vector(1, 1, 0);
	t_matrix t = view_transform(from, to, up);
	double elements[16] = {
		-0.50709, 0.50709, 0.67612, -2.36643,
		0.76772, 0.60609, 0.12122, -2.82843,
		-0.35857, 0.59761, -0.71714, 0.00000,
		0.00000, 0.00000, 0.00000, 1.00000};
	t_matrix expected = create_mtx(4, 4, elements);

	EXPECT_TRUE(comp_mtx(t, expected));
}
