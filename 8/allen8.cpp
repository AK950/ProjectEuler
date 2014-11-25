#include <iostream>
#include <fstream>
#include <string>

using namespace std;

static const unsigned long ADJACENT = 13;

unsigned long product(unsigned long* numbers, int index){
	unsigned long prod = 1;
	for (int i = index; i < index+ADJACENT; ++i)
	{
		prod *= numbers[i];
	}
	return prod;
}

int checkZero(unsigned long* numbers, int index){
	int location = -1;
	for (int i = index; i < index+ADJACENT; ++i)
	{
		if (numbers[i] == 0){
			location = i;
		}
	}
	return location;
}

int main () {
	string line;
	ifstream number ("number.txt");
	if (number.is_open()){
		getline(number,line);
		number.close();
	}
	static const unsigned long SIZE = line.size();
	unsigned long digits[SIZE];
	for (int i = 0; i < SIZE; ++i)
	{
		digits[i] = line[i] - '0';
	}

	unsigned long answer = 0;
	int index = 0;
	while (index <= SIZE-ADJACENT){
		int zeroLocation = checkZero(digits,index);
		if (zeroLocation != -1){
			index = zeroLocation+1;
		}
		else{
			unsigned long guess = product(digits,index);
			if (guess > answer)
				answer = guess;
			++index;
		}
	}

	cout << answer << endl;

	return 0;
}