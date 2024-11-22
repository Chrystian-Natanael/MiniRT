#include <gtest/gtest.h>
#include <cmath>

extern "C" {
	#include "Utils.h"
}

TEST(DoubleToIntTest, PositiveValues) {
	EXPECT_EQ(dtoi(2.3), 2);
	EXPECT_EQ(dtoi(2.5), 3);
	EXPECT_EQ(dtoi(2.7), 3);
}

TEST(DoubleToIntTest, NegativeValues) {
	EXPECT_EQ(dtoi(-2.3), -2);
	EXPECT_EQ(dtoi(-2.5), -3);
	EXPECT_EQ(dtoi(-2.7), -3);
}

TEST(DoubleToIntTest, ZeroValue) {
	EXPECT_EQ(dtoi(0.0), 0);
}

TEST(DoubleToIntTest, BoundaryValues) {
	EXPECT_EQ(dtoi(1.499999), 1);
	EXPECT_EQ(dtoi(1.500001), 2);
	EXPECT_EQ(dtoi(-1.499999), -1);
	EXPECT_EQ(dtoi(-1.500001), -2);
}
