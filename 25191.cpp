#include <iostream>
using namespace std;

int main() {
	int N, A, B;
	cin >> N >> A >> B;

	int res = (A / 2) + B;

	if (res > N)
		cout << N << endl;
	else
		cout << res << endl;

	return 0;
}