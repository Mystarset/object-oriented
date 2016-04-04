 /************************************************************ 
  FileName: scan.cpp  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               对接收的数据进行判断格式是否正确，并将数据分块的一个个放入队列中
			   对负数和减号进行区分 

  Function List:
            
			   Scan () 对变量初始化
			   ~Scan () 清空队列
			   ToStringQueue() 逐个扫描字符串，判断输入数据准确性的同时把数据分开放入队列
			   BackStringQueue 返回队列的值 

*************************************************************/ 

#include "Scan.h"

#include <stack>
#include <queue>
#include <string>

using namespace std;
 
Scan::Scan()
{
	error = true;  //初始化 
}

Scan::~Scan()
{
    while (!que->empty()) 
	{
		que->pop();  //清空队列 
    }
    
	delete que;

}


bool check(char c)   //判断是否是运算符 
{
	if (c == '+' || c == '-' || c == '*' 
		|| c == '/' || c == '(' || c == ')')
	{
	    return false;
	} 
    return true;
}


void Scan::ToStringQueue(string input)
{
    int i;
	string data="";    //当前的数据 
	string opr="";     //用于区分负数与减号 
	stack<string>stk;  //新建一个栈用于判断括号是否匹配 
	
	for (i = 0; i < input.size(); i++)
	{
	 	if (input[i] == '.' || (input[i] >= '0' && input[i] <= '9'))
	 	{
	 	 	data += input [i];
	 	 	
	 	 	if (data.size() > 10 )  // 数字位数大于10位时报错 
			    { 
			        error = false;  
			        break;
			    }
	 	}
	 	
	 	if (input[i] == '+' || input [i] == '-' || input [i] == '*' 
		   || input[i] == '/' || input[i] == '(' || input [i] == ')')
	 	
		{
	 	    
	 	    if (data != "")   // 把数字入队 
			{
			    que->push(opr+data);
		        data = "";
		        opr = "";
		    }
		            
			data += input[i];

		    if (input[i] == '-')  //对'-'进行特殊判断 
		    {
		    	if (i == 0)
		    	    opr = "-";
		    	if (i!=0)
				    if  (!check(input[i-1]) && check(input[i+1]) && input[i-1] != ')')
		    	        opr = "-";
		    	    else
		    	        que->push (data);
		    }
		    else
			    que->push (data);   // 把符号入队 
		    
		    
			if (input[i] == '(')      // 判断括号是否匹配 
			{            
				stk.push (data);
		    }
			    
			data="";
			
			if (input[i] == ')')
			{
				if (stk.empty())
				{
					error = false;
				}
				else
			  	    if (stk.top() == "(" )
			  	    {
				        stk.pop();
				    }
				    else
				    {
				    	error = false;
				    }
			} 
		}
		 
	}
	
	if (data != "" )  
    {
	    que->push(opr+data);  //如果最后一个数据是数字则把这个数字入队 
    }
	
	if (!stk.empty()) 
	{
	    error = false;  //如果括号不匹配报错 
    } 
	
	while (!stk.empty()) 
	{
	    stk.pop();   //清空栈 
    }
}

queue<string> *Scan::BackStringQueue()
{
	if (error) // 如果没有报错返回队列的值 
	{
	    return que;  
    }
	else 
	{
	    return NULL; //如果报错则返回空 
    }
}


