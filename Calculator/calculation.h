 /************************************************************ 
  FileName: calculaton.h  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
                对读入的队列进行操作，计算出表达式的值 

  Function List:
            
			   NumCalculator()   计算表达式
			   PrintAnser()      输出答案 

*************************************************************/
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
		int ReturnError();
		int ReturnAnser();
		
	protected:
};

#endif
