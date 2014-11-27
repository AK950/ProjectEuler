#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

static const unsigned long ADJACENT = 4;
static const unsigned long ROW = 20;
static const unsigned long COLUMN = 20;

unsigned long productAcross(vector< vector<unsigned long> > numbers, unsigned long row, unsigned long column){
	unsigned long prod = 1;
	for (int i = column; i < column+ADJACENT; ++i)
	{
		prod *= numbers[row][i];
	}
	return prod;
}

unsigned long productVertical(vector< vector<unsigned long> > numbers, unsigned long row, unsigned long column){
	unsigned long prod = 1;
	for (int i = row; i < row+ADJACENT; ++i)
	{
		prod *= numbers[i][column];
	}
	return prod;
}

unsigned long productDiagonalRight(vector< vector<unsigned long> > numbers, unsigned long row, unsigned long column){
	unsigned long prod = 1;
	int i = row;
	int j = column;
	while (i < row+ADJACENT){
		prod *= numbers[i][j];
		++i;
		++j;
	}
	return prod;
}

unsigned long productDiagonalLeft(vector< vector<unsigned long> > numbers, unsigned long row, unsigned long column){
	unsigned long prod = 1;
	int i = row;
	int j = column;
	while (i < row+ADJACENT){
		prod *= numbers[i][j];
		++i;
		--j;
	}
	return prod;
}

int main(){
	vector< vector<unsigned long> > A;
	unsigned long i = 0;
	unsigned long j = 0;
	unsigned long num;
	vector<unsigned long> temp;
	ifstream number("numbers.txt");
	if (number.is_open()){
		while (number >> num){
			temp.push_back(num);
			if (j == COLUMN-1){
				j = 0;
				++i;
				A.push_back(temp);
				temp.clear();
			}
			else{
				++j;
			}
		}
		number.close();
	}
	unsigned long answer = 0;
	for (int i = 0; i < ROW; ++i)
	{
		for (int j = 0; j < COLUMN-ADJACENT+1; ++j)
		{
			unsigned long guess = productAcross(A,i,j);
			if (guess > answer)
				answer = guess;
		}
	}
	for (int i = 0; i < ROW-ADJACENT+1; ++i)
	{
		for (int j = 0; j < COLUMN; ++j)
		{
			unsigned long guess = productVertical(A,i,j);
			if (guess > answer)
				answer = guess;
		}
	}
	for (int i = 0; i < ROW-ADJACENT+1; ++i)
	{
		for (int j = 0; j < COLUMN-ADJACENT+1; ++j)
		{
			unsigned long guess = productDiagonalRight(A,i,j);
			if (guess > answer)
				answer = guess;
		}
	}
	for (int i = 0; i < ROW-ADJACENT+1; ++i)
	{
		for (int j = ADJACENT-1; j < COLUMN; ++j)
		{
			unsigned long guess = productDiagonalLeft(A,i,j);
			if (guess > answer)
				answer = guess;
		}
	}
	cout << answer << endl;

	return 0;
}