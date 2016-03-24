 /************************************************************ 
  FileName: Main.cpp  

  Author: Starset        Version :  1.0        Date:  2016.3.7

  Description:      
  
               输入一个四则运算表达式，逐个字符扫描提取输出 
               当输入exit时 结束程序 

  Function List:
            
			   int main() 主程序 实现输入输出的调用 

*************************************************************/ 

#include "scan.h"
#include "print.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
	
      
      bool run=true;    // 判断代码是否继续运行的变量 
      
      while (run) 
        {
        	
			Scan *get = new Scan;
            Print *wri = new Print;
        	
        	cout << "请输入四则运算表达式:" << endl ;
        	
        	string str;   // 用于储存输入数据的变量 
        	
        	cin >> str;
        	
        	if (str == "exit") run = false ; // 判断是否结束 
        	
			else
			 {
			 	 get->ToStringQueue(str);  //得到队列 
			 	 
			 	 if (get->BackStringQueue() != NULL)   //判断数据是否合法 
			 	    
					 wri->StringPrint(get->BackStringQueue());  // 合法时的输出 
			 	 
				 else
			 	  	 
					 cout << "Error!" << endl;  //  不合法时的输出 
			 	  	 
			 } 
			 
			delete get;
			delete wri;
        }


    return 0;	
	
} 










