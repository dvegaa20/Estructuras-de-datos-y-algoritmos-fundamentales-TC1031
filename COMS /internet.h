// =========================================================
// File: internet.h
// Author:DIEGO VEGA CAMACHO
// Date:17/06/2022
// Description: internet class
// =========================================================

#ifndef InternetOperator_H 
#define InternetOperator_H 

#include "operator.h"
using namespace std; 

class InternetOperator : public Operator { 
private: 
  const double LIMITGB = 1.0;

public: 
  InternetOperator(int, double, double, double, int, OperatorType); 
  InternetOperator(const InternetOperator&);

  double calculateTalkingCost(int, int); 
  double calculateMessageCost(int, int, int); 
  double calculateNetworkCost(double); 
};
InternetOperator::InternetOperator(int Id, double TalkingCharge, double MessageCost, double NetworkCharge, int DiscountRate, OperatorType typ) 
	: Operator(Id, TalkingCharge, MessageCost, NetworkCharge, DiscountRate, typ){ 
}
InternetOperator::InternetOperator(const InternetOperator &oth) 
	: Operator(oth){
} 
double InternetOperator::calculateTalkingCost(int minute, int age){ 
	double cost = 0;
	if (minute > 0 && age > 0){ 
		cost = minute *talkingCharge;
		if (minute < 2){ 
			cost -= cost *discountRate/100; 
		} 
	} 
	return cost ; 
} 
double InternetOperator::calculateMessageCost(int quantity, int thisOpId, int othOpId){ 
	double cost =0; 
	if (quantity > 0){ 
		cost = quantity * messageCost; 
		if (quantity < 3){ 
			cost -= cost *discountRate/100; 
		}
	}
	return cost ; 
} 
double InternetOperator::calculateNetworkCost(double amount){
  double cost =0; 
  if (amount > LIMITGB){ 
    cost =(amount-LIMITGB)*networkCharge; 
  } 
  return cost ;
}
#endif 

