#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;

		v.push_back(a + b);
	}

	for (int i = 0; i < N; i++)
		cout << "Case #" << i + 1 << ": " << v[i] << '\n';

	return 0;
}