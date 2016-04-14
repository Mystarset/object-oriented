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
#include "Pretreatment.h"

#include <iostream>
#include <string.h>
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
        Pretreatment *pre = new Pretreatment; 
		bool checkprint = false;
			
        
        
        string str="";   // ���ڴ����������ݵı��� 
        
       	if (argc != 2 && argc != 3)
       	{
       		cout << "����������������ʽ:" << endl ;
            cin >> str;
        	
            if (str == "exit") 
		    { 
			    run = false ; // �ж��Ƿ���� 
			    break;
            }  
		    else
		    {
			    if (str == "-a")      
			    {
			        cin >> str;
			        checkprint = true;
			    }
	        }
	    }
	    else
	    {
	        if (argc == 3)
	        {
	            checkprint = true;
	    	    str = argv[2];
	        }
	        else
	        {
	    	    str = argv[1];	    		
	        }
	    }
	    
		get->ToStringQueue(str);  //�õ����� 
			 	 
		if (get->BackStringQueue() != NULL)   //�ж������Ƿ�Ϸ� 
		{ 
			//wri->StringPrint(get->BackStringQueue());  // �Ϸ�ʱ����� 
			
			pre->yuchuli(get->BackStringQueue());  //Ԥ������ʽ 
			
			cal->NumCalculator(pre->BackStringQueue());   // ������ʽ 
				
			if (checkprint)    // �ж��Ƿ���Ҫ������ʽ 
			{
				cout << str << "= ";
			}
				
			cal->PrintAnser();
			
		} 
		
		delete get;
		//delete wri;
		delete cal; 
		delete pre;
		
		if (argc == 2 || argc == 3)
		{
		    break;
		}
	} 
			 

    

    return 0;	
	
} 










