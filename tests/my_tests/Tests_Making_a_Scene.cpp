#include <gtest/gtest.h>
#include <cmath>

extern "C"
{
#include "Matrices.h"
#include "Sphere.h"
#include "Light_and_Shading.h"
#include "Scenes.h"
}

TEST(TesterWorldFeature, CreatingWorld)
{
	t_world *w = world();

	EXPECT_EQ(w->obj_lst, nullptr);
	EXPECT_EQ(w->lights_lst, nullptr);
}

TEST(TesterWorldFeature, DefaultWorld)
{
	t_world *w = world();

	create_obj_lst(w);
	create_obj_lst(w);
	EXPECT_EQ(w->obj_lst->sp->radius, 1);
	EXPECT_EQ(w->obj_lst->sp->src, point(0, 0, 0));
}
