#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> line(N, -1);

	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;

		int cnt = 0;

		for (int j = 0; j < N; j++) {
			if (line[j] != -1) {
				continue;
			}

			// ºó Ä­ÀÌ¶ó¸é
			if (line[j] == -1) {
				cnt++;

				if (cnt - 1 == num) {
					line[j] = i;

					break;
				}
			}
		}
	}

	for (int i = 0; i < N; i++) {
		cout << line[i] << ' ';
	}

	return 0;
}