#include "calculation.h"
#include <iostream>

using namespace std;

int main(int argc,char* argv[])
{
	double r;
	calculation *cal = new calculation;
	cin >> r;
	double ansarea = cal->calarea(r);
	cout << ansarea << endl;
	return 0;
}
