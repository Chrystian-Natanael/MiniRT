#include <gtest/gtest.h>
#include <cstdlib>

extern "C"
{
#include "Colors.h"
#include "Tuples.h"
#include <stdint.h>
}

class FixtureColor : public ::testing::Test
{
protected:
	t_pool_set *set;

	void SetUp() override
	{
		set = get_pool();
		set->the_pool = create_pool(500000);
	}

	void TearDown() override
	{
		deallocate(set->the_pool);
	}
};

TEST_F(FixtureColor, OpCol_CreateColors)
{
	t_colors c1 = create_color(0.9, 0.6, 0.75);

	EXPECT_EQ(c1.red, 0.9);
	EXPECT_EQ(c1.green, 0.6);
	EXPECT_EQ(c1.blue, 0.75);
}

TEST_F(FixtureColor, OpCol_AdditionColors)
{
	t_colors c1 = create_color(0.9, 0.6, 0.75);
	t_colors c2 = create_color(0.7, 0.1, 0.25);
	t_colors res = sum_colors(c1, c2);

	EXPECT_EQ(res.red, 1.6);
	EXPECT_EQ(res.green, 0.7);
	EXPECT_EQ(res.blue, 1.0);
}

TEST_F(FixtureColor, OpCol_SubtractionColors)
{
	t_colors c1 = create_color(0.9, 0.6, 0.75);
	t_colors c2 = create_color(0.7, 0.1, 0.25);
	t_colors res = sub_colors(c1, c2);

	EXPECT_TRUE(equal(res.red, 0.2));
	EXPECT_EQ(res.green, 0.5);
	EXPECT_EQ(res.blue, 0.5);
}

TEST_F(FixtureColor, OpCol_MultiplicationColors)
{
	t_colors c = create_color(0.2, 0.3, 0.4);
	t_colors res = multiply_col(c, 2);

	EXPECT_EQ(res.red, 0.4);
	EXPECT_EQ(res.green, 0.6);
	EXPECT_EQ(res.blue, 0.8);
}

TEST_F(FixtureColor, OpCol_HadaColors)
{
	t_colors c1 = create_color(1, 0.2, 0.4);
	t_colors c2 = create_color(0.9, 1, 0.1);
	t_colors res = hada_col(c1, c2);

	EXPECT_EQ(res.red, 0.9);
	EXPECT_EQ(res.green, 0.2);
	EXPECT_TRUE(equal(res.blue, 0.04));
}

TEST_F(FixtureColor, OpCol_HadaColorsOtherValues)
{
	t_colors c1 = create_color(2, 0.2, 0.4);
	t_colors c2 = create_color(0.9, 2, 0.2);
	t_colors res = hada_col(c1, c2);

	EXPECT_EQ(res.red, 1.8);
	EXPECT_EQ(res.green, 0.4);
	EXPECT_TRUE(equal(res.blue, 0.08));
}

TEST_F(FixtureColor, OpCol_ConvertRGBToHexa)
{
	t_colors c = create_color(1, 0, 0);
	uint32_t res = rgb2hex(c);

	EXPECT_EQ(res, 0xFF0000FF);
}
