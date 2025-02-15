#include <iostream>
using namespace std;

int main() {
	int  N, X, S;
	cin >> N >> X >> S;

	bool flag = false;

	for (int i = 0; i < N; i++) {
		int c, p;
		cin >> c >> p;

		if (c <= X && p > S)
			flag = true;			
	}

	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	return 0;
}