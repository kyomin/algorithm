#include <iostream>

using namespace std;

int solution(int a, int b) {
	int result = a;

	// 1�� �ڸ��� ����Ѵ�.
	for (int i = 2; i <= b; i++)
		result = (result*a) % 10;

	// ���� 1�� �ڸ��� 0�̸� 10��° ��ǻ���� ����̴�.
	if (result == 0)
		result = 10;

	// �� �ܿ��� ���� �ڸ��� ��Ī�Ǵ� ��ǻ���̴�.
	return result;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int a, b;
		cin >> a >> b;

		cout << solution(a, b) << '\n';
	}

	return 0;
}