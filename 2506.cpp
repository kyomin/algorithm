#include <iostream>

using namespace std;

int arr[100];

int main() {
	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	int sum = arr[0];

	int curScore = arr[0];

	for (int i = 1; i < N; i++) {
		// �¾Ҵٸ�
		if (arr[i] == 1) {
			// �տ��� �¾Ҵ��� Ȯ��
			if (arr[i - 1] == 1)
				curScore++;
			else
				curScore = 1;

			sum += curScore;
		}
		else {	// Ʋ�ȴٸ�
			curScore = 0;
		}
	}

	cout << sum << endl;

	return 0;
}