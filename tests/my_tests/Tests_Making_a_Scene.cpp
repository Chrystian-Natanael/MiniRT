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


class FixtureWorld : public ::testing::Test {
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

TEST_F(FixtureWorld, CreatingWorld)
{
	t_world *w = world();

	EXPECT_EQ(w->obj_lst, nullptr);
	EXPECT_EQ(w->lights_lst, nullptr);
}

TEST_F(FixtureWorld, DefaultWorld) {
	double *light_position = point(-10, 10, -10);
	t_colors *light_color = create_color(1, 1, 1);
	t_pt_light light = pt_light(light_position, light_color);

	t_sp *s1 = create_sp();
	s1->material.color = create_color(0.8, 1.0, 0.6);
	s1->material.diffuse = create_color(0.7, 0.7, 0.7);
	s1->material.specular = create_color(0.2, 0.2, 0.2);

	t_sp *s2 = create_sp();
	s2->transf = scale(0.5, 0.5, 0.5);

	t_world *w = default_world();

	EXPECT_TRUE(equal(w->lights_lst->light_src.pos[X], light.pos[X]));
	EXPECT_TRUE(equal(w->lights_lst->light_src.pos[Y], light.pos[Y]));
	EXPECT_TRUE(equal(w->lights_lst->light_src.pos[Z], light.pos[Z]));
	EXPECT_TRUE(equal(w->lights_lst->light_src.intensity->blue, light.intensity->blue));
	EXPECT_TRUE(equal(w->lights_lst->light_src.intensity->green, light.intensity->green));
	EXPECT_TRUE(equal(w->lights_lst->light_src.intensity->red, light.intensity->red));

	EXPECT_TRUE(equal(w->obj_lst->sp->material.color->red, s1->material.color->red));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.color->green, s1->material.color->green));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.color->blue, s1->material.color->blue));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.diffuse->red, s1->material.diffuse->red));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.diffuse->green, s1->material.diffuse->green));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.diffuse->blue, s1->material.diffuse->blue));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.specular->red, s1->material.specular->red));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.specular->green, s1->material.specular->green));
	EXPECT_TRUE(equal(w->obj_lst->sp->material.specular->blue, s1->material.specular->blue));

	EXPECT_TRUE(comp_mtx(s2->transf, w->obj_lst->next->sp->transf));
}


TEST_F(FixtureWorld, IntersectWorldWithRay) {
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

TEST_F(FixtureWorld, PrecomputingStateOfIntersection) {
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
	
	EXPECT_TRUE(equal(comps->eyev[X],0));
	EXPECT_TRUE(equal(comps->eyev[Y], 0));
	EXPECT_TRUE(equal(comps->eyev[Z], -1));

	EXPECT_TRUE(equal(comps->normalv[X], 0));
	EXPECT_TRUE(equal(comps->normalv[Y], 0));
	EXPECT_TRUE(equal(comps->normalv[Z], -1));

	EXPECT_FALSE(comps->inside);
}

TEST_F(FixtureWorld, HitWhenIntersectionOccursOnInside) {
	t_ray r = create_ray(point(0, 0, 0), vector(0, 0, 1));
	t_sp *shape = create_sp();
	t_inter *i = NULL;
	intersections(1, shape, &i);
	t_comp *comps = prepare_computations(i, r);

	EXPECT_TRUE(equal(comps->point[X], 0));
	EXPECT_TRUE(equal(comps->point[Y], 0));
	EXPECT_TRUE(equal(comps->point[Z], 1));
	
	EXPECT_TRUE(equal(comps->eyev[X],0));
	EXPECT_TRUE(equal(comps->eyev[Y], 0));
	EXPECT_TRUE(equal(comps->eyev[Z], -1));

	EXPECT_TRUE(equal(comps->normalv[X], 0));
	EXPECT_TRUE(equal(comps->normalv[Y], 0));
	EXPECT_TRUE(equal(comps->normalv[Z], -1));

	EXPECT_TRUE(comps->inside);
}