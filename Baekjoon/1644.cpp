#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int N;
	cin >> N;

	bool *C = new bool[N + 1];

	for (int i = 2; i <= N; i++)
		C[i] = false;

	for (int i = 2; i <= N; i++) {
		if (C[i] == false) {
			// �Ҽ� ���!
			v.push_back(i);

			for (int j = i * 2; j <= N; j += i)
				C[j] = true;
		}
	}

	/*
	 ���� �����佺�׳׽��� ü �˰����� ����������
	 ���� v�� N������ �Ҽ����� ����.
	 */

	// �� ������ �˰����� ���� ������ ����!
	int len = v.size();
	int s = 0, e = 0;
	int sum = 0;
	int count = 0;

	// �����Ͱ� �迭 �ε��� ������ ���� ������
	while (e < len || s < len) {
		if (sum < N) {
			if (e == len)
				break;

			sum += v[e];

			e += 1;

			if (sum == N)
				count++;
		}
		else {
			sum -= v[s];
			s += 1;

			if (sum == N)
				count++;
		}
	}

	cout << count << endl;

	return 0;
}