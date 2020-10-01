#include <iostream>
#include <vector>

using namespace std;

typedef long long ll;

ll d[100][21];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	n -= 1;		// ������ ���� ���� �Է¹ޱ� ���� 1�� ����.

	vector<int> nums(n);

	for (int i = 0; i < n; i++)
		cin >> nums[i];

	int last;
	cin >> last;	// ������ �� �Է¹���

	// ù ��° ���� ���� ó��
	d[0][nums[0]] = 1;

	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= 20; j++) {
			if (j - nums[i] >= 0)
				d[i][j] += d[i - 1][j - nums[i]];

			if (j + nums[i] <= 20)
				d[i][j] += d[i - 1][j + nums[i]];
		}
	}

	// n-1��°���� ���� last�� ���� �� �ִ� ����� ������ ����
	cout << d[n - 1][last] << endl;

	return 0;
}