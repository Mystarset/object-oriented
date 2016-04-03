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
	    stack<double> *StaNum = new stack<double>;   //��ջ���ڴ������� 
		stack<string> *StaOpr = new stack<string>;   //��ջ���ڴ洢������ 
        CheckRelation *che = new CheckRelation;      //�����ж�������֮������ȼ� 
        Operation *oper = new Operation;             //���� 

	public:
		Calculation();
		~Calculation();
		void NumCalculator(queue<string> *data);
		void PrintAnser();
		
	protected:
};

#endif
