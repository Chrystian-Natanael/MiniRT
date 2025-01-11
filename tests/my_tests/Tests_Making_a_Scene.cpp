#include <gtest/gtest.h>
#include <cmath>

extern "C"
{
#include "Matrices.h"
#include "Shapes.h"
#include "Light_and_Shading.h"
#include "Intersections.h"
#include "Scenes.h"
#include "Canvas.h"
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
	t_colors light_color = create_color(1, 1, 1);
	t_pt_light light = pt_light(light_position, light_color);

	t_shape	*s1;

	init_shape(SPHERE, &s1);

	s1->material.color = create_color(0.8, 1.0, 0.6);
	s1->material.diffu = create_color(0.7, 0.7, 0.7);
	s1->material.spec = create_color(0.2, 0.2, 0.2);

	t_shape	*s2;

	init_shape(SPHERE, &s2);

	s2->transf = scale(0.5, 0.5, 0.5);

	t_world *w = default_world();

	EXPECT_TRUE(equal(w->lights_lst->light_src.pos[X], light.pos[X]));
	EXPECT_TRUE(equal(w->lights_lst->light_src.pos[Y], light.pos[Y]));
	EXPECT_TRUE(equal(w->lights_lst->light_src.pos[Z], light.pos[Z]));
	EXPECT_TRUE(equal(w->lights_lst->light_src.intens.blue, light.intens.blue));
	EXPECT_TRUE(equal(w->lights_lst->light_src.intens.green, light.intens.green));
	EXPECT_TRUE(equal(w->lights_lst->light_src.intens.red, light.intens.red));

	EXPECT_TRUE(equal(w->obj_lst->shape->material.color.red, s1->material.color.red));
	EXPECT_TRUE(equal(w->obj_lst->shape->material.color.green, s1->material.color.green));
	EXPECT_TRUE(equal(w->obj_lst->shape->material.color.blue, s1->material.color.blue));
	EXPECT_TRUE(equal(w->obj_lst->shape->material.diffu.red, s1->material.diffu.red));
	EXPECT_TRUE(equal(w->obj_lst->shape->material.diffu.green, s1->material.diffu.green));
	EXPECT_TRUE(equal(w->obj_lst->shape->material.diffu.blue, s1->material.diffu.blue));
	EXPECT_TRUE(equal(w->obj_lst->shape->material.spec.red, s1->material.spec.red));
	EXPECT_TRUE(equal(w->obj_lst->shape->material.spec.green, s1->material.spec.green));
	EXPECT_TRUE(equal(w->obj_lst->shape->material.spec.blue, s1->material.spec.blue));

	EXPECT_TRUE(comp_mtx(s2->transf, w->obj_lst->next->shape->transf));
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
	t_shape	*shape;

	init_shape(SPHERE, &shape);
	t_inter *i = NULL;
	intersections(4, shape, &i);
	t_comp *comps = prepare_computations(i, r);

	EXPECT_TRUE(equal(comps->pos, i->pos));
	EXPECT_EQ(comps->shape, i->shape);
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
	t_shape	*shape;

	init_shape(SPHERE, &shape);
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
	intersections(4, shape->shape, &i);
	t_comp *comps = prepare_computations(i, r);
	t_colors c = shade_hit(w, *comps);

	EXPECT_TRUE(equal(c.red, 0.38066));
	EXPECT_TRUE(equal(c.green, 0.47583));
	EXPECT_TRUE(equal(c.blue, 0.2855));
}

TEST_F(FixtureWorld, ShadingAnIntersectionFromTheInside)
{
	t_world *w = default_world();
	w->lights_lst->light_src = pt_light(point(0, 0.25, 0), create_color(1, 1, 1));
	t_ray r = create_ray(point(0, 0, 0), vector(0, 0, 1));
	t_obj *shape = w->obj_lst->next;
	t_inter *i = NULL;
	intersections(0.5, shape->shape, &i);
	t_comp *comps = prepare_computations(i, r);
	t_colors c = shade_hit(w, *comps);

	EXPECT_TRUE(equal(c.red, 0.90498));
	EXPECT_TRUE(equal(c.green, 0.90498));
	EXPECT_TRUE(equal(c.blue, 0.90498));
}

TEST_F(FixtureWorld, ColorWhenRayMisses)
{
	t_world *w = default_world();
	t_ray r = create_ray(point(0, 0, -5), vector(0, 1, 0));
	t_colors c = color_at(w, r);

	EXPECT_TRUE(equal(c.red, 0));
	EXPECT_TRUE(equal(c.green, 0));
	EXPECT_TRUE(equal(c.blue, 0));
}

TEST_F(FixtureWorld, ColorWhenRayHits)
{
	t_world *w = default_world();
	t_ray r = create_ray(point(0, 0, -5), vector(0, 0, 1));
	t_colors c = color_at(w, r);

	EXPECT_TRUE(equal(c.red, 0.38066));
	EXPECT_TRUE(equal(c.green, 0.47583));
	EXPECT_TRUE(equal(c.blue, 0.2855));
}

TEST_F(FixtureWorld, ColorWithIntersectionBehindRay)
{
	t_world *w = default_world();
	t_obj *outer = w->obj_lst;
	outer->shape->material.ambient = create_color(1, 1, 1);
	t_obj *inner = w->obj_lst->next;
	inner->shape->material.ambient = create_color(1, 1, 1);
	t_ray r = create_ray(point(0, 0, 0.75), vector(0, 0, -1));
	t_colors c = color_at(w, r);

	EXPECT_TRUE(equal(c.red, inner->shape->material.color.red));
	EXPECT_TRUE(equal(c.green, inner->shape->material.color.green));
	EXPECT_TRUE(equal(c.blue, inner->shape->material.color.blue));
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

TEST_F(FixtureWorld, ConstructingCamera)
{
	int hsize = 160;
	int vsize = 120;
	double field_view = M_PI / 2;
	t_camera c = camera(hsize, vsize, field_view);

	EXPECT_EQ(c.hsize, 160);
	EXPECT_EQ(c.vsize, 120);
	EXPECT_TRUE(equal(c.field_view, M_PI / 2));
	EXPECT_TRUE(comp_mtx(c.transform, id_mtx()));
}

TEST_F(FixtureWorld, pxizeForHorizontalCanvas)
{
	t_camera c = camera(200, 125, M_PI / 2);
	EXPECT_TRUE(equal(c.pixel_sz, 0.01));
}

TEST_F(FixtureWorld, pxizeForVerticalCanvas)
{
	t_camera c = camera(125, 200, M_PI / 2);
	EXPECT_DOUBLE_EQ(c.pixel_sz, 0.01);
}

TEST_F(FixtureWorld, ConstructingRayThroughCenterOfCanvas)
{
	t_camera c = camera(201, 101, M_PI / 2);
	t_ray r = ray_for_pixel(c, 100, 50);

	EXPECT_TRUE(equal(r.src[X], 0));
	EXPECT_TRUE(equal(r.src[Y], 0));
	EXPECT_TRUE(equal(r.src[Z], 0));
	EXPECT_TRUE(equal(r.dir[X], 0));
	EXPECT_TRUE(equal(r.dir[Y], 0));
	EXPECT_TRUE(equal(r.dir[Z], -1));
}

TEST_F(FixtureWorld, ConstructingRayThroughCornerOfCanvas)
{
	t_camera c = camera(201, 101, M_PI / 2);
	t_ray r = ray_for_pixel(c, 0, 0);

	EXPECT_TRUE(equal(r.src[X], 0));
	EXPECT_TRUE(equal(r.src[Y], 0));
	EXPECT_TRUE(equal(r.src[Z], 0));
	EXPECT_TRUE(equal(r.dir[X], 0.66519));
	EXPECT_TRUE(equal(r.dir[Y], 0.33259));
	EXPECT_TRUE(equal(r.dir[Z], -0.66851));
}

TEST_F(FixtureWorld, ConstructingRayWhenCameraIsTransformed)
{
	t_camera c = camera(201, 101, M_PI / 2);
	c.transform = multiply_mtx(rotate_y(M_PI / 4), translate(0, -2, 5));
	t_ray r = ray_for_pixel(c, 100, 50);

	EXPECT_TRUE(equal(r.src[X], 0));
	EXPECT_TRUE(equal(r.src[Y], 2));
	EXPECT_TRUE(equal(r.src[Z], -5));
	EXPECT_TRUE(equal(r.dir[X], sqrt(2) / 2));
	EXPECT_TRUE(equal(r.dir[Y], 0));
	EXPECT_TRUE(equal(r.dir[Z], -sqrt(2) / 2));
}

TEST_F(FixtureWorld, RenderingWorldWithCamera)
{
	t_world *w = default_world();
	t_camera c = camera(11, 11, M_PI / 2);
	double *from = point(0, 0, -5);
	double *to = point(0, 0, 0);
	double *up = vector(0, 1, 0);
	c.transform = view_transform(from, to, up);
	t_paint image = render_canva(c, w);

	t_colors expected_color = create_color(0.38066, 0.47583, 0.2855);

	EXPECT_TRUE(equal(image.px[5 * image.wid + 5].red, 0.38066));
	EXPECT_TRUE(equal(image.px[5 * image.wid + 5].green, 0.47583));
	EXPECT_TRUE(equal(image.px[5 * image.wid + 5].blue, 0.2855));
}

TEST_F(FixtureWorld, NoShadowWhenNothingIsCollinearWithPointAndLight)
{
	t_world *w = default_world();
	t_pt_pos	pt;
	pt.pos = point(0, 10, 0);

	pt.in_shadow = is_shadowed(w, pt.pos);

	EXPECT_FALSE(pt.in_shadow);
}

TEST_F(FixtureWorld, ShadowWhenObjectIsBetweenPointAndLight)
{
	t_world *w = default_world();
	t_pt_pos	pt;
	pt.pos = point(10, -10, 10);

	pt.in_shadow = is_shadowed(w, pt.pos);

	EXPECT_TRUE(pt.in_shadow);
}

TEST_F(FixtureWorld, NoShadowWhenObjectIsBehindLight)
{
	t_world *w = default_world();
	t_pt_pos	pt;
	pt.pos = point(-20, 20, -20);

	pt.in_shadow = is_shadowed(w, pt.pos);

	EXPECT_FALSE(pt.in_shadow);
}

TEST_F(FixtureWorld, NoShadowWhenObjectIsBehindPoint)
{
	t_world *w = default_world();
	t_pt_pos	pt;
	pt.pos = point(-2, 2, -2);

	pt.in_shadow = is_shadowed(w, pt.pos);

	EXPECT_FALSE(pt.in_shadow);
}

TEST_F(FixtureWorld, ShadeHitIsGivenAnIntersectionInShadow)
{
	t_world *w = world();

	w->lights_lst = (t_lights *)alloc_pool(sizeof(t_lights), set->colors);
	w->lights_lst->light_src = pt_light(point(0, 0, -10), create_color(1, 1, 1));

	create_obj_lst(w, SPHERE);
	w->obj_lst->shape->material.color = create_color(1, 1, 1);
	w->obj_lst->shape->material.spec = create_color(0, 0, 0);

	create_obj_lst(w, SPHERE);
	w->obj_lst->next->shape->material.color = create_color(1, 1, 1);
	w->obj_lst->next->shape->material.spec = create_color(0, 0, 0);
	set_transf(&w->obj_lst->next->shape, (translate(0, 0, 10)));

	t_ray	ray = create_ray(point(0, 0, 5), vector(0, 0, 1));

	t_colors	color_at_hit = color_at(w, ray);

	EXPECT_DOUBLE_EQ(color_at_hit.red, 0.1);
	EXPECT_DOUBLE_EQ(color_at_hit.green, 0.1);
	EXPECT_DOUBLE_EQ(color_at_hit.blue, 0.1);
}
