 /************************************************************ 
  FileName: Main.cpp  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               输入一个四则运算表达式，计算出表达式结果
			   当在表达式前输入-a时，输出表达时以及结果 
               当输入exit时 结束程序 

  Function List:
            
			   int main() 主程序 实现输入输出的调用 

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
	
      
    bool run = true;    // 判断代码是否继续运行的变量 
          // 判断输出是否需要输出表达式 
      
    while (run) 
    {
        
	    Scan *get = new Scan;
        //Print *wri = new Print;
        Calculation *cal = new Calculation;
        Pretreatment *pre = new Pretreatment; 
		bool checkprint = false;
			
        
        
        string str="";   // 用于储存输入数据的变量 
        
       	if (argc != 2 && argc != 3)
       	{
       		cout << "请输入四则运算表达式:" << endl ;
            cin >> str;
        	
            if (str == "exit") 
		    { 
			    run = false ; // 判断是否结束 
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
	    
		get->ToStringQueue(str);  //得到队列 
			 	 
		if (get->BackStringQueue() != NULL)   //判断数据是否合法 
		{ 
			//wri->StringPrint(get->BackStringQueue());  // 合法时的输出 
			
			pre->yuchuli(get->BackStringQueue());  //预处理表达式 
			
			cal->NumCalculator(pre->BackStringQueue());   // 计算表达式 
				
			if (checkprint)    // 判断是否需要输出表达式 
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










