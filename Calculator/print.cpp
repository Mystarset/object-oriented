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



