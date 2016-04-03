#ifndef CALCULATION_H
#define CALCULATION_H

#include "Operation.h"

#include <queue>
#include <string>
#include <stack>
using namespace std;

class Calculation
{
	private:
	    stack<double> *StaNum = new stack<double>;   //该栈用于储存数字 
		stack<string> *StaOpr = new stack<string>;   //该栈用于存储操作符 
        CheckRelation *che = new CheckRelation;      //用于判定操作符之间的优先级 
        Operation *oper = new Operation;             //计算 

	public:
		Calculation();
		~Calculation();
		void NumCalculator(queue<string> *data);
		void PrintAnser();
		
	protected:
};

#endif
