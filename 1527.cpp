#include <iostream>
using namespace std;

typedef unsigned long long ll;

ll A, B;
ll result;

void solve(ll num) {
	if (num > B)
		return;

	if (A <= num && num <= B)
		result++;

	solve(num * 10 + 4);
	solve(num * 10 + 7);
}

int main() {
	cin >> A >> B;

	solve(4);
	solve(7);
	cout << result << endl;

	return 0;
}