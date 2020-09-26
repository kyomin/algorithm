#include <iostream>
#include <string>

using namespace std;

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		string s1, s2;
		cin >> s1 >> s2;

		// 두 숫자 길이가 같으므로
		int len = s1.size();
		
		int cnt = 0;

		for (int i = 0; i < len; i++) {
			if (s1[i] != s2[i])
				cnt++;
		}

		cout << "Hamming distance is " << cnt << '.' << '\n';
	}

	return 0;
}