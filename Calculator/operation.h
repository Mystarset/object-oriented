 /************************************************************ 
  FileName: operation.h  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
   
                把字符串转化成数字
				对传入的操作符与数字进行运算             

  Function List:
            
			   ChangeToNum()  字符串转数字
			   Operate() 计算 

*************************************************************/ 
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
