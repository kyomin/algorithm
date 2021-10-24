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
	int N;
	cin >> N;

	cin.get();
	for (int n = 0; n < N; n++) {
		string str;
		getline(cin, str);

		vector<string> names = split(str, ' ');
		string res = "god";
		int len = names.size();

		for (int i = 1; i < len; i++) 
			res += names[i];
		
		cout << res << endl;
	}

	return 0;
}