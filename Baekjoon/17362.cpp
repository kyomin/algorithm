#include <iostream>

using namespace std;

int main() {
	int N;
	cin >> N;

	int ans[9] = {
		-1, 1, 2, 3, 4, 5, 4, 3, 2
	};

	if (N % 8 == 0)
		cout << ans[8] << endl;
	else
		cout << ans[N % 8] << endl;

	return 0;
}