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

		// ���� ���� ������ �������� �ʰ�
		// ���� ������ ū ���� ������ �����Ͽ� �ð� ���⵵ ����
		while (dq.size() && dq.back().second > curVal)
			dq.pop_back();

		dq.push_back(Node(i, curVal));

		// �����̵� ������ ũ�⿡�� ��� ���� ������ ����
		if (dq.front().first <= i - L)
			dq.pop_front();

		cout << dq.front().second << ' ';
	}

	return 0;
}