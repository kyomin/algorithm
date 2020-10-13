#include <iostream>
#include <cstring>
#include <string>

using namespace std;

int main() {
	char arr[80];
	int T;
	cin >> T;

	int * ptr = new int[T];

	for (int i = 0; i < T; i++) {
		int sum = 0;
		int score = 0;
		cin >> arr;
		int len = strlen(arr);

		// 길이를 만족한다면
		if ((0 < len) && (len < 80)) {
			for (int j = 0; j < len; j++) {
				if (arr[j] == 'O') {
					score++;
					sum += score;
				}
				else if (arr[j] == 'X')
					score = 0;
			}
		}

		ptr[i] = sum;
	}

	for (int i = 0; i < T; i++)
		cout << ptr[i] << endl;

	return 0;
}