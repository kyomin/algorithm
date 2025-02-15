#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int pos;
	string str;

	for (int i = 0; i < N; i++) {
		cin >> pos;
		cin >> str;

		str.erase(pos-1, 1);

		cout << str << '\n';
	}

	return 0;
}