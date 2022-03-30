#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	unordered_set<string> pSet;
	int ans = 0;
	int N, M;
	cin >> N >> M;

	// 가능한 모든 접두사 중복 없이 집합에 넣기
	string s;
	for (int i = 0; i < N; i++) {		
		cin >> s;
		string temp = "";
		
		for (int j = 0; j < s.length(); j++) {
			temp += s[j];
			pSet.insert(temp);
		}
	}

	for (int i = 0; i < M; i++) {
		string str;
		cin >> str;

		if (pSet.find(str) != pSet.end())
			ans++;
	}

	cout << ans << '\n';

	return 0;
}