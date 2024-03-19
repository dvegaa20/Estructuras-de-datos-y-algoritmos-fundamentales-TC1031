// =========================================================
// File: testing_refrigerated.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 4/Jan/2022
// Description: This file contains the series of tests that
//							the RefrigeratedContainer class must pass.
// To compile: g++ -std=c++11 testing_refrigerated.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../refrigerated.h"

TEST_CASE("testing basic constructor with positive weight", "[RefrigeratedContainer(id, weight)]") {
	RefrigeratedContainer c1(1, 30000);

	REQUIRE(c1.getId() == 1);
	REQUIRE(c1.getWeight() == 30000);
  REQUIRE(c1.getType() == REFRIGERATED);
}

TEST_CASE("testing copy constructor", "[RefrigeratedContainer(const RefrigeratedContainer&)]") {
	RefrigeratedContainer c1(1, 30000);
	RefrigeratedContainer c2(c1);

	REQUIRE(c2.getId() == 1);
	REQUIRE(c2.getWeight() == 30000);
  REQUIRE(c2.getType() == REFRIGERATED);
}

TEST_CASE("testing getConsumption", "[getConsumption()]") {
	RefrigeratedContainer c1(1, 1000);

	REQUIRE(c1.getConsumption() == 5000.0);
}
