#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;

	vector<bool> check(N, false);	// �ܹ��� �Ծ����� üũ
	string str;
	cin >> str;

	for (int i = 0; i < N; i++) {		
		// ����̸�
		if (str[i] == 'P') {
			int start = (i - K) >= 0 ? (i - K) : 0;
			bool flag = false;

			for (int j = start; j < i; j++) {
				// �ܹ����̰�, �� �Ծ�����
				if (str[j] == 'H' && !check[j]) {
					check[j] = true;
					flag = true;

					break;
				}
			}

			if (flag) {
				continue;
			}

			// ���ʿ��� �ܹ��Ÿ� �� �Ծ����� ������ Ž��
			int end = (i + K) < N ? (i + K) : N - 1;

			for (int j = i + 1; j <= end; j++) {
				// �ܹ����̰�, �� �Ծ�����
				if (str[j] == 'H' && !check[j]) {
					check[j] = true;

					break;
				}
			}
		}
	}

	int count = 0;
	for (int i = 0; i < N; i++) {
		if (check[i]) {
			count++;
		}
	}

	cout << count << endl;

	return 0;
}