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
