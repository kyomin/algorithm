#include <iostream>
using namespace std;

int main() {
	int count = 0;
	int N;
	cin >> N;

	// a(a + b + c - 1) = 0
	// => a = 0 || a + b + c = 1
	for (int a = -N; a <= N; ++a) {
		if (a == 0)
			continue;

		for (int b = -N; b <= N; ++b) {
			// a + b + c = 1 �Ŀ���
			// c�� ����ϰ� ������ ����ȭ
			int c = 1 - a - b;
			
			if (c >= -N && c <= N)
				++count;			
		}
	}

	// a�� 0�� ��� b, c�� ����� �� ���ϱ�
	count += (2 * N + 1)*(2 * N + 1);

	cout << count << endl;

	return 0;
}