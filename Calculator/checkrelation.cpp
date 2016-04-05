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
#include <string>

CheckRelation::CheckRelation()
{
	OprRelation[0] = ">><<<>>";
	OprRelation[1] = ">><<<>>";
	OprRelation[2] = ">>>><>>";
	OprRelation[3] = ">>>><>>";
	OprRelation[4] = "<<<<<= ";
	OprRelation[5] = ">>>> >>";
	OprRelation[6] = "<<<<< =";
	
	num['+'] = 0; num['-'] = 1; num['*'] = 2; num['/'] = 3;
	num['('] = 4; num[')'] = 5; num['#'] = 6;
}

CheckRelation::~CheckRelation()
{
}

int CheckRelation::isnum(string opr)  // 转化成优先级数组对应的数字 
{
    return (num[opr[0]]);
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
