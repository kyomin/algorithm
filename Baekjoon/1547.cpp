#include <iostream>

using namespace std;

int main() {
	int T;
	cin >> T;

	// ó�� ���� �ִ� ���� ��ȣ
	int mark = 1;

	for (int i = 0; i < T; i++) {
		int n1, n2;
		cin >> n1 >> n2;

		if (n1 == mark)
			mark = n2;
		else if (n2 == mark)
			mark = n1;
	}

	cout << mark << endl;

	return 0;
}