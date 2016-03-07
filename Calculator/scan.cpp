 /************************************************************ 
  FileName: scan.cpp  

  Author: Starset        Version :  1.0        Date:  2015.3.7

  Description:      
  
               对接收的数据进行判断格式是否正确，并将数据分块的一个个放入队列中 

  Function List:
            
			   Scan () 对变量初始化
			   ~Scan () 清空队列
			   ToStringQueue() 逐个扫描字符串，判断输入数据准确性的同时把数据分开放入队列
			   BackStringQueue 返回队列的值 

*************************************************************/ 

#include "scan.h"

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
   while (!que->empty()) que->pop();  //清空队列 
   	
   delete que;

}


void Scan::ToStringQueue(string input)
{
	int i;
	string date="";
	stack<string>stk;  //新建一个栈用于判断括号是否匹配 
	
	for ( i=0; i<input.size(); i++)
	 {
	 	if (input[i] == '.' || (input[i] >= '0' && input[i] <= '9' ) )
	 	 {
	 	 	date += input [i];
	 	 	
	 	 	if (date.size() > 10 )  // 数字位数大于10位时报错 
			  { 
			     error = false;  
			     break;
			  }
	 	 }
	 	
	 	if (input[i] == '+' || input [i] == '-' || input [i] == '*' || input[i] == '/' || input[i] == '(' || input [i] == ')')
	 	 {
	 	    
	 	    if (date != "")   // 把数字入队 
			 {
			    que->push (date);
		        date="";
		     }
		    date += input[i];
	
		    que->push (date);   // 把符合入队 
		    
		    
			 
		    if (input[i] == '(')      // 判断括号是否匹配 
			  stk.push (date);
			 
			date="";
			
			if (input[i] == ')')
			  {
			  	 if (stk.top() == "(" )
				    stk.pop(); 
			  } 
		 }
		 
	 }
	
	if (date != "" )  que->push(date);  //如果最后一个数据是数字则把这个数字入队 
	
	if (!stk.empty())  error = false;  //如果括号不匹配报错 
	
	while (!stk.empty()) stk.pop();   //清空栈 
}

queue<string> *Scan::BackStringQueue()
{
	if (error) // 如果没有报错返回队列的值 
	   return que;  
	else 
	   return NULL; //如果报错则返回空 
}


