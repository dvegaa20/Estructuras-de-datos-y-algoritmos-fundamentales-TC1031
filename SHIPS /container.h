// =========================================================
// File: container.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef CONTAINER_H
#define CONTAINER_H

typedef enum{LIGHT, HEAVY, REFRIGERATED, LIQUID} ContainerType;

class Container {
protected:
  int id, weight;
  ContainerType type;

public:
  Container(int, int, ContainerType);
  Container(const Container&);

  ContainerType getType() const;
  int getId() const;
  int getWeight() const;

  bool operator==(const Container*);
  bool operator==(const Container&);
  bool operator<(const Container*);
  bool operator<(const Container&);

  virtual double getConsumption() const = 0;
};

#endif
