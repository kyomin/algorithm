#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

map<char, int> m;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;

		if (m.find(str[0]) == m.end())
			m[str[0]] = 1;
		else
			m.find(str[0])->second += 1;
	}

	int cnt = 0;

	for (map<char, int>::iterator it = m.begin(); it != m.end(); it++) {
		if (it->second >= 5) {
			cout << it->first;
			cnt++;
		}
	}

	if (cnt == 0)
		cout << "PREDAJA";

	cout << '\n';

	return 0;
}