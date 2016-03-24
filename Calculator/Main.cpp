 /************************************************************ 
  FileName: Main.cpp  

  Author: Starset        Version :  1.0        Date:  2016.3.7

  Description:      
  
               ����һ������������ʽ������ַ�ɨ����ȡ��� 
               ������exitʱ �������� 

  Function List:
            
			   int main() ������ ʵ����������ĵ��� 

*************************************************************/ 

#include "scan.h"
#include "print.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	
      
      bool run=true;    // �жϴ����Ƿ�������еı��� 
      
      while (run) 
        {
        	
			Scan *get = new Scan;
            Print *wri = new Print;
        	
        	cout << "����������������ʽ:" << endl ;
        	
        	string str;   // ���ڴ����������ݵı��� 
        	
        	cin >> str;
        	
        	if (str == "exit") run = false ; // �ж��Ƿ���� 
        	
			else
			 {
			 	 get->ToStringQueue(str);  //�õ����� 
			 	 
			 	 if (get->BackStringQueue() != NULL)   //�ж������Ƿ�Ϸ� 
			 	    
					 wri->StringPrint(get->BackStringQueue());  // �Ϸ�ʱ����� 
			 	 
				 else
			 	  	 
					 cout << "Error!" << endl;  //  ���Ϸ�ʱ����� 
			 	  	 
			 } 
			 
			delete get;
			delete wri;
        }


    return 0;	
	
} 










