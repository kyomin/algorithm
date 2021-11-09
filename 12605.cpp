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
	int T;
	cin >> T;

	cin.get();
	for (int t = 1; t <= T; t++) {
		string str;
		getline(cin, str);

		vector<string> strings = split(str, ' ');
		int len = strings.size();

		cout << "Case #" << t << ": ";
		for (int i = len - 1; i > 0; i--)
			cout << strings[i] << ' ';

		cout << strings[0] << endl;
	}

	return 0;
}