#include <gtest/gtest.h>
#include <cmath>

extern "C" {
	#include "Matrices.h"
	#include "Utils.h"
	#include "Tuples.h"
	#include <stdbool.h>
}

TEST(TesterMatrixTranslation, MultiplyingByTranslationMatrix) {
	t_matrix transform = translation(5, -3, 2);
	double *p = point(-3, 4, 5);
	double *expected_point = point(2, 1, 7);

	double *result = matrix_tuple_multiply(transform, p);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_point[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_point[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_point[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_point[3]);

	free(p);
	free(expected_point);
	free(result);
}

TEST(TesterMatrixTranslation, MultiplyingByInverseOfTranslationMatrix) {
	t_matrix transform = translation(5, -3, 2);
	t_matrix inv = inverse(transform);
	double *p = point(-3, 4, 5);
	double *expected_point = point(-8, 7, 3);

	double *result = matrix_tuple_multiply(inv, p);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_point[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_point[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_point[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_point[3]);

	free(p);
	free(expected_point);
	free(result);
}

TEST(TesterMatrixTranslation, TranslationDoesNotAffectVectors) {
	t_matrix transform = translation(5, -3, 2);
	double *v = vector(-3, 4, 5);

	double *result = matrix_tuple_multiply(transform, v);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], v[0]);
	EXPECT_DOUBLE_EQ(result[1], v[1]);
	EXPECT_DOUBLE_EQ(result[2], v[2]);
	EXPECT_DOUBLE_EQ(result[3], v[3]);

	free(v);
	free(result);
}

TEST(TesterMatrixScaling, ScalingMatrixAppliedToPoint) {
	t_matrix transform = scaling(2, 3, 4);
	double *p = point(-4, 6, 8);
	double *expected_point = point(-8, 18, 32);

	double *result = matrix_tuple_multiply(transform, p);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_point[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_point[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_point[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_point[3]);

	free(p);
	free(expected_point);
	free(result);
}

TEST(TesterMatrixScaling, ScalingMatrixAppliedToVector) {
	t_matrix transform = scaling(2, 3, 4);
	double *v = vector(-4, 6, 8);
	double *expected_vector = vector(-8, 18, 32);

	double *result = matrix_tuple_multiply(transform, v);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_vector[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_vector[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_vector[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_vector[3]);

	free(v);
	free(expected_vector);
	free(result);
}

TEST(TesterMatrixScaling, MultiplyingByInverseOfScalingMatrix) {
	t_matrix transform = scaling(2, 3, 4);
	t_matrix inv = inverse(transform);
	double *v = vector(-4, 6, 8);
	double *expected_vector = vector(-2, 2, 2);

	double *result = matrix_tuple_multiply(inv, v);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_vector[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_vector[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_vector[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_vector[3]);

	free(v);
	free(expected_vector);
	free(result);
}

TEST(TesterMatrixScaling, ReflectionIsScalingByNegativeValue) {
	t_matrix transform = scaling(-1, 1, 1);
	double *p = point(2, 3, 4);
	double *expected_point = point(-2, 3, 4);

	double *result = matrix_tuple_multiply(transform, p);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], expected_point[0]);
	EXPECT_DOUBLE_EQ(result[1], expected_point[1]);
	EXPECT_DOUBLE_EQ(result[2], expected_point[2]);
	EXPECT_DOUBLE_EQ(result[3], expected_point[3]);

	free(p);
	free(expected_point);
	free(result);
}

TEST(TesterMatrixRotation, RotatingPointAroundZAxis) {
	double pi = M_PI;
	double sqrt2_over_2 = sqrt(2) / 2;

	double *p = point(0, 1, 0);
	t_matrix half_quarter = rotation_z(pi / 4);
	t_matrix full_quarter = rotation_z(pi / 2);

	double *expected_half_quarter = point(-sqrt2_over_2, sqrt2_over_2, 0);
	double *expected_full_quarter = point(-1, 0, 0);

	double *result_half_quarter = matrix_tuple_multiply(half_quarter, p);
	double *result_full_quarter = matrix_tuple_multiply(full_quarter, p);

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

	free(p);
	free(expected_half_quarter);
	free(expected_full_quarter);
	free(result_half_quarter);
	free(result_full_quarter);
}

TEST(TesterMatrixRotation, RotatingPointAroundYAxis) {
	double pi = M_PI;
	double sqrt2_over_2 = sqrt(2) / 2;

	double *p = point(0, 0, 1);
	t_matrix half_quarter = rotation_y(pi / 4);
	t_matrix full_quarter = rotation_y(pi / 2);

	double *expected_half_quarter = point(sqrt2_over_2, 0, sqrt2_over_2);
	double *expected_full_quarter = point(1, 0, 0);

	double *result_half_quarter = matrix_tuple_multiply(half_quarter, p);
	double *result_full_quarter = matrix_tuple_multiply(full_quarter, p);

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

	free(p);
	free(expected_half_quarter);
	free(expected_full_quarter);
	free(result_half_quarter);
	free(result_full_quarter);
}

TEST(TesterMatrixRotation, InverseOfXRotationRotatesOppositeDirection) {
	double pi = M_PI;
	double sqrt2_over_2 = sqrt(2) / 2;

	double *p = point(0, 1, 0);
	t_matrix half_quarter = rotation_x(pi / 4);
	t_matrix inv = inverse(half_quarter);

	double *expected_point = point(0, sqrt2_over_2, -sqrt2_over_2);

	double *result = matrix_tuple_multiply(inv, p);

	ASSERT_NE(result, nullptr);
	EXPECT_NEAR(result[0], expected_point[0], 1e-5);
	EXPECT_NEAR(result[1], expected_point[1], 1e-5);
	EXPECT_NEAR(result[2], expected_point[2], 1e-5);
	EXPECT_NEAR(result[3], expected_point[3], 1e-5);

	free(p);
	free(expected_point);
	free(result);
}

TEST(TesterMatrixRotation, RotatingPointAroundXAxis) {
	double pi = M_PI;
	double sqrt2_over_2 = sqrt(2) / 2;

	double *p = point(0, 1, 0);
	t_matrix half_quarter = rotation_x(pi / 4);
	t_matrix full_quarter = rotation_x(pi / 2);

	double *expected_half_quarter = point(0, sqrt2_over_2, sqrt2_over_2);
	double *expected_full_quarter = point(0, 0, 1);

	double *result_half_quarter = matrix_tuple_multiply(half_quarter, p);
	double *result_full_quarter = matrix_tuple_multiply(full_quarter, p);

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

	free(p);
	free(expected_half_quarter);
	free(expected_full_quarter);
	free(result_half_quarter);
	free(result_full_quarter);
}

TEST(Transformations, IndividualTransformationsSequence) {
	double *p = point(1, 0, 1);
	t_matrix A = rotation_x(M_PI / 2);
	t_matrix B = scaling(5, 5, 5);
	t_matrix C = translation(10, 5, 7);

	// Apply rotation first
	double *p2 = matrix_tuple_multiply(A, p);
	ASSERT_NE(p2, nullptr);
	EXPECT_TRUE(equal(p2[0], 1));
	EXPECT_TRUE(equal(p2[1], -1));
	EXPECT_TRUE(equal(p2[2], 0));

	// Apply scaling
	double *p3 = matrix_tuple_multiply(B, p2);
	ASSERT_NE(p3, nullptr);
	EXPECT_TRUE(equal(p3[0], 5));
	EXPECT_TRUE(equal(p3[1], -5));
	EXPECT_TRUE(equal(p3[2], 0));

	// Apply translation
	double *p4 = matrix_tuple_multiply(C, p3);
	ASSERT_NE(p4, nullptr);
	EXPECT_TRUE(equal(p4[0], 15));
	EXPECT_TRUE(equal(p4[1], 0));
	EXPECT_TRUE(equal(p4[2], 7));

	free(p);
	free(p2);
	free(p3);
	free(p4);
}

TEST(Transformations, ChainedTransformationsReverseOrder) {
	double *p = point(1, 0, 1);
	t_matrix A = rotation_x(M_PI / 2);
	t_matrix B = scaling(5, 5, 5);
	t_matrix C = translation(10, 5, 7);

	// Chained transformations
	t_matrix T = matrix_multiply(C, matrix_multiply(B, A));
	double *result = matrix_tuple_multiply(T, p);

	ASSERT_NE(result, nullptr);
	EXPECT_DOUBLE_EQ(result[0], 15);
	EXPECT_DOUBLE_EQ(result[1], 0);
	EXPECT_DOUBLE_EQ(result[2], 7);

	free(p);
	free(result);
}