// =========================================================
// File: port.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef PORT_H
#define PORT_H

#include <list>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include "container.h"
#include "simpleship.h"

class Port {
private:
  int id;
  double x, y;
  std::list<Container*> containers;
  std::list<SimpleShip*> history;
  std::list<SimpleShip*> current;

public:
  Port(int, double, double);
  Port(const Port&);

  int getId() const;
  double getX() const;
  double getY() const;
  std::list<Container*> getContainers() const;
  std::list<SimpleShip*> getHistory() const;
  std::list<SimpleShip*> getCurrent() const;

  double getDistance(Port*) const;
  void incomingShip(SimpleShip*);
  void outgoingShip(SimpleShip*);

  bool contains(Container*);
  void add(Container*);
  void remove(Container*);

  std::string toString() const;
};

#endif
