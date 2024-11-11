#include <gtest/gtest.h>
#include <cstdlib>

extern "C" {
	#include "Colors.h"
	#include "Tuples.h"
	#include <stdint.h>
}

TEST(OperationColors, CreateColors) {
	t_colors *c1 = create_color(0.9, 0.6, 0.75);

	ASSERT_NE(c1, nullptr);
	EXPECT_EQ(c1->red, 0.9);
	EXPECT_EQ(c1->green, 0.6);
	EXPECT_EQ(c1->blue, 0.75);
	free(c1);
}

TEST(OperationColors, AdditionColors) {
	t_colors *c1 = create_color(0.9, 0.6, 0.75);
	t_colors *c2 = create_color(0.7, 0.1, 0.25);
	t_colors *res = sum_colors(c1, c2);

	ASSERT_NE(res, nullptr);
	EXPECT_EQ(res->red, 1.6);
	EXPECT_EQ(res->green, 0.7);
	EXPECT_EQ(res->blue, 1.0);
	free(c1);
	free(c2);
	free(res);
}

TEST(OperationColors, SubtractionColors) {
	t_colors *c1 = create_color(0.9, 0.6, 0.75);
	t_colors *c2 = create_color(0.7, 0.1, 0.25);
	t_colors *res = sub_colors(c1, c2);

	ASSERT_NE(res, nullptr);
	EXPECT_TRUE(equal(res->red, 0.2));
	EXPECT_EQ(res->green, 0.5);
	EXPECT_EQ(res->blue, 0.5);
	free(c1);
	free(c2);
	free(res);
}

TEST(OperationColors, MultiplicationColors) {
	t_colors *c = create_color(0.2, 0.3, 0.4);
	t_colors *res = multiplication_colors(c, 2);

	ASSERT_NE(res, nullptr);
	EXPECT_EQ(res->red, 0.4);
	EXPECT_EQ(res->green, 0.6);
	EXPECT_EQ(res->blue, 0.8);
	free(c);
	free(res);
}

TEST(OperationColors, HadaColors) {
	t_colors *c1 = create_color(1, 0.2, 0.4);
	t_colors *c2 = create_color(0.9, 1, 0.1);
	t_colors *res = hada_prd_colors(c1, c2);

	ASSERT_NE(res, nullptr);
	EXPECT_EQ(res->red, 0.9);
	EXPECT_EQ(res->green, 0.2);
	EXPECT_TRUE(equal(res->blue, 0.04));
	free(c1);
	free(c2);
	free(res);
}

TEST(OperationColors, HadaColorsOtherValues) {
	t_colors *c1 = create_color(2, 0.2, 0.4);
	t_colors *c2 = create_color(0.9, 2, 0.2);
	t_colors *res = hada_prd_colors(c1, c2);

	ASSERT_NE(res, nullptr);
	EXPECT_EQ(res->red, 1.8);
	EXPECT_EQ(res->green, 0.4);
	EXPECT_TRUE(equal(res->blue, 0.08));
	free(c1);
	free(c2);
	free(res);
}

TEST(OperationColors, ConvertRGBToHexa) {
	t_colors *c = create_color(1, 0, 0);
	uint32_t res = rgb_to_hexa(*c);

	EXPECT_EQ(res, 0xFFFF00F0);
	free(c);
}
