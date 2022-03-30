#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<int> getPi(string p) {
	int m = p.length();
	int j = 0;
	vector<int> pi(m, 0);

	for (int i = 1; i < m; i++) {
		while (j > 0 && p[i] != p[j])
			j = pi[j - 1];

		if (p[i] == p[j])
			pi[i] = ++j;
	}

	return pi;
}

int kmp(string s, string p) {
	auto pi = getPi(p);	// 패턴에 대한 pi 배열 얻기
	int n = s.length();
	int m = p.length();
	int j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];

		if (s[i] == p[j]) {
			// 패턴이 일치하는 시작 인덱스를 찾은 경우
			if (j == m - 1)
				return 1;
			else 
				j++;			
		}
	}

	return 0;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s, p;
	cin >> s;
	cin >> p;
	int ans = kmp(s, p);

	cout << ans << '\n';

	return 0;
}