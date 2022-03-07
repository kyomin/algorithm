#include <iostream>
using namespace std;

int main() {
	int cnt = 0;
	int N;
	cin >> N;

	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;

		if (n != i)
			cnt++;
	}

	cout << cnt << endl;

	return 0;
}