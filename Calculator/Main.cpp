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
        Print *wri = new Print;
        Calculation *cal = new Calculation;
        Pretreatment *pre = new Pretreatment; 
		bool checkprint = false;
			
        
        
        string str1 = "",str = "";   // ���ڴ����������ݵı��� 
        string in = "";    // ���ڴ洢�����ļ����ļ���
		string out = "";   // ���ڴ洢����ļ����ļ��� 
	    
	    if (argc == 2)
	    {
	    	str1 = argv[1];
	    }
	    if (argc == 3)
	    {
	    	str1 = argv[2];
	    	checkprint = true;
	    }
	    if (argc == 4)
	    {
	    	freopen(argv[2],"r",stdin);
	    	freopen(argv[3],"w",stdout);
	    	cin >> str1;
	    }
	    
	    
	    for (int i = 0; i < str1.length(); i++)
	    {
	    	if (str1[i] == '=') break;
	    	str = str + str1[i];
	    }
	    
	    
	    
		get->ToStringQueue(str);  //�õ����� 
			 	 
		if (get->BackStringQueue() != NULL)   //�ж������Ƿ�Ϸ� 
		{ 
			//wri->StringPrint(get->BackStringQueue());  // �Ϸ�ʱ����� 
			
			pre->yuchuli(get->BackStringQueue());  //Ԥ������ʽ 
			
			cal->NumCalculator(pre->BackStringQueue());   // ������ʽ 
			
			int error = cal->ReturnError();
			int anser = cal->ReturnAnser();
				
			wri->PrintAnser(checkprint,error,anser,str1); // ����� 
			
		} 
		
		delete get;
		delete wri;
		delete cal; 
		delete pre;
		
		break;
	} 
			 
    return 0;	
	
} 










