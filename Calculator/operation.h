#ifndef OPERATION_H
#define OPERATION_H

#include <iostream>

using namespace std;

class Operation
{
	private:
				 
	public:
		Operation();
		~Operation();
		double ChangeToNum(string data);
		double Operate(double opr1,double opr2,string opr);
	protected:
};

#endif
