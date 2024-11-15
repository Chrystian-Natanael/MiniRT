#include <gtest/gtest.h>
#include <cmath>

extern "C" {
	#include "Matrices.h"
	#include "Error.h"
	#include "Tuples.h"
	#include <stdbool.h>
}

TEST(TesterMatrix, CreateMatrix) {

	double	elements_4x4[16] = {1, 2, 3, 4,
								5.5, 6.5, 7.5, 8.5,
								9, 10, 11, 12,
								13.5, 14.5, 15.5, 16.5};

	double	elements_3x3[16] = {-3, 5, 0,
								1, -2, -7,
								0, 1, 1};

	double	elements_2x2[16] = {-3, 5,
								1, -2};

	t_matrix	matrix1 = create_matrix(4, 4, elements_4x4);
	t_matrix	matrix2 = create_matrix(3, 3, elements_3x3);
	t_matrix	matrix3 = create_matrix(2, 2, elements_2x2);

	ASSERT_NE(matrix1.content, nullptr);
	ASSERT_NE(matrix2.content, nullptr);
	ASSERT_NE(matrix3.content, nullptr);

	int	idx = 0;
	for (int idx_r = 0; idx_r < 4; idx_r++) {

		for (int idx_c = 0; idx_c < 4; idx_c++) {
			EXPECT_TRUE(equal(matrix1.content[idx_r * 4 + idx_c], elements_4x4[idx]));
			idx++;
		}
	}
	idx = 0;
	for (int idx_r = 0; idx_r < 3; idx_r++) {

		for (int idx_c = 0; idx_c < 3; idx_c++) {
			EXPECT_TRUE(equal(matrix2.content[idx_r * 3 + idx_c], elements_3x3[idx]));
			idx++;
		}
	}
	idx = 0;
	for (int idx_r = 0; idx_r < 2; idx_r++) {

		for (int idx_c = 0; idx_c < 2; idx_c++) {
			EXPECT_TRUE(equal(matrix3.content[idx_r * 2 + idx_c], elements_2x2[idx]));
			idx++;
		}
	}
}

TEST(TesterMatrix, CompareEQMatrices) {

	double	elements_4x4[16] = {1, 2, 3, 4,
								5, 6, 7, 8,
								9, 8, 7, 6,
								5, 4, 3, 2};
	t_matrix	matrix1 = create_matrix(4, 4, elements_4x4);
	EXPECT_TRUE(compare_matrix(matrix1, matrix1));
}

TEST(TesterMatrix, CompareNEMatrices) {

	double	elements_4x4_a[16] =	{1, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	double	elements_4x4_b[16] =	{2, 3, 4, 5,
									6, 7, 8, 9,
									8, 7, 6, 5,
									4, 3, 2, 1};

	t_matrix	matrix1 = create_matrix(4, 4, elements_4x4_a);
	t_matrix	matrix2 = create_matrix(4, 4, elements_4x4_b);

	EXPECT_FALSE(compare_matrix(matrix1, matrix2));
}

TEST(TesterMatrix, CompareNEMatricesFloatTrue) {

	double	elements_4x4_a[16] =	{1.100, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	double	elements_4x4_b[16] =	{1.100005, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	t_matrix	matrix1 = create_matrix(4, 4, elements_4x4_a);
	t_matrix	matrix2 = create_matrix(4, 4, elements_4x4_b);

	EXPECT_TRUE(compare_matrix(matrix1, matrix2));
}

TEST(TesterMatrix, CompareNEMatricesFloatFalse) {

	double	elements_4x4_a[16] =	{1.100, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	double	elements_4x4_b[16] =	{1.105, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	t_matrix	matrix1 = create_matrix(4, 4, elements_4x4_a);
	t_matrix	matrix2 = create_matrix(4, 4, elements_4x4_b);

	EXPECT_FALSE(compare_matrix(matrix1, matrix2));
}

TEST(TesterMatrixMultiplication, MatricesMultiplyEQSizes) {

	double	elements_4x4_a[16] =	{1, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	double	elements_4x4_b[16] =	{-2, 1, 2, 3,
									3, 2, 1, -1,
									4, 3, 6, 5,
									1, 2, 7, 8};

	double	elements_res[16] = 		{20, 22, 50, 48,
									44, 54, 114, 108,
									40, 58, 110, 102,
									16, 26, 46, 42};

	t_matrix	matrix1 = create_matrix(4, 4, elements_4x4_a);
	t_matrix	matrix2 = create_matrix(4, 4, elements_4x4_b);
	t_matrix	res = matrix_multiply(matrix1, matrix2);

	EXPECT_DOUBLE_EQ(res.col, matrix2.col);
	EXPECT_DOUBLE_EQ(res.row, matrix1.row);

	int	idx = 0;
	for (int idx_r = 0; idx_r < 4; idx_r++) {
		for (int idx_c = 0; idx_c < 4; idx_c++) {
			EXPECT_TRUE(equal(res.content[idx_r * 4 + idx_c], elements_res[idx]));
			idx++;
		}
	}
}

TEST(TesterMatrixMultiplication, MatricesMultiplyDiffSizes) {

	double	elements_4x4[16] =	{1, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	double	elements_4x3[12] =	{-2, 1, 2,
									3, 2, 1,
									4, 3, 6,
									1, 2, 7};

	double	elements_res[12] = 		{20, 22, 50,
									44, 54, 114,
									40, 58, 110,
									16, 26, 46};

	t_matrix	matrix1 = create_matrix(4, 4, elements_4x4);
	t_matrix	matrix2 = create_matrix(4, 3, elements_4x3);
	t_matrix	res = matrix_multiply(matrix1, matrix2);

	EXPECT_DOUBLE_EQ(res.col, matrix2.col);
	EXPECT_DOUBLE_EQ(res.row, matrix1.row);

	int	idx = 0;
	for (int idx_r = 0; idx_r < 4; idx_r++) {
		for (int idx_c = 0; idx_c < 3; idx_c++) {
			EXPECT_TRUE(equal(res.content[idx_r * 4 + idx_c], elements_res[idx]));
			idx++;
		}
	}
}

TEST(TesterMatrixMultiplication, MatricesTuplesMultiply) {

	double *p = point(1, 2, 3);
	double	element[16] = {1, 2, 3, 4,
							2, 4, 4, 2,
							8, 6, 4, 1,
							0, 0, 0, 1};
	t_matrix	matrix;

	matrix = create_matrix(4, 4, element);
	double	*res = matrix_tuple_multiply(matrix, p);

	ASSERT_NE(p, nullptr);
	ASSERT_NE(res, nullptr);
	EXPECT_DOUBLE_EQ(res[0], 18);
	EXPECT_DOUBLE_EQ(res[1], 24);
	EXPECT_DOUBLE_EQ(res[2], 33);
	EXPECT_EQ(static_cast<int>(p[3]), POINT);

	free(p);
	free(res);
}

TEST(TesterMatrixMultiplication, IdentityMatrixByMatrix) {

	double	element1[16] = {0, 1, 2, 4,
							1, 2, 4, 8,
							2, 4, 8, 16,
							4, 8, 16, 32};
	double	element2[16] = {1, 0, 0, 0,
							0, 1, 0, 0,
							0, 0, 1, 0,
							0, 0, 0, 1};

	t_matrix	matrix = create_matrix(4, 4, element1);
	t_matrix	identity = create_matrix(4, 4, element2);
	t_matrix	res = matrix_multiply(matrix, identity);

	int	idx = 0;
	for (int idx_r = 0; idx_r < 4; idx_r++) {
		for (int idx_c = 0; idx_c < 4; idx_c++) {
			EXPECT_TRUE(equal(res.content[idx_r * 4 + idx_c], matrix.content[idx_r * 4 + idx_c]));
			idx++;
		}
	}
}

TEST(TesterMatrixMultiplication, IdentityMatrixByTuple) {

	double	tuple[4] = {1, 2, 3, 4};
	double	element[16] = {1, 0, 0, 0,
							0, 1, 0, 0,
							0, 0, 1, 0,
							0, 0, 0, 1};

	t_matrix	identity = create_matrix(4, 4, element);
	double	*res = matrix_tuple_multiply(identity, tuple);

	ASSERT_NE(tuple, nullptr);
	ASSERT_NE(res, nullptr);
	EXPECT_DOUBLE_EQ(res[0], 1);
	EXPECT_DOUBLE_EQ(res[1], 2);
	EXPECT_DOUBLE_EQ(res[2], 3);
	EXPECT_DOUBLE_EQ((res[3]), 4);

	free(res);
}

TEST(TesterMatrixTransposition, 4x4MatrixTranspose) {

	double	element[16] = {0, 9, 3, 0,
							9, 8, 0, 8,
							1, 8, 5, 3,
							0, 0, 5, 8};
	double	elem_transp[16] = {0, 9, 1, 0,
							9, 8, 8, 0,
							3, 0, 5, 5,
							0, 8, 3, 8};

	t_matrix	matrix = create_matrix(4, 4, element);
	t_matrix	transp = matrix_transpose(matrix);

	EXPECT_EQ(transp.col, matrix.row);
	EXPECT_EQ(transp.row, matrix.col);

	int	idx = 0;
	for (int idx_r = 0; idx_r < 4; idx_r++) {
		for (int idx_c = 0; idx_c < 4; idx_c++) {
			EXPECT_DOUBLE_EQ(transp.content[idx_r * 4 + idx_c], elem_transp[idx]);
			idx++;
		}
	}
}

TEST(TesterMatrixTransposition, 4x3MatrixTranspose) {

	double	element[12] = {0, 9, 3,
							9, 8, 0,
							1, 8, 5,
							0, 0, 5};
	double	elem_transp[12] = {0, 9, 1, 0,
							9, 8, 8, 0,
							3, 0, 5, 5};

	t_matrix	matrix = create_matrix(4, 3, element);
	t_matrix	transp = matrix_transpose(matrix);

	EXPECT_EQ(transp.col, matrix.row);
	EXPECT_EQ(transp.row, matrix.col);

	int	idx = 0;
	for (int idx_r = 0; idx_r < 4; idx_r++) {
		for (int idx_c = 0; idx_c < 3; idx_c++) {
			EXPECT_DOUBLE_EQ(transp.content[idx_r * 3 + idx_c], elem_transp[idx]);
			idx++;
		}
	}
}

TEST(TesterMatrixDeterminant, Determinant2x2Matrix) {
	double elements_2x2[4] = {1, 5,
							-3, 2};
	t_matrix matrix = create_matrix(2, 2, elements_2x2);

	double det = determinant(matrix);

	EXPECT_DOUBLE_EQ(det, 17);
}

TEST(TesterMatrixSubmatrix, Submatrix3x3To2x2) {
	double elements_3x3[9] = {1, 5, 0,
							-3, 2, 7,
							0, 6, -3};
	t_matrix matrix = create_matrix(3, 3, elements_3x3);

	t_matrix submtx = submatrix(matrix, 0, 2);

	double expected_elements[4] = {-3, 2,
									 0, 6};

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			EXPECT_DOUBLE_EQ(submtx.content[i * 2 + j], expected_elements[i * 2 + j]);
		}
	}
}

TEST(TesterMatrixSubmatrix, Submatrix4x4To3x3) {
	double elements_4x4[16] = {-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1};
	t_matrix matrix = create_matrix(4, 4, elements_4x4);

	t_matrix submtx = submatrix(matrix, 2, 1);

	double expected_elements[9] = {-6, 1, 6, -8, 8, 6, -7, -1, 1};

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			EXPECT_DOUBLE_EQ(submtx.content[i * 3 + j], expected_elements[i * 3 + j]);
		}
	}
}