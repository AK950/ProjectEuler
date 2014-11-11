#include <iostream>
#include <math.h>
using std::cout;
using std::endl;


int main() {

	double x = 1 + sqrt(5);
	x = x/2;
	x = x*x*x;
	double y = 1 - sqrt(5);
	y = y/2;
	y = y*y*y;
	double z = 1/sqrt(5);

	int sum = 0;
	double i = 1;
	int a =  nearbyint((z)*(pow(x,i) - pow(y,i)));

	do {
		
		sum += a;
		i++;
		a =  nearbyint((z)*(pow(x,i) - pow(y,i)));
		
	} while (a < 4000000);

	cout << sum << endl;
	
	// Using the fact that F_32 (as per the definition of F_i in the problem)
	// is the last even fibbonacci number less than 4 million,
	// we get a constant time solution - same idea as before but using
	// Geometric series formula
		
	double sumofx = (x - pow(x,12)) / (1-x);
	double sumofy = (y - pow(y,12)) / (1-x);
	int sum_2 = nearbyint(z*(sumofx -sumofy));

	cout << sum_2 << endl;
	
	
	return 0;

}
