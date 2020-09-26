#include <iostream>
#include <algorithm>

using namespace std;

int MAX = -1000000000;
int MIN = 1000000000;
int N;

int arr[12];

void go(int curVal, int nextOperandIdx, char curOperator,
	int plusCnt, int subCnt, int mulCnt, int divCnt) {
	switch (curOperator)
	{
	case '+' :
		curVal += arr[nextOperandIdx];
		break;
	case '-' :
		curVal -= arr[nextOperandIdx];
		break;
	case '*':
		curVal *= arr[nextOperandIdx];
		break;
	case '/':
		curVal /= arr[nextOperandIdx];
		break;
	default:
		break;
	}

	if (nextOperandIdx == N) {
		MAX = max(MAX, curVal);
		MIN = min(MIN, curVal);
		return;
	}

	if (plusCnt != 0) 
		go(curVal, nextOperandIdx + 1, '+', plusCnt - 1, subCnt, mulCnt, divCnt);
	
	if (subCnt != 0)
		go(curVal, nextOperandIdx + 1, '-', plusCnt, subCnt - 1, mulCnt, divCnt);

	if (mulCnt != 0)
		go(curVal, nextOperandIdx + 1, '*', plusCnt, subCnt, mulCnt - 1, divCnt);

	if (divCnt != 0)
		go(curVal, nextOperandIdx + 1, '/', plusCnt, subCnt, mulCnt, divCnt - 1);
}

int main() {
	int plusCnt, subCnt, mulCnt, divCnt;

	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> arr[i];

	cin >> plusCnt >> subCnt >> mulCnt >> divCnt;

	if (plusCnt != 0)
		go(arr[1], 2, '+', plusCnt - 1, subCnt, mulCnt, divCnt);

	if (subCnt != 0)
		go(arr[1], 2, '-', plusCnt, subCnt - 1, mulCnt, divCnt);

	if (mulCnt != 0)
		go(arr[1], 2, '*', plusCnt, subCnt, mulCnt - 1, divCnt);

	if (divCnt != 0)
		go(arr[1], 2, '/', plusCnt, subCnt, mulCnt, divCnt - 1);

	cout << MAX << endl;
	cout << MIN << endl;

	return 0;
}