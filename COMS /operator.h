// =========================================================
// File: operator.h
// Author:DIEGO VEGA CAMACHO
// Date:17/06/2022
// Description: operator class
// =========================================================

#ifndef OPERATOR_H 
#define OPERATOR_H 

#include <string> 
#include <sstream> 
#include <iomanip> 
using namespace std; 

typedef enum{VOX, INTERNET} OperatorType; 

class Operator { 
protected: 
  int id, discountRate; 
  double talkingCharge, messageCost, networkCharge, totalInternetUsage;
  int totalSpentTalkingTime, totalMessageSent; 
  OperatorType type; 

public: 
  Operator(int, double, double, double, int, OperatorType); 
  Operator(const Operator&); 

  int getId() const; 
  int getDiscountRate() const; 
  double getTalkingChage() const; 
  double getMessageCost() const; 
  double getNetworkCharge() const; 
  int getTotalSpentTalkingTime() const; 
  int getTotalMessageSent() const; 
  double getTotalInternetUsage() const; 
  OperatorType getType() const; 

  void addTalkingTime(int); 
  void addTotalMessageSent(int); 
  void addTotalInternetUsage(double); 

  string toString() const; 

  virtual double calculateTalkingCost(int, int) = 0; 
  virtual double calculateMessageCost(int, int, int) = 0; 
  virtual double calculateNetworkCost(double) = 0;
}; 
Operator::Operator(int Id, double TalkingCharge, double MessageCost, double NetworkCharge, int DiscountRate, OperatorType typ){ 
	id = Id; 
	discountRate = DiscountRate; 
	talkingCharge = TalkingCharge; 
	messageCost = MessageCost; 
	networkCharge = NetworkCharge; 
	type = typ; 
	totalInternetUsage = 0; 
	totalSpentTalkingTime = 0; 
	totalMessageSent = 0; 
} 
Operator::Operator(const Operator &oth){ 
	id=oth.id; 
	discountRate=oth.discountRate; 
	talkingCharge=oth.talkingCharge; 
	messageCost=oth.messageCost; 
	networkCharge=oth.networkCharge; 
	totalInternetUsage=oth.totalInternetUsage; 
	totalSpentTalkingTime=oth.totalSpentTalkingTime; 
	totalMessageSent=oth.totalMessageSent; 
	type=oth.type; 
} 
int Operator::getId() const{ 
	return id;
} 
int Operator::getDiscountRate() const{ 
	return discountRate; 
} 
double Operator::getTalkingChage() const{ 
	return talkingCharge; 
} 
double Operator::getMessageCost() const{ 
	return messageCost; 
} 
double Operator::getNetworkCharge() const{ 
	return networkCharge; 
} 
int Operator::getTotalSpentTalkingTime() const{ 
	return totalSpentTalkingTime; 
} 
int Operator::getTotalMessageSent() const{ 
	return totalMessageSent; 
} 
double Operator::getTotalInternetUsage() const{ 
	return totalInternetUsage; 
} 
OperatorType Operator::getType() const{ 
	return type; 
} 
void Operator::addTalkingTime(int minute){ 
	if (minute > 0){ 
		totalSpentTalkingTime += minute;
	} 
} 
void Operator::addTotalMessageSent(int MessageCost){ 
	if (MessageCost > 0){ 
		totalMessageSent += MessageCost; 
	} 
} 
void Operator::addTotalInternetUsage(double amount){ 
	if (amount>0){ 
		totalInternetUsage+=amount; 
	} 
} 
string Operator::toString() const{ 
	stringstream aux; 
	aux<<"Operator "<< fixed << getId() << ": " 
	   << fixed << getTotalSpentTalkingTime() <<" " 
	   << fixed << getTotalMessageSent() <<" " 
	   << fixed << setprecision(2) << getTotalInternetUsage() <<"\n"; 
	return aux.str(); 
} 
#endif 
