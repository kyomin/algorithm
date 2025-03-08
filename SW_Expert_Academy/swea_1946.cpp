#include <iostream>
#include <string>
using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int N;
		cin >> N;

		string str = "";

		for (int i = 0; i < N; i++) {
			char C;
			int K;

			cin >> C >> K;

			for (int k = 0; k < K; k++)
				str += C;
		}

		cout << '#' << t << endl;

		for (int i = 0; i < str.length(); i += 10) {
			for (int j = i; j < i + 10; j++) {
				if (j >= str.length())
					break;

				cout << str[j];
			}

			cout << endl;
		}
	}

	return 0;
}