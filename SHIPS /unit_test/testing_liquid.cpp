// =========================================================
// File: testing_liquid.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 4/Jan/2022
// Description: This file contains the series of tests that
//							the LiquidContainer class must pass.
// To compile: g++ -std=c++11 testing_liquid.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../liquid.h"

TEST_CASE("testing basic constructor with positive weight", "[LiquidContainer(id, weight)]") {
	LiquidContainer c1(1, 30000);

	REQUIRE(c1.getId() == 1);
	REQUIRE(c1.getWeight() == 30000);
  REQUIRE(c1.getType() == LIQUID);
}

TEST_CASE("testing copy constructor", "[LiquidContainer(const LiquidContainer&)]") {
	LiquidContainer c1(1, 30000);
	LiquidContainer c2(c1);

	REQUIRE(c2.getId() == 1);
	REQUIRE(c2.getWeight() == 30000);
  REQUIRE(c2.getType() == LIQUID);
}

TEST_CASE("testing getConsumption", "[getConsumption()]") {
	LiquidContainer c1(1, 1000);

	REQUIRE(c1.getConsumption() == 4000.0);
}
