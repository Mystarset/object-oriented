 /************************************************************ 
  FileName: Main.cpp  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
   
                把字符串转化成数字
				对传入的操作符与数字进行运算             

  Function List:
            
			   ChangeToNum()  字符串转数字
			   Operate() 计算 

*************************************************************/ 
#include "operation.h"

#include <iostream>
#include <sstream>

using namespace std;

Operation::Operation()
{
}

Operation::~Operation()
{
}

double Operation::ChangeToNum(string data)
{
	std::stringstream stream;
	
	stream.clear();
	
	stream << data;
	double temp;
	stream >> temp;
	
	return temp;
}

double Operation::Operate(double opr1,double opr2,string opr)
{
    if (opr == "+")
    {
    	return (opr1+opr2);
    }
    if (opr == "-")
    {
    	return (opr1-opr2);
    }
    if (opr == "*")
	{
		return (opr1*opr2);
	} 
    if (opr == "/")
    {
    	return (opr1/opr2);
    }
}
