// =========================================================
// File: testing_heavy.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 4/Jan/2022
// Description: This file contains the series of tests that
//							the HeavyContainer class must pass.
// To compile: g++ -std=c++11 testing_heavy.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../light.h"
#include "../heavy.h"

TEST_CASE("testing basic constructor with positive weight", "[HeavyContainer(id, weight)]") {
	HeavyContainer c1(1, 30000);

	REQUIRE(c1.getId() == 1);
	REQUIRE(c1.getWeight() == 30000);
  REQUIRE(c1.getType() == HEAVY);
}

TEST_CASE("testing copy constructor", "[HeavyContainer(const HeavyContainer&)]") {
	HeavyContainer c1(1, 30000);
	HeavyContainer c2(c1);

	REQUIRE(c2.getId() == 1);
	REQUIRE(c2.getWeight() == 30000);
  REQUIRE(c2.getType() == HEAVY);
}

TEST_CASE("testing getConsumption", "[getConsumption()]") {
	HeavyContainer c1(1, 1000);

	REQUIRE(c1.getConsumption() == 3000.0);
}

TEST_CASE("testing operator<", "[operator<]") {
	HeavyContainer c1(2, 30000);
	LightContainer c3(2, 30000);
	LightContainer *c4 = new LightContainer(2, 30000);
	bool result;

	result = (c1 < c3);
	REQUIRE(result == false);
	result = (c3 < c1);
	REQUIRE(result == true);
	result = (c1 < c4);
	REQUIRE(result == false);

	delete c4;
}
