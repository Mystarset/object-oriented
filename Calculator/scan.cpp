 /************************************************************ 
  FileName: scan.cpp  

  Author: Starset        Version :  1.0        Date:  2015.3.7

  Description:      
  
               �Խ��յ����ݽ����жϸ�ʽ�Ƿ���ȷ���������ݷֿ��һ������������� 

  Function List:
            
			   Scan () �Ա�����ʼ��
			   ~Scan () ��ն���
			   ToStringQueue() ���ɨ���ַ������ж���������׼ȷ�Ե�ͬʱ�����ݷֿ��������
			   BackStringQueue ���ض��е�ֵ 

*************************************************************/ 

#include "scan.h"

#include <stack>
#include <queue>
#include <string>

using namespace std;
 
Scan::Scan()
{
	error = true;  //��ʼ�� 
}

Scan::~Scan()
{
   while (!que->empty()) que->pop();  //��ն��� 
   	
   delete que;

}


void Scan::ToStringQueue(string input)
{
	int i;
	string date="";
	stack<string>stk;  //�½�һ��ջ�����ж������Ƿ�ƥ�� 
	
	for ( i=0; i<input.size(); i++)
	 {
	 	if (input[i] == '.' || (input[i] >= '0' && input[i] <= '9' ) )
	 	 {
	 	 	date += input [i];
	 	 	
	 	 	if (date.size() > 10 )  // ����λ������10λʱ���� 
			  { 
			     error = false;  
			     break;
			  }
	 	 }
	 	
	 	if (input[i] == '+' || input [i] == '-' || input [i] == '*' || input[i] == '/' || input[i] == '(' || input [i] == ')')
	 	 {
	 	    
	 	    if (date != "")   // ��������� 
			 {
			    que->push (date);
		        date="";
		     }
		    date += input[i];
	
		    que->push (date);   // �ѷ������ 
		    
		    
			 
		    if (input[i] == '(')      // �ж������Ƿ�ƥ�� 
			  stk.push (date);
			 
			date="";
			
			if (input[i] == ')')
			  {
			  	 if (stk.top() == "(" )
				    stk.pop(); 
			  } 
		 }
		 
	 }
	
	if (date != "" )  que->push(date);  //������һ������������������������� 
	
	if (!stk.empty())  error = false;  //������Ų�ƥ�䱨�� 
	
	while (!stk.empty()) stk.pop();   //���ջ 
}

queue<string> *Scan::BackStringQueue()
{
	if (error) // ���û�б����ض��е�ֵ 
	   return que;  
	else 
	   return NULL; //��������򷵻ؿ� 
}


