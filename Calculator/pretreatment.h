 /************************************************************ 
  FileName: Main.h  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               对一些比较奇怪的表达式预处理成规范的表达式 

  Function List:
            
			   yuchuli() 预处理
			   BackStringQueue() 返回处理后的数据 

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
