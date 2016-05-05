 /************************************************************ 
  FileName: checkrelation.h 

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               判断操作符之间的优先级
			   判断当前字符是操作符还是数字 

  Function List:
            
			    isnum() relation()  用于判断优先级
				isopr() 用于确定是否是操作符 

*************************************************************/ 
#ifndef CHECKRELATION_H
#define CHECKRELATION_H

#include <iostream>
#include <string>

using namespace std;

class CheckRelation
{
	private:
		/*运算符的优先级关系  
                                 //'+', '-', '*', '/', '(', ')', '#'   
        char OprRelation[7][7] = {{'>', '>', '<', '<', '<', '>', '>'},  //'+'  
                                  {'>', '>', '<', '<', '<', '>', '>'},  //'-'  
                                  {'>', '>', '>', '>', '<', '>', '>'},  //'*'  
                                  {'>', '>', '>', '>', '<', '>', '>'},  //'/'  
                                  {'<', '<', '<', '<', '<', '=', ' '},  //'('  
                                  {'>', '>', '>', '>', ' ', '>', '>'},  //')'  
                                  {'<', '<', '<', '<', '<', ' ', '='}}; //'#'    */

        string OprRelation[7];
		int num[300];
		 
	public:
		CheckRelation();
		~CheckRelation();
		int isnum(string opr);
		char relation(string opr1,string opr2);
		bool isopr(string opr);
		
	protected:
};

#endif
