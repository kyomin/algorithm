#include <iostream>
#include <string>
#include <map>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	map<int, string> int_key;
	map<string, int> string_key;

	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		string s;
		cin >> s;

		int_key.insert(make_pair(i, s));
		string_key.insert(make_pair(s, i));
	}

	for (int i = 0; i < M; i++) {
		string s;
		cin >> s;

		// 숫자라면!
		if (atoi(s.c_str()) != 0)
			cout << int_key.find(atoi(s.c_str()))->second << '\n';
		else
			cout << string_key.find(s)->second << '\n';
	}

	return 0;
}