 /************************************************************ 
  FileName: checkrelation.h 

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               �жϲ�����֮������ȼ�
			   �жϵ�ǰ�ַ��ǲ������������� 

  Function List:
            
			    isnum() relation()  �����ж����ȼ�
				isopr() ����ȷ���Ƿ��ǲ����� 

*************************************************************/ 
#ifndef CHECKRELATION_H
#define CHECKRELATION_H

#include <iostream>
#include <string>

using namespace std;

class CheckRelation
{
	private:
		/*����������ȼ���ϵ  
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
