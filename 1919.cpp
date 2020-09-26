#include <iostream>
#include <string>

using namespace std;

int A[26];
int B[26];

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int len1, len2;

	len1 = s1.size();
	len2 = s2.size();

	for (int i = 0; i < len1; i++) {
		int alpha = (int)(s1[i] - 'a');

		A[alpha]++;
	}

	for (int i = 0; i < len2; i++) {
		int alpha = (int)(s2[i] - 'a');

		B[alpha]++;
	}

	int result = 0;

	for (int i = 0; i < 26; i++) {
		if (A[i] == 0 && B[i] == 0)
			continue;

		// continue에서 안 먹히면 하나는 0이 아니란 소리!
		if (A[i] > B[i]) 
			result += (A[i] - B[i]);
		else 
			result += (B[i] - A[i]);
	}

	cout << result << '\n';

	return 0;
}