 /************************************************************ 
  FileName: print.h  

  Author: Starset        Version :  1.0        Date:  2016.3.7

  Description:      
              
              ������� 

  Function List:
              
              StringPrint() ��� 

*************************************************************/ 
#include <queue>
#include <string>

#ifndef PRINT_H
#define PRINT_H

using namespace std;

class Print
{
    private:
		
	public:
		Print();
		~Print();
		
	    void StringPrint(queue<string> *output);
	    
	protected:
};

#endif
