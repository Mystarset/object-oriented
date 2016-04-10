 /************************************************************ 
  FileName: Main.cpp  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
                对读入的队列进行操作，计算出表达式的值 

  Function List:
            
			   NumCalculator()   计算表达式
			   PrintAnser()      输出答案 

*************************************************************/ 
#include "Calculation.h"
#include "CheckRelation.h"
#include "Operation.h"

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
	StaNum->push(0);    //在数字栈读入一个0，以防止  -()   这种形式的表达式无法计算 
	
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
            	double sum2 = StaNum->top();  //数字栈的栈顶是第二个数字 
            	StaNum->pop();
            	double sum1 = StaNum->top();
            	StaNum->pop();
            	string oprt = StaOpr->top();
            	StaOpr->pop();
            	double temp = oper->Operate(sum1,sum2,oprt);  // 计算结果 
            	
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
void Calculation::PrintAnser()
{
	if (error == 1) 
	{
		printf("数字超出运算范围\n"); 
	}

    if (error == 2)
    {
        printf("数字被零除\n");
    }
    
    if (error == 0)
	{
	    cout << StaNum->top() << endl;   //输出 
    } 

}
