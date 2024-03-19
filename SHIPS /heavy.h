// =========================================================
// File: heavy.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef HEAVY_H
#define HEAVY_H

#include "container.h"

class HeavyContainer : public Container {
public:
  HeavyContainer(int, int);
  HeavyContainer(int, int, ContainerType);
  HeavyContainer(const HeavyContainer&);

  double getConsumption() const;
};

#endif
