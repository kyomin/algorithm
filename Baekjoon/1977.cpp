#include <iostream>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int M, N;
	cin >> M >> N;

	int sum = 0;
	int min = 0;

	for (int i = M; i <= N; i++) {
		// ���� �ּ��� ���������� ó��
		if (i == 1) {
			sum += i;
			
			if (min == 0)
				min = i;
		}
		else {
			for (int j = 2; j*j <= i; j++) {
				// �������������
				if (j*j == i) {
					sum += i;

					if (min == 0)
						min = i;
				}
			}
		}
	}

	// ������������ ã�� ���ߴٸ�
	if (sum == 0)
		cout << -1 << endl;
	else {
		cout << sum << endl;
		cout << min << endl;
	}

	return 0;
}