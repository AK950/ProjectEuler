#include <iostream>

using std::cout;
using std::endl;

int gcf(int, int);

int main(){
	int answer = 1;
	for (int i = 20; i > 0; --i)
	{
		answer *= i/gcf(answer,i);
	}
	cout << answer << endl;
	return 0;
}

int gcf(int a, int b){
	if (b==0)
		return a;
	return gcf(b,a % b);
}