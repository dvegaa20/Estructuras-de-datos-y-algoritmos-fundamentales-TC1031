// =========================================================
// File: refrigerated.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef REFRIGERATED_H
#define REFRIGERATED_H

#include "heavy.h"

class RefrigeratedContainer : public HeavyContainer {
public:
  RefrigeratedContainer(int, int);
  RefrigeratedContainer(const RefrigeratedContainer&);

  double getConsumption() const;
};

#endif
