#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	map<string, string> m;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string site, password;
		cin >> site >> password;

		m[site] = password;
	}

	for (int i = 0; i < M; i++) {
		string site;
		cin >> site;

		cout << m.find(site)->second << '\n';
	}

	return 0;
}