#include <iostream>
#include <vector>
using namespace std;

int main() {
	// ������ 9�ܱ��� �����ϴ� ���� 81 ����
	vector<bool> check(82, false);

	// �����ϴ� ��� ���� üŷ�Ѵ�.
	for (int i = 2; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			int mul = i * j;

			check[i] = true;
			check[j] = true;
			check[mul] = true;
		}
	}

	int N;
	cin >> N;

	if (check[N]) {
		cout << 1 << endl;
	}
	else {
		cout << 0 << endl;
	}

	return 0;
}