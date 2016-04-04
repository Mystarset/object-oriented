 /************************************************************ 
  FileName: scan.cpp  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               �Խ��յ����ݽ����жϸ�ʽ�Ƿ���ȷ���������ݷֿ��һ�������������
			   �Ը����ͼ��Ž������� 

  Function List:
            
			   Scan () �Ա�����ʼ��
			   ~Scan () ��ն���
			   ToStringQueue() ���ɨ���ַ������ж���������׼ȷ�Ե�ͬʱ�����ݷֿ��������
			   BackStringQueue ���ض��е�ֵ 

*************************************************************/ 

#include "Scan.h"

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
    while (!que->empty()) 
	{
		que->pop();  //��ն��� 
    }
    
	delete que;

}


bool check(char c)   //�ж��Ƿ�������� 
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
	string data="";    //��ǰ������ 
	string opr="";     //�������ָ�������� 
	stack<string>stk;  //�½�һ��ջ�����ж������Ƿ�ƥ�� 
	
	for (i = 0; i < input.size(); i++)
	{
	 	if (input[i] == '.' || (input[i] >= '0' && input[i] <= '9'))
	 	{
	 	 	data += input [i];
	 	 	
	 	 	if (data.size() > 10 )  // ����λ������10λʱ���� 
			    { 
			        error = false;  
			        break;
			    }
	 	}
	 	
	 	if (input[i] == '+' || input [i] == '-' || input [i] == '*' 
		   || input[i] == '/' || input[i] == '(' || input [i] == ')')
	 	
		{
	 	    
	 	    if (data != "")   // ��������� 
			{
			    que->push(opr+data);
		        data = "";
		        opr = "";
		    }
		            
			data += input[i];

		    if (input[i] == '-')  //��'-'���������ж� 
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
			    que->push (data);   // �ѷ������ 
		    
		    
			if (input[i] == '(')      // �ж������Ƿ�ƥ�� 
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
	    que->push(opr+data);  //������һ������������������������� 
    }
	
	if (!stk.empty()) 
	{
	    error = false;  //������Ų�ƥ�䱨�� 
    } 
	
	while (!stk.empty()) 
	{
	    stk.pop();   //���ջ 
    }
}

queue<string> *Scan::BackStringQueue()
{
	if (error) // ���û�б����ض��е�ֵ 
	{
	    return que;  
    }
	else 
	{
	    return NULL; //��������򷵻ؿ� 
    }
}


