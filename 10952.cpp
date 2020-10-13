#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;

	while (true) {
		int a, b;
		cin >> a >> b;

		if (a == 0 && b == 0)
			break;

		v.push_back(a + b);
	}

	int len = v.size();

	for (int i = 0; i < len; i++)
		cout << v[i] << '\n';

	return 0;
}