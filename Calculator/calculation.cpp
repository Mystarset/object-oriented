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
	while (!StaNum->empty())    //���ջ 
    {
    	StaNum->pop();
    }
    
    while (!StaOpr->empty())    //���ջ 
    {
    	StaOpr->pop();
    }
    
    delete StaNum;
    delete StaOpr;
}


void Calculation::NumCalculator(queue<string> *data)
{
	data->push("#");    //�ڶ�ͷ��β������һ��#�ţ������жϱ��ʽ�Ƿ������� 
	StaOpr->push("#");
	
    string nowopr = data->front();  // nowopr Ϊ��ǰ��ͷ��Ԫ�� 
    data->pop();
    
	while (nowopr != "#" || StaOpr->top() != "#")   //�����ͷ��ջ����Ԫ�ض�Ϊ#�����ʾ���ʽ������� 
	{
	    if ( che->isopr(nowopr) )  // �ж��ǲ������������� 
		{
		    char rel = che->relation(StaOpr->top(),nowopr); //�ж�ջ���������͵�ǰ�����������ȼ� 
		    
			if (rel == '<')  //ջ�������������ȼ����ڵ�ǰ�����������ȼ� �ѵ�ǰ�������������ջ
            {
            	StaOpr->push(nowopr);    
            	nowopr = data->front();
            	data->pop();
            }		    
            if (rel == '=')  //���ȼ���ͬ ��ʾ����ƥ���ջ 
            {
            	StaOpr->pop();   
            	nowopr = data->front();
				data->pop(); 
            }
            if (rel == '>') //ջ�����������ȼ����ڵ�ǰ����������ȡ��ջ�����������м��� 
            {
            	double sum1 = 0;
				double sum2 = 0;
				double temp = 0;
            	string oprt = "\0";
            	
            	if (!StaNum->empty())
            	{
            	    sum2 = StaNum->top();  //����ջ��ջ���ǵڶ������� 
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
					temp = oper->Operate(sum1,sum2,oprt);  // ������ 
				}
				
            	if (temp > N) 
            	{
            		error = 1;
            	}
            	if (oprt == "/" && sum2 == 0)
            	{
            		error = 2;
            	} 
            	
            	StaNum->push(temp);  //�ѽ��¼������ջ 
            }
		}        
	    else  // ��������� 
	    {
	    	StaNum->push(oper->ChangeToNum(nowopr)); // ���ַ���תΪ���ֲ���ջ 
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

