#include <iostream>
#include <string>
using namespace std;

int checkArr[4];		// 비밀번호 체크 배열
int curStateArr[4];		// 현재 상태 배열
int checkSecret = 0;	// 몇 개의 문자에 대한 개수를 충족했는지 판단하는 변수

// 새로 들어온 문자 처리 함수
void addChar(char c) {
	switch (c) {
	case 'A': {
		curStateArr[0]++;
		if (curStateArr[0] == checkArr[0])
			checkSecret++;
		break;
	}
	case 'C': {
		curStateArr[1]++;
		if (curStateArr[1] == checkArr[1])
			checkSecret++;
		break;
	}
	case 'G': {
		curStateArr[2]++;
		if (curStateArr[2] == checkArr[2])
			checkSecret++;
		break;
	}
	case 'T': {
		curStateArr[3]++;
		if (curStateArr[3] == checkArr[3])
			checkSecret++;
		break;
	}
	}
}

// 제거할 문자를 처리하는 함수
void removeChar(char c) {
	switch (c) {
	case 'A': {
		if (curStateArr[0] == checkArr[0])
			checkSecret--;
		curStateArr[0]--;
		break;
	}
	case 'C': {
		if (curStateArr[1] == checkArr[1])
			checkSecret--;
		curStateArr[1]--;
		break;
	}
	case 'G': {		
		if (curStateArr[2] == checkArr[2])
			checkSecret--;
		curStateArr[2]--;
		break;
	}
	case 'T': {
		if (curStateArr[3] == checkArr[3])
			checkSecret--;
		curStateArr[3]--;
		break;
	}
	}
}

int main() {
	int S, P;
	cin >> S >> P;

	int result = 0;
	string dnaStr;
	cin >> dnaStr;

	for (int i = 0; i < 4; i++) {
		cin >> checkArr[i];

		if (checkArr[i] == 0)
			checkSecret++;
	}

	// 초기 P 부분 문자열 처리
	for (int i = 0; i < P; i++)
		addChar(dnaStr[i]);

	if (checkSecret == 4)
		result++;

	// 슬라이딩 윈도우 처리
	for (int i = P; i < S; i++) {
		int j = i - P;

		addChar(dnaStr[i]);
		removeChar(dnaStr[j]);

		if (checkSecret == 4)
			result++;
	}

	cout << result << endl;

	return 0;
}