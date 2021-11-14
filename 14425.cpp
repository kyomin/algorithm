#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
	int ans = 0;
	map<string, bool> m;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		
		m[str] = true;
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;

		if (m[str])
			ans++;
	}

	cout <<ans << endl;

	return 0;
}