#include <gtest/gtest.h>
#include <cmath>

extern "C"
{
#include "Matrices.h"
#include "Sphere.h"
#include "Light_and_Shading.h"
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

TEST_F(FixtureWorld, DefaultWorld)
{
	t_world *w = world();
	double *pt = point(0, 0, 0);

	create_obj_lst(w);
	create_obj_lst(w);
	EXPECT_EQ(w->obj_lst->sp->radius, 1);
	EXPECT_EQ(w->obj_lst->sp->src[X], pt[X]);
	EXPECT_EQ(w->obj_lst->sp->src[Y], pt[Y]);
	EXPECT_EQ(w->obj_lst->sp->src[Z], pt[Z]);
}
