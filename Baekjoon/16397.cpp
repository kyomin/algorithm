#include <iostream>
#include <queue>
#include <string>

using namespace std;

int N, T, G;

bool check[100000] = { false, };

int calc_pow(int x, int y) {
	if (y == 0)
		return 1;

	return x * calc_pow(x, y - 1);
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> T >> G;

	// first : ����, second : Ƚ��
	queue<pair<int, int>> q;

	q.push(make_pair(N, 0));

	check[N] = true;

	while (!q.empty()) {
		int n = q.front().first;
		int curCount = q.front().second;

		q.pop();

		// Ƚ���� �Ѿ ������ fail!
		if (curCount > T) {
			cout << "ANG" << '\n';
			return 0;
		}

		// ��ǥ ���ڿ� �����ϸ� ����!
		if (n == G) {
			cout << curCount << '\n';
			return 0;
		}

		/*
			��ư 2���� ����� ���� ������.
		*/

		// A ��ư
		if (n + 1 < 100000 && !check[n + 1]) {
			q.push(make_pair(n + 1, curCount + 1));

			check[n + 1] = true;
		}

		// B ��ư
		if (n * 2 < 100000) {
			string temp = to_string(n * 2);

			// ������ �ڸ����� ��´�.
			int len = temp.size();

			temp[0] = (char)(temp[0] - 1);

			int result = 0;

			for (int i = 0; i < len; i++) {
				if ((int)(temp[i] - '0') == 0)
					continue;

				result += (int)(temp[i] - '0')*calc_pow(10, len - i - 1);
			}

			if (result < 100000 && !check[result]) {
				q.push(make_pair(result, curCount + 1));

				check[result] = true;
			}
		}
	}

	cout << "ANG" << '\n';

	return 0;
}