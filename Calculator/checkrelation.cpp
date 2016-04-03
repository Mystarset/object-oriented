 /************************************************************ 
  FileName: Main.cpp  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               判断操作符之间的优先级
			   判断当前字符是操作符还是数字 

  Function List:
            
			    isnum() relation()  用于判断优先级
				isopr() 用于确定是否是操作符 

*************************************************************/ 
#include "checkrelation.h"

CheckRelation::CheckRelation()
{
}

CheckRelation::~CheckRelation()
{
}
int CheckRelation::isnum(string opr)  // 转化成优先级数组对应的数字 
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
    return OprRelation[isnum(opr1)][isnum(opr2)];  // 返回操作符之间的优先级关系 
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
