#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>

using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter))
		internal.push_back(temp);

	return internal;
}

int main() {
	// 몇 줄인가?
	int N;
	cin >> N;

	cin.ignore();

	vector <vector<string>> result;

	for (int i = 0; i < N; i++) {
		string str;
		vector<string> v;

		getline(cin, str);

		v = split(str, ' ');

		int len = v.size();

		for (int i = 0; i < len; i++)
			reverse(v[i].begin(), v[i].end());

		result.push_back(v);
	}

	for (int i = 0; i < N; i++) {
		int len = result[i].size();

		for (int j = 0; j < len; j++) 
			cout << result[i][j] << ' ';

		cout << '\n';
	}

	return 0;
}