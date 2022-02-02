#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
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

bool com(const pair<string, int> &p1, const pair<string, int> &p2) {
	if (p1.first < p2.first)
		return true;
	else
		return false;
}

int main() {
	map<string, int> m;
	vector<pair<string, int>> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string file;
		cin >> file;

		string extension = split(file, '.')[1];

		// 해당 키를 못 찾았다면
		if (m.find(extension) == m.end())
			m[extension] = 1;
		else
			m.find(extension)->second += 1;	// 해당 키를 찾았다면 빈도 증가
	}

	copy(m.begin(), m.end(), back_inserter(v));
	sort(v.begin(), v.end(), com);

	for (int i = 0; i < v.size(); i++)
		cout << v[i].first << ' ' << v[i].second << endl;
	
	return 0;
}