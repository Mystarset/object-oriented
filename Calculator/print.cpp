 /************************************************************ 
  FileName: print.cpp  

  Author: Starset        Version :  1.0        Date:  2015.3.7

  Description:      
              
              ������� 

  Function List:
              
              StringPrint() ��� 

*************************************************************/ 


#include "print.h"

#include <queue>
#include <string>
#include <iostream>

using namespace std;

Print::Print()
{
}

Print::~Print()
{
}

void Print::StringPrint(queue<string> *output)
{
	while (!output->empty())   // ��� 
	 {
	 	cout << output->front() << endl;
	 	output->pop();
	 }
}



