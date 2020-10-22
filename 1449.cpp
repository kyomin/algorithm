#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	vector<int> position;
	int N, L;
	cin >> N >> L;

	position.resize(N);

	for (int i = 0; i < N; i++)
		cin >> position[i];

	sort(position.begin(), position.end());

	int start = 0;
	int cnt = 0;

	for (auto pos : position) {
		// ������ ���̱� => �� ��ġ�κ��� L-1������ �������� Ŀ���� �����ϴ�.
		if (start < pos) {
			start = pos + L - 1;
			cnt++;
		}
	}

	cout << cnt << '\n';

	return 0;
}