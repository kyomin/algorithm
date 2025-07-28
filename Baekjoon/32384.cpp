#include <iostream>
#include <string>
using namespace std;

int main() {
	string sentence = "LoveisKoreaUniversity";
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		cout << sentence;

		if (i != N) {
			cout << ' ';
		}
	}

	return 0;
}