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
