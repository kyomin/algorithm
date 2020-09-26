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
		// 맞았다면
		if (arr[i] == 1) {
			// 앞에서 맞았는지 확인
			if (arr[i - 1] == 1)
				curScore++;
			else
				curScore = 1;

			sum += curScore;
		}
		else {	// 틀렸다면
			curScore = 0;
		}
	}

	cout << sum << endl;

	return 0;
}