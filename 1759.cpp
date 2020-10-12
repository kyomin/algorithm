#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int L, C;
vector<char> vc;
vector<char> arr;

void DFS(int cnt) {
	if (vc.size() == L) {
		int judge_vowel = 0;	// 모음 개수
		int judge_consonant = 0;	// 자음 개수

		for (auto i : vc)
			if (i == 'a' || i == 'e' || i == 'i' || i == 'o' || i == 'u')
				judge_vowel++;
			else
				judge_consonant++;

		if (judge_vowel >= 1 && judge_consonant >= 2) {
			for (auto i : vc)
				cout << i;

			cout << '\n';
		}

		return;
	}

	for (int i = cnt; i < C; i++) {
		if (vc.size() < L) {
			vc.push_back(arr[i]);
			DFS(i + 1);
			vc.pop_back();
		}
	}
}

int main() {
	cin >> L >> C;

	for (int i = 0; i < C; i++) {
		char n;
		cin >> n;
		arr.push_back(n);
	}

	sort(arr.begin(), arr.end());

	DFS(0);

	return 0;
}