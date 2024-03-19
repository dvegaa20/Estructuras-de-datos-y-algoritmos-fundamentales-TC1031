// =========================================================
// File: vox.h
// Author:DIEGO VEGA CAMACHO
// Date: 17/06/2022
// Description: vox class
// =========================================================

#ifndef VOXOPERATOR_H 
#define VOXOPERATOR_H 

#include "operator.h" 
using namespace std; 

class VoxOperator : public Operator { 
public: 
  VoxOperator(int, double, double, double, int, OperatorType); 
  VoxOperator(const VoxOperator&); 

  double calculateTalkingCost(int, int);
  double calculateMessageCost(int, int, int); 
  double calculateNetworkCost(double); 
}; 
VoxOperator::VoxOperator(int Id, double TalkingCharge, double MessageCost, double NetworkCharge, int DiscountRate, OperatorType typ) 
	: Operator(Id, TalkingCharge, MessageCost, NetworkCharge, DiscountRate, typ){
} 
VoxOperator::VoxOperator(const VoxOperator &oth) 
	: Operator(oth){ 
} 
double VoxOperator::calculateTalkingCost(int minute, int age){
	double cost =0;
	if (minute > 0 && age > 0){ 
		cost = minute*talkingCharge; 
		if (age<18 || age>65){ 
			cost -=cost *discountRate/100; 
		} 
	} 
	return cost ;
} 
double VoxOperator::calculateMessageCost(int quantity, int thisOpId, int othOpId){
	double cost =0;
	if (quantity > 0){ 
		cost = quantity*messageCost; 
		if(thisOpId==othOpId){ 
			cost -=cost *discountRate/100;
		}
	}
	return cost ;
} 
double VoxOperator::calculateNetworkCost(double amount){ 
	double cost =0; 
	if (amount>0){ 
		cost =amount*networkCharge;	
	}
	return cost ; 
} 
#endif 
