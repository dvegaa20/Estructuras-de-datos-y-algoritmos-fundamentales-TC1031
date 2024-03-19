// =========================================================
// File: simpleship.h
// Author:
// Date:
// Description:
// =========================================================

#ifndef SIMPLE_SHIP_H
#define SIMPLE_SHIP_H

class SimpleShip {
protected:
  int id;

public:
  SimpleShip(int);
  SimpleShip(const SimpleShip&);

  int getId() const;

  bool operator==(const SimpleShip*);
  bool operator==(const SimpleShip&);

  bool operator<(const SimpleShip*);
  bool operator<(const SimpleShip&);

  virtual std::string toString() const = 0;
};

#endif
