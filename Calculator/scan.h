 /************************************************************ 
  FileName: scan.cpp  

  Author: Starset        Version :  1.1        Date:  2016.4.3

  Description:      
  
               �Խ��յ����ݽ����жϸ�ʽ�Ƿ���ȷ���������ݷֿ��һ�������������
			   �Ը����ͼ��Ž������� 

  Function List:
            
			   Scan () �Ա�����ʼ��
			   ~Scan () ��ն���
			   ToStringQueue() ���ɨ���ַ������ж���������׼ȷ�Ե�ͬʱ�����ݷֿ��������
			   BackStringQueue ���ض��е�ֵ 

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
