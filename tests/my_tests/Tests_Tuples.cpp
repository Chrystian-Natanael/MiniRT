#include <gtest/gtest.h>
#include <cstdlib>

extern "C" {
	#include "Tuples.h"
}

TEST(PointAndVectorTest, TestPointFunction) {
	init_pools();
	double *p = point(1.0, 2.0, 3.0);

	ASSERT_NE(p, nullptr);
	EXPECT_DOUBLE_EQ(p[0], 1.0);
	EXPECT_DOUBLE_EQ(p[1], 2.0);
	EXPECT_DOUBLE_EQ(p[2], 3.0);
	EXPECT_EQ(static_cast<int>(p[3]), POINT);

}

TEST(PointAndVectorTest, TestVectorFunction) {
	init_pools();
	double *v = vector(4.0, 5.0, 6.0);

	ASSERT_NE(v, nullptr);
	EXPECT_DOUBLE_EQ(v[0], 4.0);
	EXPECT_DOUBLE_EQ(v[1], 5.0);
	EXPECT_DOUBLE_EQ(v[2], 6.0);
	EXPECT_EQ(static_cast<int>(v[3]), VECTOR);

}

TEST(PointAndVectorTest, TestEqualFunction) {
	init_pools();
	double x = (1.100);
	EXPECT_TRUE(equal(x, 1.100005));
	EXPECT_FALSE(equal(x, 1.105));
}

TEST(OperationsTest, TestSumFunction) {
	init_pools();
	double *p1 = point(3, -2, 5);
	double *v = vector(-2, 3, 1);
	double *r = sum(p1, v);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], 1);
	EXPECT_DOUBLE_EQ(r[1], 1);
	EXPECT_DOUBLE_EQ(r[2], 6);
	EXPECT_DOUBLE_EQ(r[3], 1);

}

TEST(OperationsTest, TestSubFunctionWith2Pts) {
	init_pools();
	double *p1 = point(3, 2, 1);
	double *p2 = point(5, 6, 7);
	double *r = sub(p1, p2);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], -2);
	EXPECT_DOUBLE_EQ(r[1], -4);
	EXPECT_DOUBLE_EQ(r[2], -6);
	EXPECT_DOUBLE_EQ(r[3], 0);

}

TEST(OperationsTest, TestSubFunctionWithPtAndVec) {
	init_pools();
	double *p = point(3, 2, 1);
	double *v = vector(5, 6, 7);
	double *r = sub(p, v);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], -2);
	EXPECT_DOUBLE_EQ(r[1], -4);
	EXPECT_DOUBLE_EQ(r[2], -6);
	EXPECT_DOUBLE_EQ(r[3], 1);

}

TEST(OperationsTest, TestSubFunctionWith2Vec) {
	init_pools();
	double *v1 = vector(3, 2, 1);
	double *v2 = vector(5, 6, 7);
	double *r = sub(v1, v2);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], -2);
	EXPECT_DOUBLE_EQ(r[1], -4);
	EXPECT_DOUBLE_EQ(r[2], -6);
	EXPECT_DOUBLE_EQ(r[3], 0);

}

TEST(OperationsTest, TestSubFunctionFromZeroVector){
	init_pools();
	double *v1 = vector(0,0,0);
	double *v2 = vector(1, -2, 3);
	double *r = sub(v1, v2);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], -1);
	EXPECT_DOUBLE_EQ(r[1], 2);
	EXPECT_DOUBLE_EQ(r[2], -3);
	EXPECT_DOUBLE_EQ(r[3], 0);

}

TEST(OperationsTest, TestSubFunctionNegating){
	init_pools();
	double *tp = negate(1, -2, 3, -4);

	ASSERT_NE(tp, nullptr);
	EXPECT_DOUBLE_EQ(tp[0], -1);
	EXPECT_DOUBLE_EQ(tp[1], 2);
	EXPECT_DOUBLE_EQ(tp[2], -3);
	EXPECT_DOUBLE_EQ(tp[3], 4);

}

TEST(OperationsTest, TestSubFunctionNegatingVector){
	init_pools();
	double *v = vector(1, -2, 3);
	double *nv = negate_vector(v);

	ASSERT_NE(nv, nullptr);
	EXPECT_DOUBLE_EQ(nv[0], -1);
	EXPECT_DOUBLE_EQ(nv[1], 2);
	EXPECT_DOUBLE_EQ(nv[2], -3);
	EXPECT_DOUBLE_EQ(nv[3], 0);

}

TEST(OperationsTest, TestMultFunction){
	init_pools();
	double *v = create_tp(1, -2, 3, -4);
	double *r = multiply(v, 3.5);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], 3.5);
	EXPECT_DOUBLE_EQ(r[1], -7);
	EXPECT_DOUBLE_EQ(r[2], 10.5);
	EXPECT_DOUBLE_EQ(r[3], -14);

}

TEST(OperationsTest, TestDivFunctionWithValidDividend){
	init_pools();
	double *v = create_tp(1, -2, 3, -4);
	double *r = division(v, 2);

	ASSERT_NE(r, nullptr);
	EXPECT_DOUBLE_EQ(r[0], 0.5);
	EXPECT_DOUBLE_EQ(r[1], -1);
	EXPECT_DOUBLE_EQ(r[2], 1.5);
	EXPECT_DOUBLE_EQ(r[3], -2);

}

TEST(OperationsTest, TestDivFunctionWithInvalidDividend){
	init_pools();
	double *v = create_tp(1, -2, 3, -4);
	double *r = division(v, 0);

	ASSERT_EQ(r, nullptr);

}

TEST(OperationsTest, TestMagFunctionWithResOne){
	init_pools();
	double *v1 = vector(1, 0, 0);
	double *v2 = vector(0, 1, 0);
	double *v3 = vector(0, 0, 1);
	double r1 = mag(v1);
	double r2 = mag(v2);
	double r3 = mag(v3);

	EXPECT_DOUBLE_EQ(r1, 1);
	EXPECT_DOUBLE_EQ(r2, 1);
	EXPECT_DOUBLE_EQ(r3, 1);

}

TEST(OperationsTest, TestMagFunctionWithResDifThanOne){
	init_pools();
	double *v1 = vector(1, 2, 3);
	double *v2 = vector(-1, -2, -3);
	double r1 = mag(v1);
	double r2 = mag(v2);

	EXPECT_DOUBLE_EQ(r1, sqrt(14));
	EXPECT_DOUBLE_EQ(r2, sqrt(14));

}

TEST(OperationsTest, TestNormFunction){
	init_pools();
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

}

TEST(OperationsTest, TestDotProductFunction){
	init_pools();
	double *v1 = vector(1, 2, 3);
	double *v2 = vector(2, 3, 4);
	double r = dot_prod(v1, v2);

	EXPECT_DOUBLE_EQ(r, 20);

}

TEST(OperationsTest, TestCrossProductFunction){
	init_pools();
	double *v1 = vector(1, 2, 3);
	double *v2 = vector(2, 3, 4);
	double *r1 = cross_prod(v1, v2);
	double *r2 = cross_prod(v2, v1);

	ASSERT_NE(r1, nullptr);
	ASSERT_NE(r2, nullptr);

	EXPECT_DOUBLE_EQ(r1[0], -1);
	EXPECT_DOUBLE_EQ(r1[1], 2);
	EXPECT_DOUBLE_EQ(r1[2], -1);

	EXPECT_DOUBLE_EQ(r2[0], 1);
	EXPECT_DOUBLE_EQ(r2[1], -2);
	EXPECT_DOUBLE_EQ(r2[2], 1);

}
