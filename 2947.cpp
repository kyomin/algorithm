#include <iostream>

using namespace std;

int main() {
	int arr[6];

	for (int i = 1; i <= 5; i++)
		cin >> arr[i];

	while (true) {
		bool escape = false;

		for (int i = 1; i < 5; i++) {
			// ���ǿ� �ɸ���
			if (arr[i] > arr[i + 1]) {
				// swap
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;

				bool judge = true;

				// �۾� �� ���
				for (int j = 1; j <= 5; j++) {
					if (arr[j] != j)
						judge = false;

					cout << arr[j] << ' ';
				}

				cout << '\n';

				if (judge) {
					escape = true;
					break;
				}
			}
		}

		if (escape)
			break;
	}

	return 0;
}