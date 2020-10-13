#include <iostream>
#include <string>

using namespace std;

// �Ҽ� �Ǵ� �Լ�
bool prime(int n) {
	if (n < 2)
		return false;

	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false;

	return true;
}

int main() {
	int min;
	int sum = 0;
	int M, N;
	cin >> M >> N;

	for (int i = M; i <= N; i++) {
		if (prime(i)) {
			// ���ʷ� �߰ߵ� �Ҽ����!
			if (sum == 0)
				min = i;

			sum += i;
		}
	}

	// �Ҽ��� �߰ߵ��� �ʾ� ���� 0�̶��
	if (sum == 0)
		cout << -1 << endl;
	else
	{
		cout << sum << endl;
		cout << min << endl;
	}

	return 0;
}