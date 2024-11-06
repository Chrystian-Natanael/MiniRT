#include <gtest/gtest.h>
#include <cstdlib>

extern "C" {
	#include "Tuples.h"
}

TEST(PointAndVectorTest, TestPointFunction) {
	double *p = point(1.0, 2.0, 3.0);

	ASSERT_NE(p, nullptr);
	EXPECT_DOUBLE_EQ(p[0], 1.0);
	EXPECT_DOUBLE_EQ(p[1], 2.0);
	EXPECT_DOUBLE_EQ(p[2], 3.0);
	EXPECT_EQ(static_cast<int>(p[3]), POINT);

	free(p);
}

TEST(PointAndVectorTest, TestVectorFunction) {
	double *v = vector(4.0, 5.0, 6.0);

	ASSERT_NE(v, nullptr);
	EXPECT_DOUBLE_EQ(v[0], 4.0);
	EXPECT_DOUBLE_EQ(v[1], 5.0);
	EXPECT_DOUBLE_EQ(v[2], 6.0);
	EXPECT_EQ(static_cast<int>(v[3]), VECTOR);

	free(v);
}

TEST(PointAndVectorTest, TestEqualFunction) {
	double x = (1.100);
	EXPECT_TRUE(equal(x, 1.100005));
	EXPECT_FALSE(equal(x, 1.105));
}

TEST(OperationsTest, TestSumFunction) {
	double *p1 = point(3, -2, 5);
	double *p2 = point(3, -2, 5);
	double *v = vector(-2, 3, 1);
	double *r = sum(p1, v);

	ASSERT_NE(r, nullptr);
	EXPECT_EQ(sum(p1, p2), nullptr);
	EXPECT_DOUBLE_EQ(r[0], 1);
	EXPECT_DOUBLE_EQ(r[1], 1);
	EXPECT_DOUBLE_EQ(r[2], 6);
	EXPECT_DOUBLE_EQ(r[3], 1);

	free(p1);
	free(p2);
	free(v);
	free(r);
}

TEST(OperationsTest, TestSubFunctionWith2Pts) {
	double *p1 = point(3, 2, 1);
	double *p2 = point(5, 6, 7);
	double *r = sub(p1, p2);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], -2);
	EXPECT_DOUBLE_EQ(r[1], -4);
	EXPECT_DOUBLE_EQ(r[2], -6);
	EXPECT_DOUBLE_EQ(r[3], 0);

	free(p1);
	free(p2);
	free(r);
}

TEST(OperationsTest, TestSubFunctionWithPtAndVec) {
	double *p = point(3, 2, 1);
	double *v = vector(5, 6, 7);
	double *r = sub(p, v);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], -2);
	EXPECT_DOUBLE_EQ(r[1], -4);
	EXPECT_DOUBLE_EQ(r[2], -6);
	EXPECT_DOUBLE_EQ(r[3], 1);

	free(p);
	free(v);
	free(r);
}

TEST(OperationsTest, TestSubFunctionWith2Vec) {
	double *v1 = vector(3, 2, 1);
	double *v2 = vector(5, 6, 7);
	double *r = sub(v1, v2);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], -2);
	EXPECT_DOUBLE_EQ(r[1], -4);
	EXPECT_DOUBLE_EQ(r[2], -6);
	EXPECT_DOUBLE_EQ(r[3], 0);

	free(v1);
	free(v2);
	free(r);
}

TEST(OperationsTest, TestSubFunctionFromZeroVector){
	double *v1 = vector(0,0,0);
	double *v2 = vector(1, -2, 3);
	double *r = sub(v1, v2);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], -1);
	EXPECT_DOUBLE_EQ(r[1], 2);
	EXPECT_DOUBLE_EQ(r[2], -3);
	EXPECT_DOUBLE_EQ(r[3], 0);

	free(v1);
	free(v2);
	free(r);
}

TEST(OperationsTest, TestSubFunctionNegating){
	double *tp = negate(1, -2, 3, -4);

	ASSERT_NE(tp, nullptr);
	EXPECT_DOUBLE_EQ(tp[0], -1);
	EXPECT_DOUBLE_EQ(tp[1], 2);
	EXPECT_DOUBLE_EQ(tp[2], -3);
	EXPECT_DOUBLE_EQ(tp[3], 4);

	free(tp);
}

TEST(OperationsTest, TestSubFunctionNegatingVector){
	double *v = vector(1, -2, 3);
	double *nv = negate_vector(v);

	ASSERT_NE(nv, nullptr);
	EXPECT_DOUBLE_EQ(nv[0], -1);
	EXPECT_DOUBLE_EQ(nv[1], 2);
	EXPECT_DOUBLE_EQ(nv[2], -3);
	EXPECT_DOUBLE_EQ(nv[3], 0);

	free(v);
	free(nv);
}

TEST(OperationsTest, TestMultFunction){
	double *v = tuple(1, -2, 3, -4);
	double *r = multiplication(v, 3.5);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], 3.5);
	EXPECT_DOUBLE_EQ(r[1], -7);
	EXPECT_DOUBLE_EQ(r[2], 10.5);
	EXPECT_DOUBLE_EQ(r[3], -14);

	free(v);
	free(r);
}

TEST(OperationsTest, TestDivFunctionWithValidDividend){
	double *v = tuple(1, -2, 3, -4);
	double *r = division(v, 2);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], 0.5);
	EXPECT_DOUBLE_EQ(r[1], -1);
	EXPECT_DOUBLE_EQ(r[2], 1.5);
	EXPECT_DOUBLE_EQ(r[3], -2);

	free(v);
	free(r);
}

TEST(OperationsTest, TestDivFunctionWithInvalidDividend){
	double *v = tuple(1, -2, 3, -4);
	double *r = division(v, 0);

	ASSERT_EQ(r, nullptr);

	free(v);
}

TEST(OperationsTest, TestMagFunctionWithResOne){
	double *v1 = vector(1, 0, 0);
	double *v2 = vector(0, 1, 0);
	double *v3 = vector(0, 0, 1);
	double r1 = magnitude(v1);
	double r2 = magnitude(v2);
	double r3 = magnitude(v3);

	EXPECT_DOUBLE_EQ(r1, 1);
	EXPECT_DOUBLE_EQ(r2, 1);
	EXPECT_DOUBLE_EQ(r3, 1);

	free(v1);
	free(v2);
	free(v3);
}

TEST(OperationsTest, TestMagFunctionWithResDifThanOne){
	double *v1 = vector(1, 2, 3);
	double *v2 = vector(-1, -2, -3);
	double r1 = magnitude(v1);
	double r2 = magnitude(v2);

	EXPECT_DOUBLE_EQ(r1, sqrt(14));
	EXPECT_DOUBLE_EQ(r2, sqrt(14));

	free(v1);
	free(v2);
}

TEST(OperationsTest, TestNormFunction){
	double *v1 = vector(4, 0, 0);
	double *v2 = vector(1, 2, 3);
	double *r1 = norm(v1);
	double *r2 = norm(v2);

	ASSERT_NE(r1, nullptr);
	EXPECT_DOUBLE_EQ(r1[0], 1);
	EXPECT_DOUBLE_EQ(r1[1], 0);
	EXPECT_DOUBLE_EQ(r1[2], 0);
	ASSERT_NE(r2, nullptr);
	EXPECT_DOUBLE_EQ(r2[0], (1 / sqrt(14)));
	EXPECT_DOUBLE_EQ(r2[1], (2 / sqrt(14)));
	EXPECT_DOUBLE_EQ(r2[2], (3 / sqrt(14)));

	free(v1);
	free(r1);
	free(v2);
	free(r2);
}

TEST(OperationsTest, TestDotProductFunction){
	double *v1 = vector(1, 2, 3);
	double *v2 = vector(2, 3, 4);
	double r = dot_product(v1, v2);

	EXPECT_DOUBLE_EQ(r, 20);

	free(v1);
	free(v2);
}

TEST(OperationsTest, TestCrossProductFunction){
	double *v1 = vector(1, 2, 3);
	double *v2 = vector(2, 3, 4);
	double *r1 = cross_product(v1, v2);
	double *r2 = cross_product(v2, v1);

	ASSERT_NE(r1, nullptr);
	ASSERT_NE(r2, nullptr);

	EXPECT_DOUBLE_EQ(r1[0], -1);
	EXPECT_DOUBLE_EQ(r1[1], 2);
	EXPECT_DOUBLE_EQ(r1[2], -1);

	EXPECT_DOUBLE_EQ(r2[0], 1);
	EXPECT_DOUBLE_EQ(r2[1], -2);
	EXPECT_DOUBLE_EQ(r2[2], 1);

	free(v1);
	free(v2);
	free(r1);
	free(r2);
}
