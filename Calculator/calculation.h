#ifndef CALCULATION_H
#define CALCULATION_H

#include "Operation.h"
#include "Checkrelation.h" 

#include <queue>
#include <string>
#include <stack>
#include <iostream>
using namespace std;

class Calculation
{
	private:
	    stack<double> *StaNum = new stack<double>;   //该栈用于储存数字 
		stack<string> *StaOpr = new stack<string>;   //该栈用于存储操作符 
        CheckRelation *che = new CheckRelation;      //用于判定操作符之间的优先级 
        Operation *oper = new Operation;             //计算 
        int error;                                   //判断错误类型 

	public:
		Calculation();
		~Calculation();
		void NumCalculator(queue<string> *data);
		void PrintAnser();
		
	protected:
};

#endif
