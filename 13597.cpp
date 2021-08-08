#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int A, B;
	cin >> A >> B;

	int result = max(A, B);

	cout << result << '\n';

	return 0;
}