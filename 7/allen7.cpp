#include <iostream>
#include<vector>
#include <cmath>

using std::cout;
using std::endl;
using std::vector;

vector<unsigned long> primes;

bool isPrime(unsigned long n){
	for (unsigned long j = 0; j < primes.size() && primes[j] < n/2; j++)
	{
		if (n % primes[j] == 0){
			return false;
		}
	}
	primes.push_back(n);
	return true;
}

int main(){
	primes.push_back(2);
	int count = 1;
	int num = 1;
	while (count < 10001){
		num += 2;
		if (isPrime(num)){
			++count;
		}
	}
	cout << num << endl;
	return 0;
}