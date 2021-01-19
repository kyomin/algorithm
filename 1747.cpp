#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool isPrime(int n) {
	if (n < 2)
		return false;

	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false;

	return true;
}

bool isPalindrome(string N) {
	string temp = N;
	reverse(N.begin(), N.end());

	if (temp == N)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	while (true) {
		if (isPrime(N) && isPalindrome(to_string(N)))
			break;

		N++;
	}

	cout << N << '\n';

	return 0;
}