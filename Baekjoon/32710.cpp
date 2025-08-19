#include <iostream>
#include <vector>
using namespace std;

int main() {
	// 구구단 9단까지 등장하는 수는 81 이하
	vector<bool> check(82, false);

	// 등장하는 모든 수를 체킹한다.
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