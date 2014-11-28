#include <iostream>
#include <cmath>
#include <map>

using namespace std;

unsigned long numDivisors(unsigned long n){
	map<unsigned long,unsigned long> primeCount;
	unsigned long numDiv = 1;
	unsigned long bound = sqrt(n);
	unsigned long number = n;
	while (number % 2 == 0){
		primeCount[2]++;
		number /= 2;
	}
	for (int i = 3; i < bound; i+=2)
	{
		while (number % i == 0){
			primeCount[i]++;
			number /= i;
		}
	}
	if (number > 1){
		primeCount[number]++;
	}

	for (map<unsigned long,unsigned long>::iterator i = primeCount.begin(); i != primeCount.end(); ++i)
	{
		numDiv *= (i->second + 1);
	}
	return numDiv;
}

int main(){
	unsigned long divisors = 0;
	unsigned long n = 1;
	unsigned long answer = 0;
	while (divisors <= 500){
		answer = n*(n+1)/2;
		divisors = numDivisors(answer);
		n++;
	}

	cout << answer << endl;

	return 0;
}