#include <iostream>

using namespace std;

int main(){
	for (unsigned long a = 1; a < 333; ++a)
	{
		for (unsigned long b = a+1; b < 1000-a-b; ++b)
		{
			unsigned long c = 1000-a-b;
			if (a*a + b*b == c*c){
				cout << a*b*c << endl;
			}
		}
	}
	return 0;
}