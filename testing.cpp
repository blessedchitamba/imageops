//unit tests for the imageops methods of all its associated classes


#define CATCH_CONFIG_MAIN
#include "Image.h"
#include "catch.hpp"

using namespace chtble001;
using namespace std;

//create test arrays to represent images
unsigned char data1[] = { 1, 30, 125, 7, 23, 255, 74, 2};
unsigned char data2[] = { 0, 10, 77, 30, 255, 197, 200, 253};

//first test the iterators to see if they behave
TEST_CASE("Iterator Class Testing")
{
	Image image1(data1, 2, 4);
	auto iterator = image1.begin();

	SECTION("* operator test")
	{
		REQUIRE(*iterator == 1);
	}

	SECTION("Begin and End methods test")
	{
		auto beg = image1.begin();
		auto end = image1.end();

		REQUIRE(*beg == 1);
		REQUIRE(*end == 2);
	}

	SECTION("= Operator test")
	{
		auto iterator2 = iterator;
		REQUIRE(*iterator == *iterator2);
		++iterator;
		++iterator;
		REQUIRE(*iterator != *iterator2);
	}

	SECTION("prefix ++ Operator test")
	{
		REQUIRE(*iterator == 1);
		++iterator;
		REQUIRE(*iterator == 30);
		++iterator;
		REQUIRE(*it == 125);
	}

	SECTION("prefix -- Operator test")
	{
		REQUIRE(*iterator == 1);
		++iterator;
		++iterator;
		++iterator;
		--iterator;
		REQUIRE(*iterator == 125);
		--iterator;
		REQUIRE(*iterator == 30);

	}



}

TEST_CASE("Copy and Move operations for the Image class")
{
	Image image1(data1, 2, 4);
	SECTION("Copy Constructor")
	{
		Image image2(image1);
		auto iterator = image1.begin();
		auto iterator2 = image2.begin();

		REQUIRE(*iterator == *iterator2);

	}

	SECTION("Move Constructor test")
	{
		Image image2(image1);
		Image image3(move(image1));
		auto iterator = image2.begin();
		auto iterator2 = image3.begin();
		REQUIRE(*iterator == *iterator2);

	}

}

//testing the overloaded operators now
TEST_CASE("Image Operators")
{
	Image image1(data1, 2, 4);
	Image image2(data2, 2, 4);
	Image result;
	SECTION("+ operator for adding")
	{
		result = image1+image2;
		auto iterator = result.begin();
		REQUIRE(*iterator == (data1[0] + data2[0]));
		++iterator;
		REQUIRE(*iterator == (data1[1] + data2[1]));
	}

	SECTION("- operator for subtracting")
	{
		result = image1-image2;
		auto iterator = result.begin();
		REQUIRE(*iterator == (data1[0] - data2[0]));
		++iterator;
		REQUIRE(*iterator == (data1[1] - data2[1]));
	}

	SECTION("! operator for inverting")
	{
		result = !image1;
		auto iterator = result.begin();
		REQUIRE(*iterator == 255 - data1[0]);
		++iterator;
		REQUIRE(*iterator == 255 - data1[1]);

	}
	SECTION("* operator for thresholding")
	{
		result = image1 * 55;
		auto iterator = result.begin();
		REQUIRE(*iterator == 0);
		++iterator;
		++iterator;
		REQUIRE(*iterator == 255);
	}
	SECTION("/ operator for masking")
	{
		result = image1 / image2;
		auto iterator = result.begin();
		++iterator;
		REQUIRE(*iterator == data2[1]);
		++iterator;
		++iterator;
		++iterator;
		//since arr1[3] is 255 arr[3] is copied across to arr1[3];
		REQUIRE(*iterator == data1[4]);

	}


}

