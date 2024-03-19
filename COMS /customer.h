// =========================================================
// File: customer.h
// Author:DIEGO VEGA CAMACHO
// Date: 17/06/2022
// Description: customer class
// =========================================================
#ifndef CUSTOMER_H 
#define CUSTOMER_H 

#include <string> 
#include <sstream> 
#include <iomanip> 
#include "bill.h" 
#include "operator.h" 
using namespace std; 

class Customer { 
private: 
  int id, age, totalSpentTalkingTime, totalMessageSent, totalInternetUsage; 
  string name; 
  Operator* op;
  Bill *bill; 

public: 
  Customer(int, string, int, Operator*, double); 
  Customer(const Customer&); 
  ~Customer(); 

  int getId() const;
  int getAge() const;
  int getTotalSpentTalkingTime() const; 
  int getTotalMessageSent() const; 
  double getTotalInternetUsage() const; 
  string getName() const; 
  Operator* getOperator() const; 
  Bill* getBill() const; 
  
  void addTalkingTime(int); 
  void addTotalMessageSent(int);
  void addTotalInternetUsage(double); 
  void setOperator(Operator*); 

  string toString() const; 

  void talk (int, Customer&);
  void message(int, const Customer&); 
  void connection(double); 
  void pay(double); 
}; 
Customer::Customer(int Id, string Name, int Age, Operator *Op, double lim){ 
	id = Id; 
	name = Name; 
	age = Age; 
	op = Op; 
	bill = new Bill(lim); 
	totalSpentTalkingTime = 0; 
	totalMessageSent = 0; 
	totalInternetUsage = 0; 
} 
Customer::Customer(const Customer &oth){ 
	id=oth.id; 
	name=oth.name; 
	age=oth.age; 
	op=oth.op; 
	bill=oth.bill; 
	totalSpentTalkingTime=oth.totalSpentTalkingTime; 
	totalMessageSent=oth.totalMessageSent; 
	totalInternetUsage=oth.totalInternetUsage; 
} 
Customer::~Customer(){ 
	delete bill;
} 
int Customer::getId() const{ 
	return id; 
} 
int Customer::getAge() const{ 
	return age; 
} 
int Customer::getTotalSpentTalkingTime() const{ 
	return totalSpentTalkingTime; 
} 
int Customer::getTotalMessageSent() const{ 
	return totalMessageSent; 
} 
double Customer::getTotalInternetUsage() const{ 
	return totalInternetUsage; 
} 
string Customer::getName() const{ 
	return name; 
} 
Operator* Customer::getOperator() const{ 
	return op; 
} 
Bill* Customer::getBill() const{ 
	return bill; 
} 
void Customer::addTalkingTime(int minute){
	if (minute > 0){ 
		totalSpentTalkingTime += minute; 
	}
} 
void Customer::addTotalMessageSent(int messageCost) {
	if (messageCost > 0){  
	 	totalMessageSent += messageCost;  
	} 
}  
void Customer::addTotalInternetUsage(double amount){
	if (amount > 0){ 
		totalInternetUsage += amount; 
	} 
} 
void Customer::setOperator(Operator *Op){
	op = Op;
} 
void Customer::talk(int minutes, Customer &oth){
	double cost;
	if (minutes > 0 && oth.getId() != id){ 
		cost = op -> calculateTalkingCost(minutes, age); 
		if (bill -> check(cost)){ 
			bill -> add(cost); 
			addTalkingTime(minutes); 
			op -> addTalkingTime(minutes); 
			if (op -> getId()!=oth.op -> getId()){ 
				oth.op->addTalkingTime(minutes); 
			} 
		} 
	} 
} 
void Customer::message(int quantity, const Customer &oth){
	double cost=0;
	if (quantity > 0 && oth.getId() != id){ 
		cost = op -> calculateMessageCost(quantity, op->getId(), oth.op -> getId()); 
		if (bill -> check(cost)){ 
			bill -> add(cost); 
			addTotalMessageSent(quantity);
			op -> addTotalMessageSent(quantity); 
		} 
	} 
} 
void Customer::connection(double amount){
	double cost = 0; 
	if (amount > 0){
		cost = op -> calculateNetworkCost(amount); 
		if (bill -> check(cost)){
			bill -> add(cost); 
			addTotalInternetUsage(amount); 
			op -> addTotalInternetUsage(amount); 
		} 
	} 
} 
void Customer::pay(double amount){
	bill -> pay(amount);
} 
string Customer::toString() const{
	stringstream aux; 
	aux<<"Customer "<< fixed << getId()<< ": "
	   << fixed << setprecision(2) << bill -> getTotalMoneySpent() << " " 
	   << fixed <<setprecision(2) << bill -> getCurrentDebt() <<"\n"; 
	return aux.str();
} 
#endif

