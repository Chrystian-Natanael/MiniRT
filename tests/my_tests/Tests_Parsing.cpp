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

	void SetUp() override
	{
		set = get_pool();
		set->the_pool = create_pool(500000);
	}

	void TearDown() override
	{
		deallocate(set->the_pool);
	}
};

TEST_F(FixtureTest, ParseSphere) {
	t_world *wld = world();
	wld->scene.has_ambient = 0;
	wld->scene.has_camera = 0;
	wld->scene.has_light = 0;
	wld->scene.save_img = false;

	char line[] = "sp 0.0,0.0,20.6 12.6 10,0,255";
	bool result = parse_sphere(line, wld);

	ASSERT_TRUE(result);
	ASSERT_NE(wld->obj_lst, nullptr);

	t_obj *sphere = wld->obj_lst;
	ASSERT_NE(sphere, nullptr);

	double expected_pos[3] = {0.0, 0.0, 20.6};
	double expected_scale = 12.6 / 2;
	double expected_color[3] = {10.0 / 255.0, 0.0, 255.0 / 255.0};

	t_matrix expected_transformation = rotate_mtx(expected_pos, point(0, 1, 0), &sphere);

	for (int i = 0; i < 16; ++i) {
		EXPECT_TRUE(equal(sphere->shape->transf.content[i], expected_transformation.content[i]));
	}

	EXPECT_TRUE(equal(sphere->shape->material.color.red, expected_color[0]));
	EXPECT_TRUE(equal(sphere->shape->material.color.green, expected_color[1]));
	EXPECT_TRUE(equal(sphere->shape->material.color.blue, expected_color[2]));
}
