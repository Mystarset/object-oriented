 /************************************************************ 
  FileName: operation.h  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
   
                ���ַ���ת��������
				�Դ���Ĳ����������ֽ�������             

  Function List:
            
			   ChangeToNum()  �ַ���ת����
			   Operate() ���� 

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
