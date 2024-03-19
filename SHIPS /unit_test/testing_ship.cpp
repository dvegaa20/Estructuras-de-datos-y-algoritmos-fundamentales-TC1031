// =========================================================
// File: testing_ship.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 4/Jan/2022
// Description: This file contains the series of tests that
//							the Ship class must pass.
// IMPORTANT: This file must be used BEFORE the
// testing of Ship class.
// To compile: g++ -std=c++11 testing_ship.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../light.h"
#include "../heavy.h"
#include "../refrigerated.h"
#include "../liquid.h"
#include "../port.h"
#include "../ship.h"

TEST_CASE("testing basic constructor", "[Ship(int, Port*, int, int, int, int, int, double)]") {
	Port p1(1, 1, 1);
	Ship s1(1, &p1, 100, 4, 1, 1, 1, 10);
	bool result;

	REQUIRE(s1.getId() == 1);
	REQUIRE(s1.getCurrentWeight() == 0.0);
	REQUIRE(s1.getTotalWeight() == 100.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 0);
	REQUIRE(s1.getMaxNumberOfAllContainers() == 4);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 0);
	REQUIRE(s1.getMaxNumberOfHeavyContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 0);
	REQUIRE(s1.getMaxNumberOfRefrigeratedContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 0);
	REQUIRE(s1.getMaxNumberOfLiquidContainers() == 1);
	REQUIRE(s1.getFuel() == 0.0);
	REQUIRE(s1.getFuelConsumptionPerKM() == 10.0);
	result = (p1.getId() == s1.getCurrentPort()->getId() &&
						p1.getX() == s1.getCurrentPort()->getX() &&
						p1.getY() == s1.getCurrentPort()->getY());
	REQUIRE(result == true);
	REQUIRE(s1.getCurrentContainers().empty() == true);
}

TEST_CASE("testing copy constructor", "[Port(const Port&)]") {
	Port p1(1, 1, 1);
	Ship s2(1, &p1, 100, 4, 1, 1, 1, 10);
	Ship s1(s2);
	bool result;

	REQUIRE(s1.getId() == 1);
	REQUIRE(s1.getCurrentWeight() == 0.0);
	REQUIRE(s1.getTotalWeight() == 100.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 0);
	REQUIRE(s1.getMaxNumberOfAllContainers() == 4);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 0);
	REQUIRE(s1.getMaxNumberOfHeavyContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 0);
	REQUIRE(s1.getMaxNumberOfRefrigeratedContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 0);
	REQUIRE(s1.getMaxNumberOfLiquidContainers() == 1);
	REQUIRE(s1.getFuel() == 0.0);
	REQUIRE(s1.getFuelConsumptionPerKM() == 10.0);
	result = (p1.getId() == s1.getCurrentPort()->getId() &&
						p1.getX() == s1.getCurrentPort()->getX() &&
						p1.getY() == s1.getCurrentPort()->getY());
	REQUIRE(result == true);
	REQUIRE(s1.getCurrentContainers().empty() == true);
}

TEST_CASE("testing reFuel", "[reFuel(double)]") {
	Port p1(1, 1, 1);
	Ship s1(1, &p1, 100, 4, 1, 1, 1, 10);

	s1.reFuel(-100);
	REQUIRE(s1.getFuel() == 0);
	s1.reFuel(10000);
	REQUIRE(s1.getFuel() == 10000);
}

TEST_CASE("testing load", "[load(Container*)]") {
	Port p1(1, 1, 1);
	Ship s1(1, &p1, 17500.0, 4, 1, 1, 1, 10);
	LightContainer c1(1, 3000);
	HeavyContainer c2(1, 3500);
	RefrigeratedContainer c3(1, 3500);
	LiquidContainer c4(1, 3500);
	LightContainer c5(1, 3000);
	HeavyContainer c6(1, 3500);
	RefrigeratedContainer c7(1, 3500);
	LiquidContainer c8(1, 3500);
	bool result;

	p1.add(&c2); p1.add(&c3); p1.add(&c4);

	result = s1.load(&c1);
	REQUIRE(result == false);
	REQUIRE(s1.getCurrentWeight() == 0.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 0);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 0);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 0);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 0);
	REQUIRE(s1.getCurrentContainers().size() == 0);

	result = s1.load(&c2);
	REQUIRE(result == true);
	REQUIRE(s1.getCurrentWeight() == 3500.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 0);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 0);
	REQUIRE(s1.getCurrentContainers().size() == 1);

	result = s1.load(&c3);
	REQUIRE(result == true);
	REQUIRE(s1.getCurrentWeight() == 7000.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 2);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 0);
	REQUIRE(s1.getCurrentContainers().size() == 2);

	result = s1.load(&c4);
	REQUIRE(result == true);
	REQUIRE(s1.getCurrentWeight() == 10500.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 3);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 1);
	REQUIRE(s1.getCurrentContainers().size() == 3);

	p1.add(&c1); p1.add(&c5); p1.add(&c6); p1.add(&c7); p1.add(&c8);
	s1.load(&c1);

	result = s1.load(&c5);
	REQUIRE(result == false);
	REQUIRE(s1.getCurrentWeight() == 13500.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 4);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 1);
	REQUIRE(s1.getCurrentContainers().size() == 4);

	result = s1.load(&c6);
	REQUIRE(result == false);
	REQUIRE(s1.getCurrentWeight() == 13500.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 4);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 1);
	REQUIRE(s1.getCurrentContainers().size() == 4);

	result = s1.load(&c7);
	REQUIRE(result == false);
	REQUIRE(s1.getCurrentWeight() == 13500.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 4);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 1);
	REQUIRE(s1.getCurrentContainers().size() == 4);

	result = s1.load(&c8);
	REQUIRE(result == false);
	REQUIRE(s1.getCurrentWeight() == 13500.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 4);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 1);
	REQUIRE(s1.getCurrentContainers().size() == 4);
}

TEST_CASE("testing unLoad", "[unLoad(Container*)]") {
	Port p1(1, 1, 1);
	Ship s1(1, &p1, 17500.0, 4, 1, 1, 1, 10);
	LightContainer c1(1, 3000);
	HeavyContainer c2(1, 3500);
	RefrigeratedContainer c3(1, 3500);
	LiquidContainer c4(1, 3500);
	LightContainer c5(1, 3000);
	HeavyContainer c6(1, 3500);
	RefrigeratedContainer c7(1, 3500);
	LiquidContainer c8(1, 3500);
	bool result;

	p1.add(&c1); p1.add(&c2); p1.add(&c3); p1.add(&c4);
	p1.add(&c5); p1.add(&c6); p1.add(&c7); p1.add(&c8);
	s1.load(&c1); s1.load(&c2); s1.load(&c3); s1.load(&c4);

	result = s1.unLoad(&c8);
	REQUIRE(result == false);
	REQUIRE(s1.getCurrentWeight() == 13500.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 4);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 1);
	REQUIRE(s1.getCurrentContainers().size() == 4);

	result = s1.unLoad(&c2);
	REQUIRE(result == true);
	REQUIRE(s1.getCurrentWeight() == 10000.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 3);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 0);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 1);
	REQUIRE(s1.getCurrentContainers().size() == 3);

	result = s1.unLoad(&c4);
	REQUIRE(result == true);
	REQUIRE(s1.getCurrentWeight() == 6500.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 2);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 0);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 0);
	REQUIRE(s1.getCurrentContainers().size() == 2);

	result = s1.unLoad(&c3);
	REQUIRE(result == true);
	REQUIRE(s1.getCurrentWeight() == 3000.0);
	REQUIRE(s1.getCurrentNumberOfAllContainers() == 1);
	REQUIRE(s1.getCurrentNumberOfHeavyContainers() == 0);
	REQUIRE(s1.getCurrentNumberOfRefrigeratedContainers() == 0);
	REQUIRE(s1.getCurrentNumberOfLiquidContainers() == 0);
	REQUIRE(s1.getCurrentContainers().size() == 1);
}

TEST_CASE("testing sailTo", "[sailTo(Port*)]") {
	Port p1(1, 1, 1);
	Port p2(2, 4, 5);
	Ship s1(1, &p1, 17500.0, 4, 1, 1, 1, 10);
	LightContainer c1(1, 3000);
	HeavyContainer c2(2, 3500);
	RefrigeratedContainer c3(3, 3500);
	LiquidContainer c4(4, 3500);
	bool result;

	p1.add(&c1); p1.add(&c2); p1.add(&c3); p1.add(&c4);
	s1.load(&c1); s1.load(&c2); s1.load(&c3); s1.load(&c4);

	result = s1.sailTo(&p2);
	REQUIRE(result == false);

	s1.reFuel(1000000);
	result = s1.sailTo(&p2);
	REQUIRE(result == true);
	REQUIRE(s1.getFuel() == 950450.0);
	result = (p2.getId() == s1.getCurrentPort()->getId() &&
						p2.getX() == s1.getCurrentPort()->getX() &&
						p2.getY() == s1.getCurrentPort()->getY());
	REQUIRE(result == true);
}
