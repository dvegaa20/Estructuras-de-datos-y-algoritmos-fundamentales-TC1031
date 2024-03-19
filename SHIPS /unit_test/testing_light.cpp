// =========================================================
// File: testing_light.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 4/Jan/2022
// Description: This file contains the series of tests that
//							the LightContainer class must pass.
// To compile: g++ -std=c++11 testing_light.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../light.h"

TEST_CASE("testing basic constructor with positive weight", "[LightContainer(id, weight)]") {
	LightContainer c1(1, 300);

	REQUIRE(c1.getId() == 1);
	REQUIRE(c1.getWeight() == 300);
  REQUIRE(c1.getType() == LIGHT);
}

TEST_CASE("testing basic constructor with negative weight", "[LightContainer(id, weight)]") {
	LightContainer c1(1, -300);

	REQUIRE(c1.getId() == 1);
	REQUIRE(c1.getWeight() == 0);
  REQUIRE(c1.getType() == LIGHT);
}

TEST_CASE("testing copy constructor", "[LightContainer(const LightContainer&)]") {
	LightContainer c1(1, 300);
	LightContainer c2(c1);

	REQUIRE(c2.getId() == 1);
	REQUIRE(c2.getWeight() == 300);
  REQUIRE(c2.getType() == LIGHT);
}

TEST_CASE("testing getConsumption", "[getConsumption()]") {
	LightContainer c1(1, 1000);

	REQUIRE(c1.getConsumption() == 2500.0);
}

TEST_CASE("testing operator==", "[operator==]") {
	LightContainer c1(1, 300);
	LightContainer c2(c1);
	LightContainer c3(1, 301);
	LightContainer *c4 = new LightContainer(1, 300);
	LightContainer *c5 = new LightContainer(1, 301);
	bool result;

	result = (c1 == c2);
	REQUIRE(result == true);
	result = (c1 == c3);
	REQUIRE(result == false);
	result = (c1 == c4);
	REQUIRE(result == true);
	result = (c1 == c5);
	REQUIRE(result == false);

	delete c4;
	delete c5;
}

TEST_CASE("testing operator<", "[operator<]") {
	LightContainer c1(2, 300);
	LightContainer c2(c1);
	LightContainer c3(3, 300);
	LightContainer *c4 = new LightContainer(1, 400);
	bool result;

	result = (c1 < c2);
	REQUIRE(result == false);
	result = (c2 < c1);
	REQUIRE(result == false);
	result = (c1 < c3);
	REQUIRE(result == true);
	result = (c3 < c1);
	REQUIRE(result == false);
	result = (c1 < c4);
	REQUIRE(result == false);

	delete c4;
}
