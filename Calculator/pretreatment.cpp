
#include "pretreatment.h"

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
 
Pretreatment::Pretreatment()
{
	for (int i = 0;i <= 10000; i++)
	{
		input[i] = "";
	}
}

Pretreatment::~Pretreatment()
{
	while (!backque->empty())
	{
	    backque->pop();	
	} 
	
	delete backque;
}

bool check(string c)   //判断是否是运算符 
{
	if (c == "+" || c == "-" || c == "*" 
		|| c == "/" || c == "(" || c == ")")
	{
	    return false;
	} 
    return true;
}

void Pretreatment::yuchuli(queue<string> *inque)
{
	int len = 0;
	while (!inque->empty())
	{
		input[len++] = inque->front();
		inque->pop(); 
	}
	
	int i = 0;
	while (i < len)
	{
		
		string c = "";
		if (i != 0)
		{
		    c = input[i-1];
	    }
	    
		if (input[i] == "-")   //一堆连续的负号的特判，以及对是否需要补零的判断 
		{
	        int num_fuhao = 0;

		
		    while (input[i] == "-" && input[i+1] == "-")
		    {
			    num_fuhao++;
			    i++;
		    }
		    if ((num_fuhao + 1) % 2 == 0)   //负号的个数是偶数个 
		    {
			    
			    if (check(input[i+1]) && check(c) && c != "")
			    {
			    	backque->push("+");
			    }
			    else
			    {
			        if (c == "(" || c == "")
			        {
			        	backque->push("0");
			        	backque->push("+");
			        	if (input[i+1] == "(")
						{
							backque->push("1");
							backque->push("*");
						} 
			        }
			    }
		       
		    }
		    else  // 负号的个数是奇数个 
		    {
		    	if (c == "(" || c == "")
			    {
			        backque->push("0");
			        backque->push("-");
			        if (input[i+1] == "(")
					{
						backque->push("1");
						backque->push("*");
					} 			        
			    }
			    else
			    {
			    	if (input[i+1] == "(")
			    	{
			    		if (check(c))
						{
							backque->push("-");
							backque->push("1");
						} 
						else
						{
			    		    backque->push("-1");
			    		}
			    		
						backque->push("*");
			    	}
			    	else
			    	{
		    	        backque->push("-");
		    	    }
		    	}
		    	
		    }
		    
		}
		else
		{
			if (input[i] == ")" && input[i+1] == "(")  //两个括号相连补乘号 
			{
				backque->push(input[i]);
				backque->push("*");
			}
			else
			{
			    if (check(input[i]) && input[i+1] == "(") //数字与左括号相连补乘号 
			    {
				    backque->push(input[i]);
				    backque->push("*");
			    }
			    else
			    {
			        if (check(input[i]) && c == ")") //右括号与数字相连补乘号 
			        {
				        backque->push("*");
				        backque->push(input[i]);
			        }
			        else
			        {
				        backque->push(input[i]);
			        }
			    }
			}
        }
		
		i++;
	}
	/*while (!backque->empty())
	{
		cout << backque->front() << endl;
		backque->pop();
	}*/
	
}
queue<string> *Pretreatment::BackStringQueue()
{
    return backque;
}
