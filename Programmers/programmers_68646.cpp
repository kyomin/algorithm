#include <vector>

using namespace std;

const int MAX = 1000000000;
int leftMin[1000000];
int rightMin[1000000];

int solution(vector<int> a) {
	int answer = 2;		// 양 끝은 항상 남을 수 있다.
	int len = a.size();
	int left_min = MAX;
	int right_min = MAX;

	// 하나일 경우 처리
	if (len == 1)
		return 1;

	// 두 개일 경우 처리
	if (len == 2)
		return 2;

	// 특정 순간의 왼쪽 부분의 최솟값
	for (int i = 0; i < len; i++) {
		if (left_min > a[i])
			left_min = a[i];

		leftMin[i] = left_min;
	}

	// 특정 순간의 오른쪽 부분의 최솟값
	for (int i = len-1; i >= 0; i--) {
		if (right_min > a[i])
			right_min = a[i];

		rightMin[i] = right_min;
	}

	// 중간 원소들에 대해 처리
	for (int mid = 1; mid < len - 1; mid++) {
		// 양쪽 다 현재보다 작다면 최후까지 남을 수 없다
		if (leftMin[mid] < a[mid] && rightMin[mid] < a[mid])
			continue;

		answer++;
	}

	return answer;
}