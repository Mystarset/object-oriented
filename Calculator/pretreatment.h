 /************************************************************ 
  FileName: Main.h  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               ��һЩ�Ƚ���ֵı��ʽԤ����ɹ淶�ı��ʽ 

  Function List:
            
			   yuchuli() Ԥ����
			   BackStringQueue() ���ش��������� 

*************************************************************/ 
#ifndef PRETREATMENT_H
#define PRETREATMENT_H

#include <string>
#include <queue> 
using namespace std;

class Pretreatment
{
	private:
		string input[10001];
		queue<string> *backque = new queue<string>;
		
	public:
		Pretreatment();
		~Pretreatment();
		
		void yuchuli(queue<string> *inque);
		queue<string> *BackStringQueue();
		
	protected:
};

#endif
