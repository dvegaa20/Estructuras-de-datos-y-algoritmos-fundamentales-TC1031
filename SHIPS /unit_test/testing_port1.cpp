// =========================================================
// File: testing_port1.cpp
// Author: Dr. Pedro O. Perez-Murueta
// Date: 4/Jan/2022
// Description: This file contains the series of tests that
//							the Port class must pass.
// IMPORTANT: This file must be used BEFORE the
// testing of Ship class.
// To compile: g++ -std=c++11 testing_port1.cpp -o app
// To execute: ./app
// =========================================================
#define CATCH_CONFIG_MAIN
#include <string>
#include "catch.h"
#include "../light.h"
#include "../port.h"

TEST_CASE("testing basic constructor with position", "[Port(double, double)]") {
	Port p(1, 1, 1);

	REQUIRE(p.getId() == 1);
	REQUIRE(p.getX() == 1.0);
	REQUIRE(p.getY() == 1.0);
	REQUIRE(p.getContainers().empty() == true);
	REQUIRE(p.getHistory().empty() == true);
	REQUIRE(p.getCurrent().empty() == true);
}

TEST_CASE("testing copy constructor", "[Port(const Port&)]") {
	Port p1(1, 1, 1);
	Port p2(p1);

	REQUIRE(p2.getId() == 1);
	REQUIRE(p2.getX() == 1.0);
	REQUIRE(p2.getY() == 1.0);
	REQUIRE(p2.getContainers().empty() == true);
	REQUIRE(p2.getHistory().empty() == true);
	REQUIRE(p2.getCurrent().empty() == true);
}

TEST_CASE("testing getDistance", "[getDistance(Port*)]") {
	Port p1(1, 1, 1);
	Port *p2 = new Port(2, 4, 5);

	REQUIRE(p1.getDistance(p2) == 5.0);

	delete p2;
}

TEST_CASE("testing add", "[add(Container*)]") {
	Port p(1, 1, 1);
	LightContainer *c1 = new LightContainer(1, 300);
	bool result;

	p.add(c1);
	REQUIRE(p.getContainers().size() == 1);
	result = (p.getContainers().back() == c1);
	REQUIRE(result == true);
}

TEST_CASE("testing contains", "[contains(Container*)]") {
	Port p(1, 1, 1);
	LightContainer *c1 = new LightContainer(1, 300);
	LightContainer *c2 = new LightContainer(2, 300);
	LightContainer *c3 = new LightContainer(3, 300);
	bool result;

	p.add(c1);
	p.add(c2);
	p.add(c3);
	REQUIRE(p.getContainers().size() == 3);
	REQUIRE(p.contains(c2) == true);

	delete c1;
	delete c2;
	delete c3;
}

TEST_CASE("testing remove", "[remove(Container*)]") {
	Port p(1, 1, 1);
	LightContainer *c1 = new LightContainer(1, 300);
	LightContainer *c2 = new LightContainer(2, 300);
	LightContainer *c3 = new LightContainer(3, 300);
	bool result;

	p.add(c1);
	p.add(c2);
	p.add(c3);
	p.remove(c2);
	REQUIRE(p.getContainers().size() == 2);
	REQUIRE(p.contains(c2) == false);

	delete c1;
	delete c2;
	delete c3;
}
