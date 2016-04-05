#ifndef CHECKRELATION_H
#define CHECKRELATION_H

#include <iostream>
#include <string>

using namespace std;

class CheckRelation
{
	private:
		/*运算符的优先关系  
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
