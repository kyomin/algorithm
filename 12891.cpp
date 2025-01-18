#include <iostream>
#include <string>
using namespace std;

int checkArr[4];		// ��й�ȣ üũ �迭
int curStateArr[4];		// ���� ���� �迭
int checkSecret = 0;	// �� ���� ���ڿ� ���� ������ �����ߴ��� �Ǵ��ϴ� ����

// ���� ���� ���� ó�� �Լ�
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

// ������ ���ڸ� ó���ϴ� �Լ�
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

	// �ʱ� P �κ� ���ڿ� ó��
	for (int i = 0; i < P; i++)
		addChar(dnaStr[i]);

	if (checkSecret == 4)
		result++;

	// �����̵� ������ ó��
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