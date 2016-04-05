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

#include <iostream>
#include <string>

using namespace std;

int main(int argc,char* argv[])
{
	
      
    bool run = true;    // 判断代码是否继续运行的变量 
    bool checkprint = false;      // 判断输出是否需要输出表达式 
      
    while (run) 
    {
        	
	    Scan *get = new Scan;
        //Print *wri = new Print;
        Calculation *cal = new Calculation;
			
        cout << "请输入四则运算表达式:" << endl ;
        	
        string str;   // 用于储存输入数据的变量 	
        cin >> str;
        	
        if (str == "exit") 
		{ 
			run = false ; // 判断是否结束 
        } 
		else
		{
			if (str == "-a")      
			{
			    cin >> str;
			    checkprint = true;
			}
			
		    get->ToStringQueue(str);  //得到队列 
			 	 
			if (get->BackStringQueue() != NULL)   //判断数据是否合法 
			{ 
				//wri->StringPrint(get->BackStringQueue());  // 合法时的输出 
				
				cal->NumCalculator(get->BackStringQueue());   // 计算表达式 
				
				if (checkprint)    // 判断是否需要输出表达式 
				{
					cout << str << "= ";
				}
				
				cal->PrintAnser();
			
			} 
			else
			{ 	  	 
				cout << "Error!" << endl;  //  不合法时的输出 
		    }
		} 
			 
			delete get;
			//delete wri;
			delete cal; 
    }

    return 0;	
	
} 










