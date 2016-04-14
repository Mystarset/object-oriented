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
