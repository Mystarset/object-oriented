 /************************************************************ 
  FileName: Main.cpp  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               �жϲ�����֮������ȼ�
			   �жϵ�ǰ�ַ��ǲ������������� 

  Function List:
            
			    isnum() relation()  �����ж����ȼ�
				isopr() ����ȷ���Ƿ��ǲ����� 

*************************************************************/ 
#include "checkrelation.h"

CheckRelation::CheckRelation()
{
}

CheckRelation::~CheckRelation()
{
}
int CheckRelation::isnum(string opr)  // ת�������ȼ������Ӧ������ 
{
    if (opr == "+") 
	{
	    return 0;
    }
	if (opr == "-") 
	{
		return 1;
	}
    if (opr == "*")
	{
        return 2;
    }
	if (opr == "/") 
	{
	    return 3;
    }
	if (opr == "(")
	{
		return 4;
	}
	if (opr == ")")
	{
		return 5;
	}
	if (opr == "#")
	{
		return 6;
	}
}
char CheckRelation::relation(string opr1,string opr2)
{
    return OprRelation[isnum(opr1)][isnum(opr2)];  // ���ز�����֮������ȼ���ϵ 
}
bool CheckRelation::isopr(string opr)
{
	if (opr == "+" || opr == "-" || opr == "*" 
	   || opr == "/" || opr == "#" || opr == "(" || opr == ")")
	{
		return true;
	}
	return false;
}
