#include <iostream>
#include <set>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	set<int> s;

	for (int i = 0; i < 10; i++) {
		int n;
		cin >> n;

		s.insert(n % 42);
	}

	cout << s.size() << '\n';

	return 0;
}