// =========================================================
// File: testing_port2.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 4/Jan/2022
// Description: This file contains the series of tests that
//							the Port class must pass.
// IMPORTANT: This file must be used AFTER the
// testing of Ship class.
// To compile: g++ -std=c++11 testing_port2.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../light.h"
#include "../port.h"
#include "../ship.h"

TEST_CASE("testing incomingShip", "[incomingShip(SimpleShip*)]") {
	Port p1(1, 1, 1);
	Port p2(2, 4, 5);
	Ship *s2 = new Ship(2, &p2, 100, 4, 1, 1, 1, 10);
	bool result;

	p1.incomingShip(s2);
	REQUIRE(p1.getCurrent().size() == 1);
	result = (p1.getCurrent().back() == s2);
	REQUIRE(result == true);
	delete s2;
}

TEST_CASE("testing outgoingShip", "[outgoingShip(SimpleShip*)]") {
	Port p1(1, 1, 1);
	Port p2(2, 4, 5);
	Ship *s1 = new Ship(1, &p2, 100, 4, 1, 1, 1, 10);
	Ship *s2 = new Ship(2, &p2, 100, 4, 1, 1, 1, 10);
	bool result;

	p1.incomingShip(s1);
	p1.outgoingShip(s1);
	REQUIRE(p1.getCurrent().size() == 0);
	REQUIRE(p1.getHistory().size() == 1);
	result = (p1.getHistory().back() == s1);
	REQUIRE(result == true);

	p1.outgoingShip(s2);
	REQUIRE(p1.getCurrent().size() == 0);
	REQUIRE(p1.getHistory().size() == 1);
	result = (p1.getHistory().back() == s2);
	REQUIRE(result == false);

	p1.incomingShip(s1);
	p1.outgoingShip(s1);
	REQUIRE(p1.getCurrent().size() == 0);
	REQUIRE(p1.getHistory().size() == 1);

	delete s1;
	delete s2;
}
