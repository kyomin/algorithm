#include <iostream>
#include <string>

using namespace std;

int main() {
	string N, M;
	cin >> N >> M;

	if (N == M)
		cout << 1 << '\n';
	else
		cout << 0 << '\n';

	return 0;
}