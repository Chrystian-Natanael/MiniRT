#include <gtest/gtest.h>
#include <cmath>

extern "C" {
	#include "Matrices.h"
	#include "Utils.h"
	#include "Tuples.h"
	#include <stdbool.h>
}

TEST(TesterMatrix, CreateMatrix) {
	init_pools();

	double	elements_4x4[16] = {1, 2, 3, 4,
								5.5, 6.5, 7.5, 8.5,
								9, 10, 11, 12,
								13.5, 14.5, 15.5, 16.5};

	double	elements_3x3[16] = {-3, 5, 0,
								1, -2, -7,
								0, 1, 1};

	double	elements_2x2[16] = {-3, 5,
								1, -2};

	t_matrix	matrix1 = create_mtx(4, 4, elements_4x4);
	t_matrix	matrix2 = create_mtx(3, 3, elements_3x3);
	t_matrix	matrix3 = create_mtx(2, 2, elements_2x2);

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
	init_pools();

	double	elements_4x4[16] = {1, 2, 3, 4,
								5, 6, 7, 8,
								9, 8, 7, 6,
								5, 4, 3, 2};
	t_matrix	matrix1 = create_mtx(4, 4, elements_4x4);
	EXPECT_TRUE(comp_mtx(matrix1, matrix1));
}

TEST(TesterMatrix, CompareNEMatrices) {
	init_pools();

	double	elements_4x4_a[16] =	{1, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	double	elements_4x4_b[16] =	{2, 3, 4, 5,
									6, 7, 8, 9,
									8, 7, 6, 5,
									4, 3, 2, 1};

	t_matrix	matrix1 = create_mtx(4, 4, elements_4x4_a);
	t_matrix	matrix2 = create_mtx(4, 4, elements_4x4_b);

	EXPECT_FALSE(comp_mtx(matrix1, matrix2));
}

TEST(TesterMatrix, CompareNEMatricesFloatTrue) {
	init_pools();

	double	elements_4x4_a[16] =	{1.100, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	double	elements_4x4_b[16] =	{1.100005, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	t_matrix	matrix1 = create_mtx(4, 4, elements_4x4_a);
	t_matrix	matrix2 = create_mtx(4, 4, elements_4x4_b);

	EXPECT_TRUE(comp_mtx(matrix1, matrix2));
}

TEST(TesterMatrix, CompareNEMatricesFloatFalse) {
	init_pools();

	double	elements_4x4_a[16] =	{1.100, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	double	elements_4x4_b[16] =	{1.105, 2, 3, 4,
									5, 6, 7, 8,
									9, 8, 7, 6,
									5, 4, 3, 2};

	t_matrix	matrix1 = create_mtx(4, 4, elements_4x4_a);
	t_matrix	matrix2 = create_mtx(4, 4, elements_4x4_b);

	EXPECT_FALSE(comp_mtx(matrix1, matrix2));
}

TEST(TesterMatrixMultiplication, MatricesMultiplyEQSizes) {
	init_pools();

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

	t_matrix	matrix1 = create_mtx(4, 4, elements_4x4_a);
	t_matrix	matrix2 = create_mtx(4, 4, elements_4x4_b);
	t_matrix	res = multiply_mtx(matrix1, matrix2);

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
	init_pools();

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

	t_matrix	matrix1 = create_mtx(4, 4, elements_4x4);
	t_matrix	matrix2 = create_mtx(4, 3, elements_4x3);
	t_matrix	res = multiply_mtx(matrix1, matrix2);

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
	init_pools();

	double *p = point(1, 2, 3);
	double	element[16] = {1, 2, 3, 4,
							2, 4, 4, 2,
							8, 6, 4, 1,
							0, 0, 0, 1};
	t_matrix	matrix;

	matrix = create_mtx(4, 4, element);
	double	*res = multiply_mtx_tp(matrix, p);

	ASSERT_NE(p, nullptr);
	ASSERT_NE(res, nullptr);
	EXPECT_DOUBLE_EQ(res[0], 18);
	EXPECT_DOUBLE_EQ(res[1], 24);
	EXPECT_DOUBLE_EQ(res[2], 33);
	EXPECT_EQ(static_cast<int>(p[3]), POINT);

}

TEST(TesterMatrixMultiplication, id_mtxMatrixByMatrix) {
	init_pools();

	double	element1[16] = {0, 1, 2, 4,
							1, 2, 4, 8,
							2, 4, 8, 16,
							4, 8, 16, 32};
	double	element2[16] = {1, 0, 0, 0,
							0, 1, 0, 0,
							0, 0, 1, 0,
							0, 0, 0, 1};

	t_matrix	matrix = create_mtx(4, 4, element1);
	t_matrix	id_mtx = create_mtx(4, 4, element2);
	t_matrix	res = multiply_mtx(matrix, id_mtx);

	int	idx = 0;
	for (int idx_r = 0; idx_r < 4; idx_r++) {
		for (int idx_c = 0; idx_c < 4; idx_c++) {
			EXPECT_TRUE(equal(res.content[idx_r * 4 + idx_c], matrix.content[idx_r * 4 + idx_c]));
			idx++;
		}
	}
}

TEST(TesterMatrixMultiplication, id_mtxMatrixByTuple) {
	init_pools();

	double	tuple[4] = {1, 2, 3, 4};
	double	element[16] = {1, 0, 0, 0,
							0, 1, 0, 0,
							0, 0, 1, 0,
							0, 0, 0, 1};

	t_matrix	id_mtx = create_mtx(4, 4, element);
	double	*res = multiply_mtx_tp(id_mtx, tuple);

	ASSERT_NE(tuple, nullptr);
	ASSERT_NE(res, nullptr);
	EXPECT_DOUBLE_EQ(res[0], 1);
	EXPECT_DOUBLE_EQ(res[1], 2);
	EXPECT_DOUBLE_EQ(res[2], 3);
	EXPECT_DOUBLE_EQ((res[3]), 4);

}

TEST(TesterMatrixTransposition, 4x4MatrixTranspose) {
	init_pools();

	double	element[16] = {0, 9, 3, 0,
							9, 8, 0, 8,
							1, 8, 5, 3,
							0, 0, 5, 8};
	double	elem_transp[16] = {0, 9, 1, 0,
							9, 8, 8, 0,
							3, 0, 5, 5,
							0, 8, 3, 8};

	t_matrix	matrix = create_mtx(4, 4, element);
	t_matrix	transp = transp_mtx(matrix);

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
	init_pools();

	double	element[12] = {0, 9, 3,
							9, 8, 0,
							1, 8, 5,
							0, 0, 5};
	double	elem_transp[12] = {0, 9, 1, 0,
							9, 8, 8, 0,
							3, 0, 5, 5};

	t_matrix	matrix = create_mtx(4, 3, element);
	t_matrix	transp = transp_mtx(matrix);

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

TEST(TesterMatrixdet, det2x2Matrix) {
	init_pools();
	double elements_2x2[4] = {1, 5,
							-3, 2};
	t_matrix matrix = create_mtx(2, 2, elements_2x2);

	double determinant = det(matrix);

	EXPECT_DOUBLE_EQ(determinant, 17);
}

TEST(TesterMatrixsubmtx, submtx3x3To2x2) {
	init_pools();
	double elements_3x3[9] = {1, 5, 0,
							-3, 2, 7,
							0, 6, -3};
	t_matrix matrix = create_mtx(3, 3, elements_3x3);

	t_matrix submatrix = submtx(matrix, 0, 2);

	double expected_elements[4] = {-3, 2,
									 0, 6};

	for (int i = 0; i < 2; ++i) {
		for (int j = 0; j < 2; ++j) {
			EXPECT_DOUBLE_EQ(submatrix.content[i * 2 + j], expected_elements[i * 2 + j]);
		}
	}
}

TEST(TesterMatrixsubmtx, submtx4x4To3x3) {
	init_pools();
	double elements_4x4[16] = {-6, 1, 1, 6, -8, 5, 8, 6, -1, 0, 8, 2, -7, 1, -1, 1};
	t_matrix matrix = create_mtx(4, 4, elements_4x4);

	t_matrix submatrix = submtx(matrix, 2, 1);

	double expected_elements[9] = {-6, 1, 6, -8, 8, 6, -7, -1, 1};

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			EXPECT_DOUBLE_EQ(submatrix.content[i * 3 + j], expected_elements[i * 3 + j]);
		}
	}
}

TEST(TesterMatrixMinor, Minor3x3) {
	init_pools();
	double elements_3x3[9] = {3, 5, 0,
							2, -1, -7,
							6, -1, 5};

	t_matrix matrix = create_mtx(3, 3, elements_3x3);

	double minor_res = minor(matrix, 1, 0);

	EXPECT_DOUBLE_EQ(minor_res, 25);
}

TEST(TesterMatrixCofactor, Cofactor3x3) {
	init_pools();
	double elements_3x3[9] = {3, 5, 0,
							2, -1, -7,
							6, -1, 5};

	t_matrix matrix = create_mtx(3, 3, elements_3x3);

	double cofactor_res[9];
	int	k = 0;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cofactor_res[k++] = cofactor(matrix, i, j);
		}
	}

	EXPECT_DOUBLE_EQ(cofactor_res[0], -12);
	EXPECT_DOUBLE_EQ(cofactor_res[1], -52);
	EXPECT_DOUBLE_EQ(cofactor_res[2], 4);
	EXPECT_DOUBLE_EQ(cofactor_res[3], -25);
	EXPECT_DOUBLE_EQ(cofactor_res[4], 15);
	EXPECT_DOUBLE_EQ(cofactor_res[5], 33);
	EXPECT_DOUBLE_EQ(cofactor_res[6], -35);
	EXPECT_DOUBLE_EQ(cofactor_res[7], 21);
	EXPECT_DOUBLE_EQ(cofactor_res[8], -13);
}

TEST(TesterMatrixDeterminat_Larger_Than_2x2, det3x3) {
	init_pools();
	double elements_3x3[9] = {1, 2, 6,
							-5, 8, -4,
							2, 6, 4};

	t_matrix matrix = create_mtx(3, 3, elements_3x3);

	double cofactor_res[9];
	int	k = 0;

	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			cofactor_res[k++] = cofactor(matrix, i, j);
		}
	}
	EXPECT_DOUBLE_EQ(cofactor_res[0], 56);
	EXPECT_DOUBLE_EQ(cofactor_res[1], 12);
	EXPECT_DOUBLE_EQ(cofactor_res[2], -46);
}


TEST(TesterMatrixdet, det3x3Matrix) {
	init_pools();
	double elements_3x3[9] = {1, 2, 6,
							-5, 8, -4,
							2, 6, 4};
	t_matrix matrix = create_mtx(3, 3, elements_3x3);

	double cofactor_res[3];
	cofactor_res[0] = cofactor(matrix, 0, 0);
	cofactor_res[1] = cofactor(matrix, 0, 1);
	cofactor_res[2] = cofactor(matrix, 0, 2);

	EXPECT_DOUBLE_EQ(cofactor_res[0], 56);
	EXPECT_DOUBLE_EQ(cofactor_res[1], 12);
	EXPECT_DOUBLE_EQ(cofactor_res[2], -46);

	double determinant = det(matrix);
	EXPECT_DOUBLE_EQ(determinant, -196);
}

TEST(TesterMatrixdet, det4x4Matrix) {
	init_pools();
	double elements_4x4[16] = {-2, -8, 3, 5,
							-3, 1, 7, 3,
							1, 2, -9, 6,
							-6, 7, 7, -9};
	t_matrix matrix = create_mtx(4, 4, elements_4x4);

	double cofactor_res[4];
	cofactor_res[0] = cofactor(matrix, 0, 0);
	cofactor_res[1] = cofactor(matrix, 0, 1);
	cofactor_res[2] = cofactor(matrix, 0, 2);
	cofactor_res[3] = cofactor(matrix, 0, 3);

	EXPECT_DOUBLE_EQ(cofactor_res[0], 690);
	EXPECT_DOUBLE_EQ(cofactor_res[1], 447);
	EXPECT_DOUBLE_EQ(cofactor_res[2], 210);
	EXPECT_DOUBLE_EQ(cofactor_res[3], 51);

	double determinant = det(matrix);
	EXPECT_DOUBLE_EQ(determinant, -4071);
}

TEST(TesterMatrixinv, invMatrixScenario1) {
	init_pools();
	double elements[16] = {-5, 2, 6, -8,
							1, -5, 1, 8,
							7, 7, -6, -7,
							1, -3, 7, 4};
	t_matrix matrix = create_mtx(4, 4, elements);
	t_matrix inv_matrix = inv(matrix);

	double expected_inv[16] = {0.21805, 0.45113, 0.24060, -0.04511,
									-0.80827, -1.45677, -0.44361, 0.52068,
									-0.07895, -0.22368, -0.05263, 0.19737,
									-0.52256, -0.81391, -0.30075, 0.30639};

	double determinant = det(matrix);
	EXPECT_DOUBLE_EQ(determinant, 532);

	double cofactor_2_3 = cofactor(matrix, 2, 3);
	EXPECT_DOUBLE_EQ(cofactor_2_3, -160);
	EXPECT_TRUE(equal(inv_matrix.content[3 * 4 + 2], (-160.0 / 532.0)));

	double cofactor_3_2 = cofactor(matrix, 3, 2);
	EXPECT_DOUBLE_EQ(cofactor_3_2, 105);
	EXPECT_DOUBLE_EQ(inv_matrix.content[2 * 4 + 3], 105.0 / 532.0);

	for (int i = 0; i < 16; ++i) {
		EXPECT_TRUE(equal(inv_matrix.content[i], expected_inv[i]));
	}
}

TEST(TesterMatrixinv, invMatrixScenario2) {
	init_pools();
	double elements[16] = {8, -5, 9, 2,
							7, 5, 6, 1,
							-6, 0, 9, 6,
							-3, 0, -9, -4};
	t_matrix matrix = create_mtx(4, 4, elements);
	t_matrix inv_matrix = inv(matrix);

	double expected_inv[16] = {-0.15385, -0.15385, -0.28205, -0.53846,
									-0.07692, 0.12308, 0.02564, 0.03077,
									0.35897, 0.35897, 0.43590, 0.92308,
									-0.69231, -0.69231, -0.76923, -1.92308};

	for (int i = 0; i < 16; ++i) {
		EXPECT_TRUE(equal(inv_matrix.content[i], expected_inv[i]));
	}
}

TEST(TesterMatrixinv, invMatrixScenario3) {
	init_pools();
	double elements[16] = {9, 3, 0, 9,
							-5, -2, -6, -3,
							-4, 9, 6, 4,
							-7, 6, 6, 2};
	t_matrix matrix = create_mtx(4, 4, elements);
	t_matrix inv_matrix = inv(matrix);

	double expected_inv[16] = {-0.04074, -0.07778, 0.14444, -0.22222,
									-0.07778, 0.03333, 0.36667, -0.33333,
									-0.02901, -0.14630, -0.10926, 0.12963,
									0.17778, 0.06667, -0.26667, 0.33333};

	for (int i = 0; i < 16; ++i) {
		EXPECT_TRUE(equal(inv_matrix.content[i], expected_inv[i]));
	}
}

TEST(TesterMatrixinv, MultiplyingProductByItsinv) {
	init_pools();
	double elementsA[16] = {3, -9, 7, 3,
							3, -8, 2, -9,
							-4, 4, 4, 1,
							-6, 5, -1, 1};
	double elementsB[16] = {8, 2, 2, 2,
							3, -1, 7, 0,
							7, 0, 5, 4,
							6, -2, 0, 5};

	t_matrix matrixA = create_mtx(4, 4, elementsA);
	t_matrix matrixB = create_mtx(4, 4, elementsB);
	t_matrix matrixC = multiply_mtx(matrixA, matrixB);
	t_matrix invB = inv(matrixB);
	t_matrix result = multiply_mtx(matrixC, invB);

	for (int i = 0; i < 16; ++i) {
		EXPECT_NEAR(result.content[i], matrixA.content[i], 1e-5);
	}
}
