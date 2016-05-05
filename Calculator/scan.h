 /************************************************************ 
  FileName: scan.cpp  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               对接收的数据进行判断格式是否正确，并将数据分块的一个个放入队列中
			   对负数和减号进行区分 

  Function List:
            
			   Scan () 对变量初始化
			   ~Scan () 清空队列
			   ToStringQueue() 逐个扫描字符串，判断输入数据准确性的同时把数据分开放入队列
			   BackStringQueue 返回队列的值 

*************************************************************/ 

#include <queue>
#include <string>

#ifndef SCAN_H
#define SCAN_H

using namespace std;

class Scan
{
    private:
		queue<string> *que = new queue<string>;
		bool error;
	
	public:
		Scan();
		~Scan();
		
		void ToStringQueue(string input);
		
		queue<string> *BackStringQueue();
		
		
	protected:
};

#endif
