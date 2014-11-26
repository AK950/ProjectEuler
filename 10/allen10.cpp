#include <iostream>
#include <cmath>

using std::cout;
using std::endl;

int main(){
	static const unsigned long SIZE = 2000000;
	bool A[SIZE+1];
	for (int i = 2; i < SIZE+1; ++i)
	{
		A[i] = true;
	}
	for (int i = 2; i < sqrt(SIZE+1); ++i)
	{
		if (A[i]==true){
			for (int j = i*i; j < SIZE+1; j+=i)
			{
				A[j] = false;
			}
		}
	}
	unsigned long answer = 0;
	for (int i = 2; i < SIZE+1; ++i)
	{
		if (A[i]==true){
			answer += i;
		}
	}
	cout << answer << endl;
	return 0;
}