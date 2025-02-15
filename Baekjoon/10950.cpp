#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int T;
	cin >> T;

	for (int i = 0; i < T; i++) {
		int A, B;
		cin >> A >> B;

		v.push_back(A + B);
	}

	for (int i = 0; i < T; i++)
		cout << v[i] << '\n';

	return 0;
}