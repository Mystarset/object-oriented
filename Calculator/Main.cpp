 /************************************************************ 
  FileName: Main.cpp  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               ����һ������������ʽ����������ʽ���
			   ���ڱ��ʽǰ����-aʱ��������ʱ�Լ���� 
               ������exitʱ �������� 

  Function List:
            
			   int main() ������ ʵ����������ĵ��� 

*************************************************************/ 

#include "scan.h"
#include "print.h"
#include "Calculation.h"

#include <iostream>
#include <string>

using namespace std;

int main(int argc,char* argv[])
{
	
      
    bool run = true;    // �жϴ����Ƿ�������еı��� 
          // �ж�����Ƿ���Ҫ������ʽ 
      
    while (run) 
    {
        
	    Scan *get = new Scan;
        //Print *wri = new Print;
        Calculation *cal = new Calculation;
		bool checkprint = false;
			
        cout << "����������������ʽ:" << endl ;
        	
        string str;   // ���ڴ����������ݵı��� 	
        cin >> str;
        	
        if (str == "exit") 
		{ 
			run = false ; // �ж��Ƿ���� 
        } 
		else
		{
			if (str == "-a")      
			{
			    cin >> str;
			    checkprint = true;
			}
		
		    get->ToStringQueue(str);  //�õ����� 
			 	 
			if (get->BackStringQueue() != NULL)   //�ж������Ƿ�Ϸ� 
			{ 
				//wri->StringPrint(get->BackStringQueue());  // �Ϸ�ʱ����� 
				
				cal->NumCalculator(get->BackStringQueue());   // ������ʽ 
				
				if (checkprint)    // �ж��Ƿ���Ҫ������ʽ 
				{
					cout << str << "= ";
				}
				
				cal->PrintAnser();
			
			} 
			else
			{ 	  	 
				cout << "Error!" << endl;  //  ���Ϸ�ʱ����� 
		    }
		} 
			 
			delete get;
			//delete wri;
			delete cal; 
    }

    return 0;	
	
} 










