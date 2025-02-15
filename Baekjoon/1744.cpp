#include <iostream>
#include <queue>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	priority_queue<int, vector<int>, less<int>> plusPq;	// 양수를 위한 내림차순 정렬
	priority_queue<int, vector<int>, greater<int>> minusPq;	// 음수를 위한 오름차순 정렬

	int one = 0;	// 1 카운트
	int zero = 0;	// 0 카운트

	for (int i = 0; i < N; i++) {
		int data;
		cin >> data;

		// 4개의 그룹으로 분리해서 저장
		if (data > 1) {
			plusPq.push(data);
		}
		else if (data == 1) {
			one++;
		}
		else if (data == 0) {
			zero++;
		}
		else {
			minusPq.push(data);
		}
	}

	int sum = 0;

	// 양수 처리
	while (plusPq.size() > 1) {
		int first = plusPq.top();
		plusPq.pop();

		int second = plusPq.top();
		plusPq.pop();

		sum += (first * second);
	}

	if (!plusPq.empty()) {
		sum += plusPq.top();
		plusPq.pop();
	}

	// 음수 처리
	while (minusPq.size() > 1) {
		int first = minusPq.top();
		minusPq.pop();

		int second = minusPq.top();
		minusPq.pop();

		sum += (first * second);
	}

	if (!minusPq.empty()) {
		if (zero == 0) {
			sum += minusPq.top();
			minusPq.pop();
		}
	}

	// 1 처리
	sum += one;

	cout << sum << '\n';

	return 0;
}