#include <iostream>
#include <deque>
using namespace std;

// first: index
// second: value
typedef pair<int, int> Node;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, L;
	cin >> N >> L;
	deque<Node> dq;

	for (int i = 0; i < N; i++) {
		int curVal;
		cin >> curVal;

		// 값이 들어올 때마다 정렬하지 않고
		// 현재 수보다 큰 값을 덱에서 제거하여 시간 복잡도 줄임
		while (dq.size() && dq.back().second > curVal)
			dq.pop_back();

		dq.push_back(Node(i, curVal));

		// 슬라이딩 윈도우 크기에서 벗어난 값은 덱에서 제거
		if (dq.front().first <= i - L)
			dq.pop_front();

		cout << dq.front().second << ' ';
	}

	return 0;
}