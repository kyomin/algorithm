#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	while (true) {
		string s;
		getline(cin, s);

		if (s == "*")
			break;

		vector<string> sentence = split(s, ' ');
		int len = sentence.size();
		bool judge = true;
		char first_char = sentence[0][0];
		
		for (int i = 1; i < len; i++) {
			if (first_char == sentence[i][0] || first_char == (char)(sentence[i][0] - 32) || first_char == (char)(sentence[i][0] + 32)) {
				continue;
			}
			else {
				judge = false;
				break;
			}
		}

		if (judge)
			cout << 'Y' << '\n';
		else
			cout << 'N' << '\n';
	}

	return 0;
}