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

vector<int> kmp(string s, string p) {
	vector<int> ans;
	auto pi = getPi(p);	// 패턴에 대한 pi 배열 얻기
	int n = s.length();
	int m = p.length();
	int j = 0;

	for (int i = 0; i < n; i++) {
		while (j > 0 && s[i] != p[j])
			j = pi[j - 1];

		if (s[i] == p[j]) {
			// 패턴이 일치하는 시작 인덱스를 찾은 경우
			if (j == m - 1) {
				ans.push_back(i - m + 1);
				j = pi[j];
			}
			else {
				j++;
			}
		}
	}

	return ans;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string s, p;
	getline(cin, s);
	getline(cin, p);
	auto matched = kmp(s, p);
	
	cout << matched.size() << '\n';

	for (auto i : matched)
		cout << i + 1 << '\n';

	return 0;
}