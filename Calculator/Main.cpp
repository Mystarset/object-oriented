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
        Print *wri = new Print;
        Calculation *cal = new Calculation;
        Pretreatment *pre = new Pretreatment; 
		bool checkprint = false;
			
        
        
        string str1 = "",str = "";   // 用于储存输入数据的变量 
        string in = "";    // 用于存储输入文件的文件名
		string out = "";   // 用于存储输出文件的文件名 
	    
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
	    
	    
	    
		get->ToStringQueue(str);  //得到队列 
			 	 
		if (get->BackStringQueue() != NULL)   //判断数据是否合法 
		{ 
			//wri->StringPrint(get->BackStringQueue());  // 合法时的输出 
			
			pre->yuchuli(get->BackStringQueue());  //预处理表达式 
			
			cal->NumCalculator(pre->BackStringQueue());   // 计算表达式 
			
			int error = cal->ReturnError();
			int anser = cal->ReturnAnser();
				
			wri->PrintAnser(checkprint,error,anser,str1); // 输出答案 
			
		} 
		
		delete get;
		delete wri;
		delete cal; 
		delete pre;
		
		break;
	} 
			 
    return 0;	
	
} 










