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