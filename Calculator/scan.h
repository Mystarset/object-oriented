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
