#include <iostream>

using std::cout;
using std::endl;

int sum(int n){
	return (n*(n+1))/2;
}
int sumOfSquares(int n){
	return (n*(n+1)*(2*n+1))/6;
}

int main(){
	int s = sum(100);
	cout << s*s - sumOfSquares(100) << endl;

	return 0;
}