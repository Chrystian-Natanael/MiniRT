#include <gtest/gtest.h>
#include <cstdlib>

extern "C" {
	#include "Tuples.h"
}

TEST(PointAndVectorTest, TestPointFunction) {
	double *p = point(1.0, 2.0, 3.0);
	
	ASSERT_NE(p, nullptr);
	EXPECT_DOUBLE_EQ(p[0], 2.0);
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
