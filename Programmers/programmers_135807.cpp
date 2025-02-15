#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool isAllDivided(vector<int> &arr, int num) {
	bool flag = true;
	int len = arr.size();

	for (int i = 0; i < len; i++) {
		int n = arr[i];

		if (n%num != 0) {
			flag = false;
			break;
		}
	}

	return flag;
}

bool isNotAllDivided(vector<int> &arr, int num) {
	bool flag = true;
	int len = arr.size();

	for (int i = 0; i < len; i++) {
		int n = arr[i];

		if (n%num == 0) {
			flag = false;
			break;
		}
	}

	return flag;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int answer = 0;

	sort(arrayA.begin(), arrayA.end());
	sort(arrayB.begin(), arrayB.end());

	int minA = arrayA[0];
	int minB = arrayB[0];

	// A 최솟값 기준으로 답 찾기
	for (int i = minA; i >= 2; i--) {
		if ((isAllDivided(arrayA, i) && isNotAllDivided(arrayB, i)) ||
			(isAllDivided(arrayB, i) && isNotAllDivided(arrayA, i))) {
			answer = i;
			break;
		}
	}

	// B 최솟값 기준으로 답 찾기
	for (int i = minB; i >= 2; i--) {
		if ((isAllDivided(arrayA, i) && isNotAllDivided(arrayB, i)) ||
			(isAllDivided(arrayB, i) && isNotAllDivided(arrayA, i))) {
			answer = max(answer, i);
			break;
		}
	}

	return answer;
}