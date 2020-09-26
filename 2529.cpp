#include <iostream>
#include <string>
#include <vector>

using namespace std;

int K;
string minResult, maxResult;
vector<char> equalNums;
bool minFound = false;
bool maxFound = false;

// 부등호 관계가 옳은지 파악해주는 함수
bool isRightRelation(char equalNum, int n1, int n2) {
	if (equalNum == '<')
		return n1 < n2;
	else
		return n1 > n2;
}

void minDfs(string str, vector<bool> check) {
	if (minFound)
		return;

	int curLen = str.size();

	if (curLen == K + 1) {
		minResult = str;
		minFound = true;
		return;
	}

	char curEqualNum = equalNums[curLen - 1];
	int prevNum = (int)(str[curLen - 1] - '0');

	for (int num = 0; num < 10; num++) {
		if (minFound)
			return;

		if (check[num])
			continue;
		
		if (isRightRelation(curEqualNum, prevNum, num)) 
			minDfs(str + to_string(num), check);
	}
}

void maxDfs(string str, vector<bool> check) {
	if (maxFound)
		return;

	int curLen = str.size();

	if (curLen == K + 1) {
		maxResult = str;
		maxFound = true;
		return;
	}

	char curEqualNum = equalNums[curLen - 1];
	int prevNum = (int)(str[curLen - 1] - '0');

	for (int num = 9; num >= 0; num--) {
		if (maxFound)
			return;

		if (check[num])
			continue;

		if (isRightRelation(curEqualNum, prevNum, num))
			maxDfs(str + to_string(num), check);
	}
}

int main() {
	cin >> K;

	equalNums.resize(K);

	for (int k = 0; k < K; k++)
		cin >> equalNums[k];

	// 최소 결과 탐색
	for (int i = 0; i < 10; i++) {
		vector<bool> check;
		check.assign(10, false);

		check[i] = true;
		minDfs(to_string(i), check);
	}
	
	// 최대 결과 탐색
	for (int i = 9; i >= 0; i--) {
		vector<bool> check;
		check.assign(10, false);

		check[i] = true;
		maxDfs(to_string(i), check);
	}

	cout << maxResult << '\n';
	cout << minResult << '\n';

	return 0;
}