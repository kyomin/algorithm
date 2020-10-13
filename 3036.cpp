#include <iostream>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int main() {
	vector<int> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	int first = v[0];
	int len = v.size();

	for (int i = 1; i < len; i++) {
		int G = gcd(first, v[i]);

		cout << first / G << '/' << v[i] / G << endl;
	}

	return 0;
}