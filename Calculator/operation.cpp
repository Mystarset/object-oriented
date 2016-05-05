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
