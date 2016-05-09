#include "Calculation.h"
#include "CheckRelation.h"
#include "Operation.h"
#include "Pretreatment.h"

#include <stack>
#include <queue>
#include <string>
#define N 1e9
using namespace std;

Calculation::Calculation()
{
	error = 0;
}

Calculation::~Calculation()
{
	while (!StaNum->empty())    //清空栈 
    {
    	StaNum->pop();
    }
    
    while (!StaOpr->empty())    //清空栈 
    {
    	StaOpr->pop();
    }
    
    delete StaNum;
    delete StaOpr;
}


void Calculation::NumCalculator(queue<string> *data)
{
	data->push("#");    //在队头队尾各加入一个#号，用于判断表达式是否计算结束 
	StaOpr->push("#");
	
    string nowopr = data->front();  // nowopr 为当前队头的元素 
    data->pop();
    
	while (nowopr != "#" || StaOpr->top() != "#")   //如果队头和栈顶的元素都为#号则表示表达式计算结束 
	{
	    if ( che->isopr(nowopr) )  // 判断是操作符还是数字 
		{
		    char rel = che->relation(StaOpr->top(),nowopr); //判断栈顶操作符和当前操作符的优先级 
		    
			if (rel == '<')  //栈顶操作符的优先级低于当前操作符的优先级 把当前操作符入操作符栈
            {
            	StaOpr->push(nowopr);    
            	nowopr = data->front();
            	data->pop();
            }		    
            if (rel == '=')  //优先级相同 表示括号匹配出栈 
            {
            	StaOpr->pop();   
            	nowopr = data->front();
				data->pop(); 
            }
            if (rel == '>') //栈顶操作符优先级大于当前操作符，则取出栈顶操作符进行计算 
            {
            	double sum1 = 0;
				double sum2 = 0;
				double temp = 0;
            	string oprt = "\0";
            	
            	if (!StaNum->empty())
            	{
            	    sum2 = StaNum->top();  //数字栈的栈顶是第二个数字 
            	    StaNum->pop();
            	}
            	else
            	{
            		error = 3;
            	}
            	if (!StaNum->empty())
            	{
            	    sum1 = StaNum->top();
            	    StaNum->pop();
                }
                else
                {
                	error = 3;
                }
                if (!StaOpr->empty())
                {
				    oprt = StaOpr->top();
            	    StaOpr->pop();
                }
				else
				{
					error = 3;
				} 
				if (error == 0)
				{
					temp = oper->Operate(sum1,sum2,oprt);  // 计算结果 
				}
				
            	if (temp > N) 
            	{
            		error = 1;
            	}
            	if (oprt == "/" && sum2 == 0)
            	{
            		error = 2;
            	} 
            	
            	StaNum->push(temp);  //把结果录入数字栈 
            }
		}        
	    else  // 如果是数字 
	    {
	    	StaNum->push(oper->ChangeToNum(nowopr)); // 把字符串转为数字并入栈 
	    	nowopr = data->front();   
	    	data->pop();
	    }
	    if (error)
	    {
	    	break;
	    }
	}
}

int Calculation::ReturnAnser()
{
	if (error)
	{
		return 0;
	}
	else
	{
		return StaNum->top();
	}
}
int Calculation::ReturnError()
{
	return error;
}

