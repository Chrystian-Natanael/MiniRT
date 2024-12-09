#include <gtest/gtest.h>
#include <cmath>

extern "C"
{
#include "Light_and_Shading.h"
#include "Sphere.h"
#include "Matrices.h"
}

TEST(TesterNormalAt, NormalOnSphereAtPointOnXAxis)
{
	t_sp *s = create_sp();
	double *n = normal_at(s, point(1, 0, 0));
	double *expected = vector(1, 0, 0);

	EXPECT_DOUBLE_EQ(n[0], expected[0]);
	EXPECT_DOUBLE_EQ(n[1], expected[1]);
	EXPECT_DOUBLE_EQ(n[2], expected[2]);
}

TEST(TesterNormalAt, NormalOnSphereAtPointOnYAxis)
{
	t_sp *s = create_sp();
	double *n = normal_at(s, point(0, 1, 0));
	double *expected = vector(0, 1, 0);

	EXPECT_DOUBLE_EQ(n[0], expected[0]);
	EXPECT_DOUBLE_EQ(n[1], expected[1]);
	EXPECT_DOUBLE_EQ(n[2], expected[2]);
}

TEST(TesterNormalAt, NormalOnSphereAtPointOnZAxis)
{
	t_sp *s = create_sp();
	double *n = normal_at(s, point(0, 0, 1));
	double *expected = vector(0, 0, 1);

	EXPECT_DOUBLE_EQ(n[0], expected[0]);
	EXPECT_DOUBLE_EQ(n[1], expected[1]);
	EXPECT_DOUBLE_EQ(n[2], expected[2]);
}

TEST(TesterNormalAt, NormalOnSphereAtNonaxialPoint)
{
	t_sp *s = create_sp();
	double sqrt3_over_3 = sqrt(3) / 3;
	double *n = normal_at(s, point(sqrt3_over_3, sqrt3_over_3, sqrt3_over_3));
	double *expected = vector(sqrt3_over_3, sqrt3_over_3, sqrt3_over_3);

	EXPECT_DOUBLE_EQ(n[0], expected[0]);
	EXPECT_DOUBLE_EQ(n[1], expected[1]);
	EXPECT_DOUBLE_EQ(n[2], expected[2]);
}

TEST(TesterNormalAt, NormalIsNormalizedVector)
{
	t_sp *s = create_sp();
	double sqrt3_over_3 = sqrt(3) / 3;
	double *n = normal_at(s, point(sqrt3_over_3, sqrt3_over_3, sqrt3_over_3));
	double *normalized_n = norm(n);

	EXPECT_TRUE(equal(n[0], normalized_n[0]));
	EXPECT_TRUE(equal(n[1], normalized_n[1]));
	EXPECT_TRUE(equal(n[2], normalized_n[2]));
}

TEST(TesterNormalAt, NormalOnTranslatedSphere)
{
	t_sp *s = create_sp();
	set_transf(s, translate(0, 1, 0));
	double *n = normal_at(s, point(0, 1.70711, -0.70711));
	double *expected = vector(0, 0.70711, -0.70711);

	EXPECT_TRUE(equal(n[0], expected[0]));
	EXPECT_TRUE(equal(n[1], expected[1]));
	EXPECT_TRUE(equal(n[2], expected[2]));
}

TEST(TesterNormalAt, NormalOnTransformedSphere)
{
	t_sp *s = create_sp();
	t_matrix m = multiply_mtx(scale(1, 0.5, 1), rotate_z(M_PI / 5));
	set_transf(s, m);
	double *n = normal_at(s, point(0, sqrt(2) / 2, -sqrt(2) / 2));
	double *expected = vector(0, 0.97014, -0.24254);

	EXPECT_TRUE(equal(n[0], expected[0]));
	EXPECT_TRUE(equal(n[1], expected[1]));
	EXPECT_TRUE(equal(n[2], expected[2]));
}

TEST(TesterReflect, ReflectVectorApproachingAt45Degrees)
{
	double *v = vector(1, -1, 0);
	double *n = vector(0, 1, 0);
	double *r = reflect(v, n);
	double *expected = vector(1, 1, 0);

	EXPECT_TRUE(equal(r[0], expected[0]));
	EXPECT_TRUE(equal(r[1], expected[1]));
	EXPECT_TRUE(equal(r[2], expected[2]));
}

TEST(TesterReflect, ReflectVectorOffSlantedSurface)
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

TEST(TesterPointLight, PointLightHasPositionAndIntensity)
{
	t_colors *intensity = create_color(1, 1, 1);
	double *position = point(0, 0, 0);
	t_pt_light light = pt_light(position, intensity);

	EXPECT_TRUE(equal(light.pos[0], position[0]));
	EXPECT_TRUE(equal(light.pos[1], position[1]));
	EXPECT_TRUE(equal(light.pos[2], position[2]));

	EXPECT_TRUE(equal(light.intensity->red, intensity->red));
	EXPECT_TRUE(equal(light.intensity->green, intensity->green));
	EXPECT_TRUE(equal(light.intensity->blue, intensity->blue));
}

TEST(TesterMaterial, DefaultMaterial)
{
	t_material m = material();

	EXPECT_TRUE(equal(m.color->red, 1));
	EXPECT_TRUE(equal(m.color->green, 1));
	EXPECT_TRUE(equal(m.color->blue, 1));

	EXPECT_TRUE(equal(m.ambient->red, 0.1));
	EXPECT_TRUE(equal(m.ambient->green, 0.1));
	EXPECT_TRUE(equal(m.ambient->blue, 0.1));
	EXPECT_TRUE(equal(m.diffuse->red, 0.9));
	EXPECT_TRUE(equal(m.diffuse->green, 0.9));
	EXPECT_TRUE(equal(m.diffuse->blue, 0.9));
	EXPECT_TRUE(equal(m.specular->red, 0.9));
	EXPECT_TRUE(equal(m.specular->green, 0.9));
	EXPECT_TRUE(equal(m.specular->blue, 0.9));
	EXPECT_TRUE(equal(m.shininess, 200.0));
}

TEST(TesterMaterial, SphereHasDefaultMaterial)
{
	t_sp *s = create_sp();
	t_material m = s->material;

	t_material default_material = material();

	EXPECT_TRUE(equal(m.color->red, default_material.color->red));
	EXPECT_TRUE(equal(m.color->green, default_material.color->green));
	EXPECT_TRUE(equal(m.color->blue, default_material.color->blue));

	EXPECT_TRUE(equal(s->material.ambient->red, default_material.ambient->red));
	EXPECT_TRUE(equal(s->material.ambient->green, default_material.ambient->green));
	EXPECT_TRUE(equal(s->material.ambient->blue, default_material.ambient->blue));
	EXPECT_TRUE(equal(m.diffuse->red, default_material.diffuse->red));
	EXPECT_TRUE(equal(m.diffuse->green, default_material.diffuse->green));
	EXPECT_TRUE(equal(m.diffuse->blue, default_material.diffuse->blue));
	EXPECT_TRUE(equal(m.specular->red, default_material.specular->red));
	EXPECT_TRUE(equal(m.specular->green, default_material.specular->green));
	EXPECT_TRUE(equal(m.specular->blue, default_material.specular->blue));
	EXPECT_TRUE(equal(m.shininess, default_material.shininess));
}

TEST(TesterMaterial, SphereAssignedMaterial)
{
	t_sp *s = create_sp();
	t_material m = material();
	m.ambient = create_color(1, 1, 1);

	s->material = m;

	EXPECT_TRUE(equal(s->material.ambient->red, m.ambient->red));
	EXPECT_TRUE(equal(s->material.ambient->green, m.ambient->green));
	EXPECT_TRUE(equal(s->material.ambient->blue, m.ambient->blue));
	EXPECT_TRUE(equal(s->material.diffuse->red, m.diffuse->red));
	EXPECT_TRUE(equal(s->material.diffuse->green, m.diffuse->green));
	EXPECT_TRUE(equal(s->material.diffuse->blue, m.diffuse->blue));
	EXPECT_TRUE(equal(s->material.specular->red, m.specular->red));
	EXPECT_TRUE(equal(s->material.specular->green, m.specular->green));
	EXPECT_TRUE(equal(s->material.specular->blue, m.specular->blue));
	EXPECT_TRUE(equal(s->material.shininess, m.shininess));

	EXPECT_TRUE(equal(s->material.color->red, m.color->red));
	EXPECT_TRUE(equal(s->material.color->green, m.color->green));
	EXPECT_TRUE(equal(s->material.color->blue, m.color->blue));
}

TEST(TesterLighting, EyeBetweenLightAndSurface) {
	init_pools();
	t_material m = material();
	double *position = point(0, 0, 0);
	double *eyev = vector(0, 0, -1);
	double *normalv = vector(0, 0, -1);
	t_pt_light light = pt_light(point(0, 0, -10), create_color(1, 1, 1));
	t_sight sight = {eyev, normalv};

	t_colors *result = lighting(m, light, position, sight);

	EXPECT_TRUE(equal(result->red, 1.9));
	EXPECT_TRUE(equal(result->green, 1.9));
	EXPECT_TRUE(equal(result->blue, 1.9));
}

TEST(TesterLighting, EyeBetweenLightAndSurfaceOffset45) {
	init_pools();
	t_material m = material();
	double *position = point(0, 0, 0);
	double *eyev = vector(0, sqrt(2) / 2, -sqrt(2) / 2);
	double *normalv = vector(0, 0, -1);
	t_pt_light light = pt_light(point(0, 0, -10), create_color(1, 1, 1));
	t_sight sight = {eyev, normalv};

	t_colors *result = lighting(m, light, position, sight);

	EXPECT_TRUE(equal(result->red, 1.0));
	EXPECT_TRUE(equal(result->green, 1.0));
	EXPECT_TRUE(equal(result->blue, 1.0));
}

TEST(TesterLighting, EyeOppositeSurfaceLightOffset45) {
	init_pools();
	t_material m = material();
	double *position = point(0, 0, 0);
	double *eyev = vector(0, 0, -1);
	double *normalv = vector(0, 0, -1);
	t_pt_light light = pt_light(point(0, 10, -10), create_color(1, 1, 1));
	t_sight sight = {eyev, normalv};

	t_colors *result = lighting(m, light, position, sight);

	EXPECT_TRUE(equal(result->red, 0.7364));
	EXPECT_TRUE(equal(result->green, 0.7364));
	EXPECT_TRUE(equal(result->blue, 0.7364));
}

TEST(TesterLighting, EyeInPathOfReflectionVector) {
	init_pools();
	t_material m = material();
	double *position = point(0, 0, 0);
	double *eyev = vector(0, -sqrt(2) / 2, -sqrt(2) / 2);
	double *normalv = vector(0, 0, -1);
	t_pt_light light = pt_light(point(0, 10, -10), create_color(1, 1, 1));
	t_sight sight = {eyev, normalv};

	t_colors *result = lighting(m, light, position, sight);

	EXPECT_TRUE(equal(result->red, 1.6364));
	EXPECT_TRUE(equal(result->green, 1.6364));
	EXPECT_TRUE(equal(result->blue, 1.6364));
}

TEST(TesterLighting, LightBehindSurface) {
	init_pools();
	t_material m = material();
	double *position = point(0, 0, 0);
	double *eyev = vector(0, 0, -1);
	double *normalv = vector(0, 0, -1);
	t_pt_light light = pt_light(point(0, 0, 10), create_color(1, 1, 1));
	t_sight sight = {eyev, normalv};

	t_colors *result = lighting(m, light, position, sight);

	EXPECT_TRUE(equal(result->red, 0.1));
	EXPECT_TRUE(equal(result->green, 0.1));
	EXPECT_TRUE(equal(result->blue, 0.1));
}
