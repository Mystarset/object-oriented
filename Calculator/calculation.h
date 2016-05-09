 /************************************************************ 
  FileName: calculaton.h  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
                �Զ���Ķ��н��в�������������ʽ��ֵ 

  Function List:
            
			   NumCalculator()   ������ʽ
			   PrintAnser()      ����� 

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
	    stack<double> *StaNum = new stack<double>;   //��ջ���ڴ������� 
		stack<string> *StaOpr = new stack<string>;   //��ջ���ڴ洢������ 
        CheckRelation *che = new CheckRelation;      //�����ж�������֮������ȼ� 
        Operation *oper = new Operation;             //���� 
        int error;                                   //�жϴ������� 

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
