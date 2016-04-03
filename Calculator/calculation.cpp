 /************************************************************ 
  FileName: Main.cpp  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
                �Զ���Ķ��н��в��������������ʽ��ֵ 

  Function List:
            
			   NumCalculator()   �������ʽ
			   PrintAnser()      ����� 

*************************************************************/ 
#include "Calculation.h"
#include "CheckRelation.h"
#include "Operation.h"

#include <stack>
#include <queue>
#include <string>

using namespace std;

Calculation::Calculation()
{
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
    delete che;
    delete oper;
}


void Calculation::NumCalculator(queue<string> *data)
{
	data->push("#");    //�ڶ�ͷ��β������һ��#�ţ������жϱ���ʽ�Ƿ������� 
	StaOpr->push("#");
	StaNum->push(0);    //������ջ����һ��0���Է�ֹ  -()   ������ʽ�ı���ʽ�޷����� 
	
    string nowopr = data->front();  // nowopr Ϊ��ǰ��ͷ��Ԫ�� 
    data->pop();
    
	while (nowopr != "#" || StaOpr->top() != "#")   //�����ͷ��ջ����Ԫ�ض�Ϊ#�����ʾ����ʽ������� 
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
            	double sum2 = StaNum->top();  //����ջ��ջ���ǵڶ������� 
            	StaNum->pop();
            	double sum1 = StaNum->top();
            	StaNum->pop();
            	string oprt = StaOpr->top();
            	StaOpr->pop();
            	double temp = oper->Operate(sum1,sum2,oprt);  // ������ 
            	
            	StaNum->push(temp);  //�ѽ��¼������ջ 
            }
		}        
	    else  // ��������� 
	    {
	    	StaNum->push(oper->ChangeToNum(nowopr)); // ���ַ���תΪ���ֲ���ջ 
	    	nowopr = data->front();   
	    	data->pop();
	    }
	}
}
void Calculation::PrintAnser()
{
	cout << StaNum->top() << endl;   //��� 
}