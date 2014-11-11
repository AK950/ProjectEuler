#include <iostream>
#include <time.h>
using std::cout;
using std::endl;


int main() {

	int sum = 0;
	// Loop through all natural numbers
	for (int i = 1; i < 1000; i++)
	{
		if (!(i%3) || !(i%5))
			sum += i;
	}

	cout << sum << endl;

	return 0;
}
