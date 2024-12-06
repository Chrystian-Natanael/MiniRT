#include <gtest/gtest.h>
#include <cmath>

extern "C"
{
#include "Matrices.h"
#include "Utils.h"
#include "Tuples.h"
#include <stdbool.h>
}

TEST(TesterMatrixtranslate, MultiplyingBytranslateMatrix)
{
	init_pools();
	t_matrix transform = translate(5, -3, 2);
	double *p = point(-3, 4, 5);
	double *expected_point = point(2, 1, 7);

	double *result = multiply_mtx_tp(transform, p);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_point[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_point[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_point[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_point[3]);

}

TEST(TesterMatrixtranslate, MultiplyingByinvOftranslateMatrix)
{
	init_pools();
	t_matrix transform = translate(5, -3, 2);
	t_matrix inverse = inv(transform);
	double *p = point(-3, 4, 5);
	double *expected_point = point(-8, 7, 3);

	double *result = multiply_mtx_tp(inverse, p);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_point[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_point[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_point[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_point[3]);

}

TEST(TesterMatrixtranslate, translateDoesNotAffectVectors)
{
	init_pools();
	t_matrix transform = translate(5, -3, 2);
	double *v = vector(-3, 4, 5);

	double *result = multiply_mtx_tp(transform, v);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], v[0]);
	EXPECT_DOUBLE_EQ(result[1], v[1]);
	EXPECT_DOUBLE_EQ(result[2], v[2]);
	EXPECT_DOUBLE_EQ(result[3], v[3]);

}

TEST(TesterMatrixscale, scaleMatrixAppliedToPoint)
{
	init_pools();
	t_matrix transform = scale(2, 3, 4);
	double *p = point(-4, 6, 8);
	double *expected_point = point(-8, 18, 32);

	double *result = multiply_mtx_tp(transform, p);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_point[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_point[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_point[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_point[3]);

}

TEST(TesterMatrixscale, scaleMatrixAppliedToVector)
{
	init_pools();
	t_matrix transform = scale(2, 3, 4);
	double *v = vector(-4, 6, 8);
	double *expected_vector = vector(-8, 18, 32);

	double *result = multiply_mtx_tp(transform, v);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_vector[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_vector[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_vector[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_vector[3]);

}

TEST(TesterMatrixscale, MultiplyingByinvOfscaleMatrix)
{
	init_pools();
	t_matrix transform = scale(2, 3, 4);
	t_matrix inverse = inv(transform);
	double *v = vector(-4, 6, 8);
	double *expected_vector = vector(-2, 2, 2);

	double *result = multiply_mtx_tp(inverse, v);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_vector[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_vector[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_vector[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_vector[3]);

}

TEST(TesterMatrixscale, ReflectionIsscaleByNegativeValue)
{
	init_pools();
	t_matrix transform = scale(-1, 1, 1);
	double *p = point(2, 3, 4);
	double *expected_point = point(-2, 3, 4);

	double *result = multiply_mtx_tp(transform, p);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_point[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_point[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_point[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_point[3]);

}

TEST(TesterMatrixRotation, RotatingPointAroundZAxis)
{
	init_pools();
	double pi = M_PI;
	double sqrt2_over_2 = sqrt(2) / 2;

	double *p = point(0, 1, 0);
	t_matrix half_quarter = rotate_z(pi / 4);
	t_matrix full_quarter = rotate_z(pi / 2);

	double *expected_half_quarter = point(-sqrt2_over_2, sqrt2_over_2, 0);
	double *expected_full_quarter = point(-1, 0, 0);

	double *result_half_quarter = multiply_mtx_tp(half_quarter, p);
	double *result_full_quarter = multiply_mtx_tp(full_quarter, p);

	ASSERT_NE(result_half_quarter, nullptr);
	EXPECT_NEAR(result_half_quarter[0], expected_half_quarter[0], 1e-5);
	EXPECT_NEAR(result_half_quarter[1], expected_half_quarter[1], 1e-5);
	EXPECT_NEAR(result_half_quarter[2], expected_half_quarter[2], 1e-5);
	EXPECT_NEAR(result_half_quarter[3], expected_half_quarter[3], 1e-5);

	ASSERT_NE(result_full_quarter, nullptr);
	EXPECT_NEAR(result_full_quarter[0], expected_full_quarter[0], 1e-5);
	EXPECT_NEAR(result_full_quarter[1], expected_full_quarter[1], 1e-5);
	EXPECT_NEAR(result_full_quarter[2], expected_full_quarter[2], 1e-5);
	EXPECT_NEAR(result_full_quarter[3], expected_full_quarter[3], 1e-5);

}

TEST(TesterMatrixRotation, RotatingPointAroundYAxis)
{
	init_pools();
	double pi = M_PI;
	double sqrt2_over_2 = sqrt(2) / 2;

	double *p = point(0, 0, 1);
	t_matrix half_quarter = rotate_y(pi / 4);
	t_matrix full_quarter = rotate_y(pi / 2);

	double *expected_half_quarter = point(sqrt2_over_2, 0, sqrt2_over_2);
	double *expected_full_quarter = point(1, 0, 0);

	double *result_half_quarter = multiply_mtx_tp(half_quarter, p);
	double *result_full_quarter = multiply_mtx_tp(full_quarter, p);

	ASSERT_NE(result_half_quarter, nullptr);
	EXPECT_NEAR(result_half_quarter[0], expected_half_quarter[0], 1e-5);
	EXPECT_NEAR(result_half_quarter[1], expected_half_quarter[1], 1e-5);
	EXPECT_NEAR(result_half_quarter[2], expected_half_quarter[2], 1e-5);
	EXPECT_NEAR(result_half_quarter[3], expected_half_quarter[3], 1e-5);

	ASSERT_NE(result_full_quarter, nullptr);
	EXPECT_NEAR(result_full_quarter[0], expected_full_quarter[0], 1e-5);
	EXPECT_NEAR(result_full_quarter[1], expected_full_quarter[1], 1e-5);
	EXPECT_NEAR(result_full_quarter[2], expected_full_quarter[2], 1e-5);
	EXPECT_NEAR(result_full_quarter[3], expected_full_quarter[3], 1e-5);

}

TEST(TesterMatrixRotation, invOfXRotationRotatesOppositedir)
{
	init_pools();
	double pi = M_PI;
	double sqrt2_over_2 = sqrt(2) / 2;

	double *p = point(0, 1, 0);
	t_matrix half_quarter = rotate_x(pi / 4);
	t_matrix inverse = inv(half_quarter);

	double *expected_point = point(0, sqrt2_over_2, -sqrt2_over_2);

	double *result = multiply_mtx_tp(inverse, p);

	ASSERT_NE(result, nullptr);
	EXPECT_NEAR(result[0], expected_point[0], 1e-5);
	EXPECT_NEAR(result[1], expected_point[1], 1e-5);
	EXPECT_NEAR(result[2], expected_point[2], 1e-5);
	EXPECT_NEAR(result[3], expected_point[3], 1e-5);

}

TEST(TesterMatrixRotation, RotatingPointAroundXAxis)
{
	init_pools();
	double pi = M_PI;
	double sqrt2_over_2 = sqrt(2) / 2;

	double *p = point(0, 1, 0);
	t_matrix half_quarter = rotate_x(pi / 4);
	t_matrix full_quarter = rotate_x(pi / 2);

	double *expected_half_quarter = point(0, sqrt2_over_2, sqrt2_over_2);
	double *expected_full_quarter = point(0, 0, 1);

	double *result_half_quarter = multiply_mtx_tp(half_quarter, p);
	double *result_full_quarter = multiply_mtx_tp(full_quarter, p);

	ASSERT_NE(result_half_quarter, nullptr);
	EXPECT_NEAR(result_half_quarter[0], expected_half_quarter[0], 1e-5);
	EXPECT_NEAR(result_half_quarter[1], expected_half_quarter[1], 1e-5);
	EXPECT_NEAR(result_half_quarter[2], expected_half_quarter[2], 1e-5);
	EXPECT_NEAR(result_half_quarter[3], expected_half_quarter[3], 1e-5);

	ASSERT_NE(result_full_quarter, nullptr);
	EXPECT_NEAR(result_full_quarter[0], expected_full_quarter[0], 1e-5);
	EXPECT_NEAR(result_full_quarter[1], expected_full_quarter[1], 1e-5);
	EXPECT_NEAR(result_full_quarter[2], expected_full_quarter[2], 1e-5);
	EXPECT_NEAR(result_full_quarter[3], expected_full_quarter[3], 1e-5);

}

TEST(Transformations, IndividualTransformationsSequence)
{
	init_pools();
	double *p = point(1, 0, 1);
	t_matrix A = rotate_x(M_PI / 2);
	t_matrix B = scale(5, 5, 5);
	t_matrix C = translate(10, 5, 7);

	// Apply rotation first
	double *p2 = multiply_mtx_tp(A, p);
	ASSERT_NE(p2, nullptr);
	EXPECT_TRUE(equal(p2[0], 1));
	EXPECT_TRUE(equal(p2[1], -1));
	EXPECT_TRUE(equal(p2[2], 0));

	// Apply scale
	double *p3 = multiply_mtx_tp(B, p2);
	ASSERT_NE(p3, nullptr);
	EXPECT_TRUE(equal(p3[0], 5));
	EXPECT_TRUE(equal(p3[1], -5));
	EXPECT_TRUE(equal(p3[2], 0));

	// Apply translation
	double *p4 = multiply_mtx_tp(C, p3);
	ASSERT_NE(p4, nullptr);
	EXPECT_TRUE(equal(p4[0], 15));
	EXPECT_TRUE(equal(p4[1], 0));
	EXPECT_TRUE(equal(p4[2], 7));

}

TEST(Transformations, ChainedTransformationsReverseOrder)
{
	init_pools();
	double *p = point(1, 0, 1);
	t_matrix A = rotate_x(M_PI / 2);
	t_matrix B = scale(5, 5, 5);
	t_matrix C = translate(10, 5, 7);

	// Chained transformations
	t_matrix T = multiply_mtx(C, multiply_mtx(B, A));
	double *result = multiply_mtx_tp(T, p);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], 15);
	EXPECT_DOUBLE_EQ(result[1], 0);
	EXPECT_DOUBLE_EQ(result[2], 7);

}