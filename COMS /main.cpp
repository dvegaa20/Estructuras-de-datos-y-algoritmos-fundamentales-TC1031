// =========================================================
// File: main.cpp
// Author:DIEGO VEGA CAMACHO
// Date:17/06/2022
// Description:main .cpp
// To compile: g++ -std=c++11 main.cpp -o app
// To execute: ./app input_file output_file
// =========================================================
#include <iostream> 
#include <string> 
#include <sstream> 
#include <iomanip> 
#include <fstream> 
#include <vector> 
#include "bill.h" 
#include "operator.h" 
#include "vox.h"
#include "internet.h" 
#include "customer.h" 
using namespace std; 

int main(int argc, char* argv[]) { 
	ifstream inputFile; 
	ofstream outputFile; 
	int C, O, N, ins, age, idOp, discountRate, idC1, idC2, minutes, quantity; 
	double lim, talkingCharge, messageCost, networkCharge, amount; 
	string name; 
	int type;
	if (argc!=3){ 
		cout<<"usage: "<<argv[0]<<"input_file output_file"<<"\n"; 
		return -1; 
	} 
	inputFile.open(argv[1]);
	if(!inputFile.is_open()){
		cout<<argv[0]<<": File  \""<<argv[1]<<"\" not found"<<"\n"; 
		return -1; 
	} 
	outputFile.open(argv[2]); 
	inputFile >> C>> O>> N; 
	
	vector<Customer *> customers; 
	vector<Operator *> operators; 
	customers.resize(C); 
	operators.resize(O);
	
  int oC=0, cC=0;
	
  for (int i=0;i<N;i++){
		inputFile >> ins;
		switch (ins){ 
			case 1:
				inputFile >> name >> age >> idOp >>lim;
				customers.at(cC)=new Customer(cC, name, age, operators.at(idOp),lim);
				cC++; 
				break; 
			case 2: 
				inputFile>>type>>talkingCharge>>messageCost>>networkCharge>>discountRate; 
				if (type==1){ 
					operators.at(oC)=new VoxOperator(oC, talkingCharge, messageCost, networkCharge, discountRate, VOX); 
					oC++; 
				}
				else if (type==2){
					operators.at(oC)=new InternetOperator(oC, talkingCharge, messageCost, networkCharge, discountRate, INTERNET); 
					oC++;
				} 
				break; 
			case 3:
				inputFile>>idC1>>idC2>>minutes;
				customers.at(idC1)->talk(minutes, *customers.at(idC2)); 
				break; 
			case 4: 
				inputFile>>idC1>>idC2>>quantity; 
				customers.at(idC1)->message(quantity, *customers.at(idC2)); 
				break; 
			case 5: 
				inputFile>>idC1>>amount; 
				customers.at(idC1)->connection(amount); 
				break; 
			case 6: 
				inputFile>>idC1>>amount; 
				customers.at(idC1)->pay(amount);
				break; 
			case 7:
				inputFile>>idC1>>idOp;
				customers.at(idC1)->setOperator(operators.at(idOp)); 
				break; 
			case 8: 
				inputFile>>idC1>>lim; 
				customers.at(idC1)->getBill()->changeTheLimit(lim); 
			default: 
				break; 
		} 
	} 
	vector<Operator *>::iterator i1;
	for (i1=operators.begin();i1!=operators.end();i1++){ 
		outputFile<<(*i1)->toString(); 
	} 
	
	int timeM=0, messageM=0, idtimeM=0, idmessageM=0, idgbM=0; 
	double gbM=0;
	vector<Customer *>::iterator i2; 
	for (i2=customers.begin();i2!=customers.end();i2++){ 
		outputFile<<(*i2)->toString();
		if ((*i2)->getTotalSpentTalkingTime()>timeM){ 
			timeM=(*i2)->getTotalSpentTalkingTime();
			idtimeM=(*i2)->getId();
		}
		if ((*i2)->getTotalMessageSent()>messageM){ 
			messageM=(*i2)->getTotalMessageSent(); 
			idmessageM=(*i2)->getId(); 
		} 
		if ((*i2)->getTotalInternetUsage()>gbM){ 
			gbM=(*i2)->getTotalInternetUsage(); 
			idgbM=(*i2)->getId();
		}
	}
	outputFile<<customers[idtimeM]->getName()<<": " 
			  <<customers[idtimeM]->getTotalSpentTalkingTime()<<"\n"; 
	outputFile<<fixed<<setprecision(2)<<customers[idmessageM]->getName()<<": " 
			  <<customers[idmessageM]->getTotalMessageSent()<<"\n";
	outputFile<<fixed<<setprecision(2)<<customers[idgbM]->getName()<<": "
			  <<customers[idgbM]->getTotalInternetUsage()<<"\n";
	
	for (int i = 0; i<customers.size(); i++){ 
		delete customers[i]; 
	} 
	for (int i = 0; i<operators.size(); i++){ 
		delete operators[i];
	} 
	customers.clear(); 
	operators.clear(); 
	inputFile.close(); 
	outputFile.close();	 
	return 0;
} 

