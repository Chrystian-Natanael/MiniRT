#include <gtest/gtest.h>
#include <cmath>

extern "C"
{
#include "Light_and_Shading.h"
#include "Shapes.h"
#include "Matrices.h"
}

class FixtureLight : public ::testing::Test
{
protected:
	t_pool_set *set;

	void SetUp() override
	{
		init_pools();
		set = get_pool();
	}

	void TearDown() override
	{
		deallocate(set->mem);
		deallocate(set);
	}
};

TEST_F(FixtureLight, TstNormalAt_NormalOnSphereAtPointOnXAxis)
{
	t_shape	*s;

	init_shape(SPHERE, &s);

	double *n = normal_at(s, point(1, 0, 0));
	double *expected = vector(1, 0, 0);

	EXPECT_DOUBLE_EQ(n[0], expected[0]);
	EXPECT_DOUBLE_EQ(n[1], expected[1]);
	EXPECT_DOUBLE_EQ(n[2], expected[2]);
}

TEST_F(FixtureLight, TstNormalAt_NormalOnSphereAtPointOnYAxis)
{
	t_shape	*s;

	init_shape(SPHERE, &s);

	double *n = normal_at(s, point(0, 1, 0));
	double *expected = vector(0, 1, 0);

	EXPECT_DOUBLE_EQ(n[0], expected[0]);
	EXPECT_DOUBLE_EQ(n[1], expected[1]);
	EXPECT_DOUBLE_EQ(n[2], expected[2]);
}

TEST_F(FixtureLight, TstNormalAt_NormalOnSphereAtPointOnZAxis)
{
	t_shape	*s;

	init_shape(SPHERE, &s);

	double *n = normal_at(s, point(0, 0, 1));
	double *expected = vector(0, 0, 1);

	EXPECT_DOUBLE_EQ(n[0], expected[0]);
	EXPECT_DOUBLE_EQ(n[1], expected[1]);
	EXPECT_DOUBLE_EQ(n[2], expected[2]);
}

TEST_F(FixtureLight, TstNormalAt_NormalOnSphereAtNonaxialPoint)
{
	t_shape	*s;

	init_shape(SPHERE, &s);

	double sqrt3_over_3 = sqrt(3) / 3;
	double *n = normal_at(s, point(sqrt3_over_3, sqrt3_over_3, sqrt3_over_3));
	double *expected = vector(sqrt3_over_3, sqrt3_over_3, sqrt3_over_3);

	EXPECT_DOUBLE_EQ(n[0], expected[0]);
	EXPECT_DOUBLE_EQ(n[1], expected[1]);
	EXPECT_DOUBLE_EQ(n[2], expected[2]);
}

TEST_F(FixtureLight, TstNormalAt_NormalIsNormalizedVector)
{
	t_shape	*s;

	init_shape(SPHERE, &s);

	double sqrt3_over_3 = sqrt(3) / 3;
	double *n = normal_at(s, point(sqrt3_over_3, sqrt3_over_3, sqrt3_over_3));
	double *normalized_n = norm(n);

	EXPECT_TRUE(equal(n[0], normalized_n[0]));
	EXPECT_TRUE(equal(n[1], normalized_n[1]));
	EXPECT_TRUE(equal(n[2], normalized_n[2]));
}

TEST_F(FixtureLight, TstNormalAt_NormalOnTranslatedSphere)
{
	t_shape	*s;

	init_shape(SPHERE, &s);

	set_transf(&s, translate(0, 1, 0));
	double *n = normal_at(s, point(0, 1.70711, -0.70711));
	double *expected = vector(0, 0.70711, -0.70711);

	EXPECT_TRUE(equal(n[0], expected[0]));
	EXPECT_TRUE(equal(n[1], expected[1]));
	EXPECT_TRUE(equal(n[2], expected[2]));
}

TEST_F(FixtureLight, TstNormalAt_NormalOnTransformedSphere)
{
	t_shape	*s;

	init_shape(SPHERE, &s);

	t_matrix m = multiply_mtx(scale(1, 0.5, 1), rotate_z(M_PI / 5));
	set_transf(&s, m);
	double *n = normal_at(s, point(0, sqrt(2) / 2, -sqrt(2) / 2));
	double *expected = vector(0, 0.97014, -0.24254);

	EXPECT_TRUE(equal(n[0], expected[0]));
	EXPECT_TRUE(equal(n[1], expected[1]));
	EXPECT_TRUE(equal(n[2], expected[2]));
}

TEST_F(FixtureLight, TstRefl_ReflectVectorApproachingAt45Degrees)
{
	double *v = vector(1, -1, 0);
	double *n = vector(0, 1, 0);
	double *r = reflect(v, n);
	double *expected = vector(1, 1, 0);

	EXPECT_TRUE(equal(r[0], expected[0]));
	EXPECT_TRUE(equal(r[1], expected[1]));
	EXPECT_TRUE(equal(r[2], expected[2]));
}

TEST_F(FixtureLight, TstRefl_ReflectVectorOffSlantedSurface)
{
	double *v = vector(0, -1, 0);
	double sqrt2_over_2 = sqrt(2) / 2;
	double *n = vector(sqrt2_over_2, sqrt2_over_2, 0);
	double *r = reflect(v, n);
	double *expected = vector(1, 0, 0);

	EXPECT_TRUE(equal(r[0], expected[0]));
	EXPECT_TRUE(equal(r[1], expected[1]));
	EXPECT_TRUE(equal(r[2], expected[2]));
}

TEST_F(FixtureLight, TstPtLight_PointLightHasPositionAndintens)
{
	t_colors intens = create_color(1, 1, 1);
	double *position = point(0, 0, 0);
	t_pt_light light = pt_light(position, intens);

	EXPECT_TRUE(equal(light.pos[0], position[0]));
	EXPECT_TRUE(equal(light.pos[1], position[1]));
	EXPECT_TRUE(equal(light.pos[2], position[2]));

	EXPECT_TRUE(equal(light.intens.red, intens.red));
	EXPECT_TRUE(equal(light.intens.green, intens.green));
	EXPECT_TRUE(equal(light.intens.blue, intens.blue));
}

TEST_F(FixtureLight, TstMat_DefaultMaterial)
{
	t_material m = material();

	EXPECT_TRUE(equal(m.color.red, 1));
	EXPECT_TRUE(equal(m.color.green, 1));
	EXPECT_TRUE(equal(m.color.blue, 1));

	EXPECT_TRUE(equal(m.ambient.red, 0.1));
	EXPECT_TRUE(equal(m.ambient.green, 0.1));
	EXPECT_TRUE(equal(m.ambient.blue, 0.1));
	EXPECT_TRUE(equal(m.diffu.red, 0.9));
	EXPECT_TRUE(equal(m.diffu.green, 0.9));
	EXPECT_TRUE(equal(m.diffu.blue, 0.9));
	EXPECT_TRUE(equal(m.spec.red, 0.9));
	EXPECT_TRUE(equal(m.spec.green, 0.9));
	EXPECT_TRUE(equal(m.spec.blue, 0.9));
	EXPECT_TRUE(equal(m.shininess, 200.0));
}

TEST_F(FixtureLight, TstMat_SphereHasDefaultMaterial)
{
	t_shape	*s;

	init_shape(SPHERE, &s);

	t_material m = s->material;

	t_material default_material = material();

	EXPECT_TRUE(equal(m.color.red, default_material.color.red));
	EXPECT_TRUE(equal(m.color.green, default_material.color.green));
	EXPECT_TRUE(equal(m.color.blue, default_material.color.blue));

	EXPECT_TRUE(equal(s->material.ambient.red, default_material.ambient.red));
	EXPECT_TRUE(equal(s->material.ambient.green, default_material.ambient.green));
	EXPECT_TRUE(equal(s->material.ambient.blue, default_material.ambient.blue));
	EXPECT_TRUE(equal(m.diffu.red, default_material.diffu.red));
	EXPECT_TRUE(equal(m.diffu.green, default_material.diffu.green));
	EXPECT_TRUE(equal(m.diffu.blue, default_material.diffu.blue));
	EXPECT_TRUE(equal(m.spec.red, default_material.spec.red));
	EXPECT_TRUE(equal(m.spec.green, default_material.spec.green));
	EXPECT_TRUE(equal(m.spec.blue, default_material.spec.blue));
	EXPECT_TRUE(equal(m.shininess, default_material.shininess));
}

TEST_F(FixtureLight, TstMat_SphereAssignedMaterial)
{
	t_shape	*s;

	init_shape(SPHERE, &s);

	t_material m = material();
	m.ambient = create_color(1, 1, 1);

	s->material = m;

	EXPECT_TRUE(equal(s->material.ambient.red, m.ambient.red));
	EXPECT_TRUE(equal(s->material.ambient.green, m.ambient.green));
	EXPECT_TRUE(equal(s->material.ambient.blue, m.ambient.blue));
	EXPECT_TRUE(equal(s->material.diffu.red, m.diffu.red));
	EXPECT_TRUE(equal(s->material.diffu.green, m.diffu.green));
	EXPECT_TRUE(equal(s->material.diffu.blue, m.diffu.blue));
	EXPECT_TRUE(equal(s->material.spec.red, m.spec.red));
	EXPECT_TRUE(equal(s->material.spec.green, m.spec.green));
	EXPECT_TRUE(equal(s->material.spec.blue, m.spec.blue));
	EXPECT_TRUE(equal(s->material.shininess, m.shininess));

	EXPECT_TRUE(equal(s->material.color.red, m.color.red));
	EXPECT_TRUE(equal(s->material.color.green, m.color.green));
	EXPECT_TRUE(equal(s->material.color.blue, m.color.blue));
}

TEST_F(FixtureLight, TstLighting_EyeBetweenLightAndSurface)
{
	t_shape	*s;
	init_shape(SPHERE, &s);
	t_pt_pos	pt;
	pt.pos = point(0, 0, 0);
	pt.in_shadow = false;
	double *eyev = vector(0, 0, -1);
	double *normalv = vector(0, 0, -1);
	t_pt_light light = pt_light(point(0, 0, -10), create_color(1, 1, 1));
	t_sight sight = {eyev, normalv};

	t_colors result = lighting(s, light, pt, sight);

	EXPECT_TRUE(equal(result.red, 1.9));
	EXPECT_TRUE(equal(result.green, 1.9));
	EXPECT_TRUE(equal(result.blue, 1.9));
}

TEST_F(FixtureLight, TstLighting_EyeBetweenLightAndSurfaceOffset45)
{
	t_shape	*s;
	init_shape(SPHERE, &s);
	t_pt_pos	pt;
	pt.pos = point(0, 0, 0);
	pt.in_shadow = false;
	double *eyev = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	double *normalv = vector(0, 0, -1);
	t_pt_light light = pt_light(point(0, 0, -10), create_color(1, 1, 1));
	t_sight sight = {eyev, normalv};

	t_colors result = lighting(s, light, pt, sight);

	EXPECT_TRUE(equal(result.red, 1.0));
	EXPECT_TRUE(equal(result.green, 1.0));
	EXPECT_TRUE(equal(result.blue, 1.0));
}

TEST_F(FixtureLight, TstLighting_EyeOppositeSurfaceLightOffset45)
{
	t_shape	*s;
	init_shape(SPHERE, &s);
	t_pt_pos	pt;
	pt.pos = point(0, 0, 0);
	pt.in_shadow = false;
	double *eyev = vector(0, 0, -1);
	double *normalv = vector(0, 0, -1);
	t_pt_light light = pt_light(point(0, 10, -10), create_color(1, 1, 1));
	t_sight sight = {eyev, normalv};

	t_colors result = lighting(s, light, pt, sight);

	EXPECT_TRUE(equal(result.red, 0.7364));
	EXPECT_TRUE(equal(result.green, 0.7364));
	EXPECT_TRUE(equal(result.blue, 0.7364));
}

TEST_F(FixtureLight, TstLighting_EyeInPathOfReflectionVector)
{
	t_shape	*s;
	init_shape(SPHERE, &s);
	t_pt_pos	pt;
	pt.pos = point(0, 0, 0);
	pt.in_shadow = false;
	double *eyev = vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	double *normalv = vector(0, 0, -1);
	t_pt_light light = pt_light(point(0, 10, -10), create_color(1, 1, 1));
	t_sight sight = {eyev, normalv};

	t_colors result = lighting(s, light, pt, sight);

	EXPECT_TRUE(equal(result.red, 1.6364));
	EXPECT_TRUE(equal(result.green, 1.6364));
	EXPECT_TRUE(equal(result.blue, 1.6364));
}

TEST_F(FixtureLight, TstLighting_LightBehindSurface)
{
	t_shape	*s;
	init_shape(SPHERE, &s);
	t_pt_pos	pt;
	pt.pos = point(0, 0, 0);
	pt.in_shadow = false;
	double *eyev = vector(0, 0, -1);
	double *normalv = vector(0, 0, -1);
	t_pt_light light = pt_light(point(0, 0, 10), create_color(1, 1, 1));
	t_sight sight = {eyev, normalv};

	t_colors result = lighting(s, light, pt, sight);

	EXPECT_TRUE(equal(result.red, 0.1));
	EXPECT_TRUE(equal(result.green, 0.1));
	EXPECT_TRUE(equal(result.blue, 0.1));
}

TEST_F(FixtureLight, TstLighting_SurfaceInShadow)
{
	t_shape	*s;
	init_shape(SPHERE, &s);
	t_pt_pos	pt;
	pt.pos = point(0, 0, 0);
	pt.in_shadow = true;
	double *eyev = vector(0, 0, -1);
	double *normalv = vector(0, 0, -1);
	t_pt_light light = pt_light(point(0, 0, -10), create_color(1, 1, 1));
	t_sight sight = {eyev, normalv};

	t_colors result = lighting(s, light, pt, sight);

	EXPECT_TRUE(equal(result.red, 0.1));
	EXPECT_TRUE(equal(result.green, 0.1));
	EXPECT_TRUE(equal(result.blue, 0.1));
}
