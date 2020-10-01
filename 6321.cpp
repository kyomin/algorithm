#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		string s;
		cin >> s;
		
		int len = s.size();

		string temp = "";

		for (int i = 0; i < len; i++) {
			char c = s[i];
			int n = (int)(c + 1);

			if (n > 90)
				n = 65;

			temp += (char)n;
		}

		cout << "String #" << t << '\n';
		cout << temp << '\n'<<'\n';
	}
	
	return 0;
}