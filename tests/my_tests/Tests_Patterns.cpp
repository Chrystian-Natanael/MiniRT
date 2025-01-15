#include <gtest/gtest.h>
#include <cmath>

extern "C" {
	#include "Colors.h"
	#include "Patterns.h"
	// #include "Matrices.h"
	// #include "Utils.h"
	#include "Light_and_Shading.h"
	#include "Tuples.h"
	// #include "Intersections.h"
	#include "Objects.h"
	// #include <stdbool.h>
}

class FixturePatterns : public ::testing::Test
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

TEST_F(FixturePatterns, CreatingStripePattern) {
	t_colors	black = create_color(0, 0, 0);
	t_colors	white = create_color(1, 1, 1);
	t_pattern	pattern = stripe_pattern(white, black);

	EXPECT_DOUBLE_EQ(pattern.c1.red, 1);
	EXPECT_DOUBLE_EQ(pattern.c1.green, 1);
	EXPECT_DOUBLE_EQ(pattern.c1.blue, 1);
	EXPECT_DOUBLE_EQ(pattern.c2.red, 0);
	EXPECT_DOUBLE_EQ(pattern.c2.green, 0);
	EXPECT_DOUBLE_EQ(pattern.c2.blue, 0);
}

TEST_F(FixturePatterns, StripePatternIsConstantInY) {
	t_colors	black = create_color(0, 0, 0);
	t_colors	white = create_color(1, 1, 1);
	t_pattern	pattern = stripe_pattern(white, black);
	t_colors	res1 = stripe_at(pattern, point(0, 0, 0));
	t_colors	res2 = stripe_at(pattern, point(0, 1, 0));
	t_colors	res3 = stripe_at(pattern, point(0, 2, 0));

	EXPECT_DOUBLE_EQ(res1.red, 1);
	EXPECT_DOUBLE_EQ(res1.green, 1);
	EXPECT_DOUBLE_EQ(res1.blue, 1);
	EXPECT_DOUBLE_EQ(res2.red, 1);
	EXPECT_DOUBLE_EQ(res2.green, 1);
	EXPECT_DOUBLE_EQ(res2.blue, 1);
	EXPECT_DOUBLE_EQ(res3.red, 1);
	EXPECT_DOUBLE_EQ(res3.green, 1);
	EXPECT_DOUBLE_EQ(res3.blue, 1);
}

TEST_F(FixturePatterns, StripePatternIsConstantInZ) {
	t_colors	black = create_color(0, 0, 0);
	t_colors	white = create_color(1, 1, 1);
	t_pattern	pattern = stripe_pattern(white, black);
	t_colors	res1 = stripe_at(pattern, point(0, 0, 0));
	t_colors	res2 = stripe_at(pattern, point(0, 0, 1));
	t_colors	res3 = stripe_at(pattern, point(0, 0, 2));

	EXPECT_DOUBLE_EQ(res1.red, 1);
	EXPECT_DOUBLE_EQ(res1.green, 1);
	EXPECT_DOUBLE_EQ(res1.blue, 1);
	EXPECT_DOUBLE_EQ(res2.red, 1);
	EXPECT_DOUBLE_EQ(res2.green, 1);
	EXPECT_DOUBLE_EQ(res2.blue, 1);
	EXPECT_DOUBLE_EQ(res3.red, 1);
	EXPECT_DOUBLE_EQ(res3.green, 1);
	EXPECT_DOUBLE_EQ(res3.blue, 1);
}

TEST_F(FixturePatterns, StripePatternAlternatesInX) {
	t_colors	black = create_color(0, 0, 0);
	t_colors	white = create_color(1, 1, 1);
	t_pattern	pattern = stripe_pattern(white, black);
	t_colors	res1 = stripe_at(pattern, point(0, 0, 0));
	t_colors	res2 = stripe_at(pattern, point(0.9, 0, 0));
	t_colors	res3 = stripe_at(pattern, point(1, 0, 0));
	t_colors	res4 = stripe_at(pattern, point(-0.1, 0, 0));
	t_colors	res5 = stripe_at(pattern, point(-1, 0, 0));
	t_colors	res6 = stripe_at(pattern, point(-1.1, 0, 0));

	EXPECT_DOUBLE_EQ(res1.red, 1);
	EXPECT_DOUBLE_EQ(res1.green, 1);
	EXPECT_DOUBLE_EQ(res1.blue, 1);
	EXPECT_DOUBLE_EQ(res2.red, 1);
	EXPECT_DOUBLE_EQ(res2.green, 1);
	EXPECT_DOUBLE_EQ(res2.blue, 1);
	EXPECT_DOUBLE_EQ(res3.red, 0);
	EXPECT_DOUBLE_EQ(res3.green, 0);
	EXPECT_DOUBLE_EQ(res3.blue, 0);
	EXPECT_DOUBLE_EQ(res4.red, 0);
	EXPECT_DOUBLE_EQ(res4.green, 0);
	EXPECT_DOUBLE_EQ(res4.blue, 0);
	EXPECT_DOUBLE_EQ(res5.red, 0);
	EXPECT_DOUBLE_EQ(res5.green, 0);
	EXPECT_DOUBLE_EQ(res5.blue, 0);
	EXPECT_DOUBLE_EQ(res6.red, 1);
	EXPECT_DOUBLE_EQ(res6.green, 1);
	EXPECT_DOUBLE_EQ(res6.blue, 1);
}

TEST_F(FixturePatterns, LightingWithPatternApplied) {
	t_colors	black = create_color(0, 0, 0);
	t_colors	white = create_color(1, 1, 1);

	t_material	m;
	m.pattern = stripe_pattern(white, black);
	m.pattern.flag = true;
	m.ambient = create_color(1, 1, 1);
	m.diffu = create_color (0, 0, 0);
	m.spec = create_color (0, 0, 0);

	t_sight	sight;
	sight.eye = vector(0, 0, -1);
	sight.normal = vector(0, 0, -1);

	t_pt_light	light = pt_light(point(0, 0, -10), create_color(1, 1, 1));
	t_pt_pos	pt1;

	pt1.in_shadow = false;
	pt1.pos = point(0.9, 0, 0);

	t_colors	c1 = lighting(m, light, pt1, sight);

	t_pt_pos	pt2;

	pt2.in_shadow = false;
	pt2.pos = point(1.1, 0, 0);

	t_colors	c2 = lighting(m, light, pt2, sight);

	EXPECT_DOUBLE_EQ(c1.red, 1);
	EXPECT_DOUBLE_EQ(c1.green, 1);
	EXPECT_DOUBLE_EQ(c1.blue, 1);
	EXPECT_DOUBLE_EQ(c2.red, 0);
	EXPECT_DOUBLE_EQ(c2.green, 0);
	EXPECT_DOUBLE_EQ(c2.blue, 0);
}

// TEST_F(FixturePatterns, StripesWithAnObjectTransformation) {
// 	t_colors	black = create_color(0, 0, 0);
// 	t_colors	white = create_color(1, 1, 1);

// 	t_shape	*s;
// 	init_shape(SPHERE, &s);
// 	set_transf(&s, scale(2, 2, 2));

// 	s->material.pattern = stripe_pattern(white, black);
// 	set_transf_pattern(&s, scale(2, 2, 2));

// 	t_colors	c = stripe_at_object(s->material.pattern, s, point(1.5, 0, 0));
// 	EXPECT_DOUBLE_EQ(c.red, 1);
// 	EXPECT_DOUBLE_EQ(c.green, 1);
// 	EXPECT_DOUBLE_EQ(c.blue, 1);
// }

// TEST_F(FixturePatterns, StripesWithPatternTransformation) {
// 	t_colors	black = create_color(0, 0, 0);
// 	t_colors	white = create_color(1, 1, 1);

// 	t_shape	*s;
// 	init_shape(SPHERE, &s);
// 	set_transf(&s, scale(2, 2, 2));

// 	s->material.pattern = stripe_pattern(white, black);
// 	set_transf_pattern(&s, scale(2, 2, 2));

// 	t_colors	c = stripe_at_object(s->material.pattern, s, point(1.5, 0, 0));
// 	EXPECT_DOUBLE_EQ(c.red, 1);
// 	EXPECT_DOUBLE_EQ(c.green, 1);
// 	EXPECT_DOUBLE_EQ(c.blue, 1);
// }
