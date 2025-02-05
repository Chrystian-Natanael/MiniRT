#include <gtest/gtest.h>
#include <cmath>

extern "C" {
	#include "Matrices.h"
	#include "Utils.h"
	#include "Light_and_Shading.h"
	#include "Tuples.h"
	#include "Intersections.h"
	#include "Objects.h"
	#include "Parser.h"
	#include <stdbool.h>
}

class FixtureTest : public ::testing::Test {
protected:
	t_pool_set *set;

	void SetUp() override {
		init_pools();
		set = get_pool();
	}

	void TearDown() override {
		deallocate(set->mem);
		deallocate(set);
	}
};

TEST_F(FixtureTest, ParseSphere) {
	t_world *wld = world();
	set_scene(wld);

	char line[] = "sp 0.0,0.0,20.6 12.6 10,0,255";
	bool result = parse_sphere(line, wld);

	ASSERT_TRUE(result);
	ASSERT_NE(wld->obj_lst, nullptr);

	t_obj *sphere = wld->obj_lst;
	ASSERT_NE(sphere, nullptr);

	double expected_pos[3] = {0.0, 0.0, 20.6};
	double expected_scale = 12.6 / 2;
	double expected_color[3] = {10.0 / 255.0, 0.0, 255.0 / 255.0};

	t_matrix expected_transformation = multiply_mtx(
		scale(expected_scale, expected_scale, expected_scale),
		translate(expected_pos[0], expected_pos[1], expected_pos[2])
	);

	for (int i = 0; i < 16; ++i) {
		EXPECT_TRUE(equal(sphere->shape->transf.content[i], expected_transformation.content[i]));
	}

	EXPECT_TRUE(equal(sphere->shape->material.color.red, expected_color[0]));
	EXPECT_TRUE(equal(sphere->shape->material.color.green, expected_color[1]));
	EXPECT_TRUE(equal(sphere->shape->material.color.blue, expected_color[2]));
}
