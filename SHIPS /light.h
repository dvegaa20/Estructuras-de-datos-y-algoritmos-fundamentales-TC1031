// =========================================================
// File: light.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef LIGHT_H
#define LIGHT_H

#include "container.h"

class LightContainer : public Container {
public:
  LightContainer(int, int);
  LightContainer(const LightContainer&);

  double getConsumption() const;
};

#endif
