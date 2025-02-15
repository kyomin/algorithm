#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

string intToString(int n) {
	stringstream s;
	s << n;
	return s.str();
}

bool prime(int n) {
	if (n < 2)
		return false;

	for (int i = 2; i*i <= n; i++)
		if (n%i == 0)
			return false;

	return true;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<string> v;

	while (true) {
		bool judge = false;
		int a, b;
		int N;
		cin >> N;

		if (N == 0)
			break;

		for (int i = 2; i < N; i++) {
			// i가 소수이고 N-i도 소수라면 해를 구한 것이다.
			if (prime(i) && prime(N - i)) {
				if ((N - i) % 2 == 1 && i % 2 == 1) {
					a = i;
					b = (N - i);
					judge = true;
					break;
				}
			}
		}

		if (judge) {
			string str = intToString(a + b) + " = " + intToString(a) + " + " + intToString(b);
			v.push_back(str);
		}
		else
			v.push_back("Goldbach's conjecture is wrong.");
	}

	int len = v.size();

	for (int i = 0; i < len; i++)
		cout << v[i] << '\n';

	return 0;
}