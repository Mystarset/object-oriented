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

int CheckRelation::isnum(string opr)  // ת�������ȼ������Ӧ������ 
{
    return (num[opr[0]]);
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
