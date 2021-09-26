#include <iostream>
#include <string>

using namespace std;

int main() {
	string restoration = "";
	string S, K;
	cin >> S >> K;

	for (int i = 0; i < S.length(); i++) {
		if (isdigit(S[i]))
			continue;

		restoration += S[i];
	}

	bool flag = false;
	int end = restoration.length() - K.length();
	for (int start = 0; start <= end; start++) {
		if (K == restoration.substr(start, K.length())) {
			flag = true;
			break;
		}
	}

	if (flag)
		cout << 1 << endl;
	else
		cout << 0 << endl;

	return 0;
}