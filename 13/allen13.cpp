#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

static const int NUMSIZE = 50;
static const int NUMELEM = 100;

int main(){
	string num;
	vector<string> numList;
	ifstream number("numbers.txt");
	if (number.is_open()){
		while (number >> num){
			numList.push_back(num);
		}
		number.close();
	}

	string answer = "";

	int sum = 0;
	int carry = 0;

	for (int i = NUMSIZE-1; i >= 0; i--)
	{
		sum = carry;
	 	for (int j = 0; j < NUMELEM; j++)
		{
			sum += numList[j][i] - 48;
		}
		answer += to_string(sum % 10);
		carry = sum / 10;
	}

	while (carry > 0){
		answer += to_string(carry % 10);
		carry /= 10;
	}

	int numDigits = answer.length();
	for (int i = 0; i < 10; ++i)
	{
		cout << answer[numDigits - i - 1];
	}

	cout << endl;

	return 0;
}