#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	vector<int> v;
	vector<int> result;
	unsigned long sum = 0;
	int A, B, m;
	cin >> A >> B >> m;

	// �� �ڸ����� ���� �Է�
	for (int i = 0; i < m; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	// A ������ 10������ �ٲٴ� �۾�!
	for (int i = 0; i < m; i++) {
		int x = m - i - 1;
		sum += v[i] * (int)pow(A, x);
	}

	// 10������ B�������� �ٲٴ� �۾�
	while (sum >= B) {
		int r = sum % B;
		sum /= B;
		result.push_back(r);
	}

	result.push_back(sum);
	int len = result.size();

	for (int i = len - 1; i >= 0; i--)
		cout << result[i] << " ";

	cout << endl;

	return 0;
}