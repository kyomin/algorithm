#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	string s1, s2;
	vector<int> A, B;

	cin >> s1 >> s2;

	int len1 = s1.size();
	int len2 = s2.size();

	for (int i = 0; i < len1; i++) {
		A.push_back((int)(s1[i] - '0'));
	}

	for (int i = 0; i < len2; i++) {
		B.push_back((int)(s2[i] - '0'));
	}

	unsigned long long result = 0;

	for (int a = 0; a < len1; a++) {
		for (int b = 0; b < len2; b++) {
			result += A[a] * B[b];
		}
	}

	cout << result << '\n';

	return 0;
}