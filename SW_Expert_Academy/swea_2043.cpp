#include <iostream>
#include <string>

using namespace std;

int main() {
	string P, K;
	cin >> P >> K;

	int p = atoi(P.c_str());
	int k = atoi(K.c_str());

	cout << abs(p - k) + 1 << '\n';

	return 0;
}