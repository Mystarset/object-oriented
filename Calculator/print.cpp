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
void Print::PrintAnser(bool checkprint,int error,int anser,string str1)
{
	if (error == 1) 
	{
		cout << "���ֳ������㷶Χ" << endl; 
	}

    if (error == 2)
    {
        cout << "���ֱ����" << endl;
    }
    
    if (error == 3)
    {
    	cout << "ERROR!" << endl; 
    }
    
    if (error == 0)
	{
		if (checkprint)
	    {
		    cout << str1 << " "; 
	    }
	    cout << anser << endl;   //��� 
    } 

}



