#include <iostream>
#include <string>

using namespace std;

string words[50];
bool isPrefix[50][50];
int N;

int main() {
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> words[i];
	}

	for (int i = 0; i < N; i++) {
		// 현재 기준 단어
		string curWord = words[i];

		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;

			// 비교 대상
			string compareWord = words[j];

			// 길이가 길면 접두사가 될 수 없으므로
			if (curWord.size() > compareWord.size())
				continue;

			int len = curWord.size();

			// 접두사가 되는 경우
			if (curWord == compareWord.substr(0, len))
				isPrefix[i][j] = true;
		}
	}

	int ans = 0;

	for (int i = 0; i < N; i++) {
		int cnt = 0;

		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;

			// 접두사가 아니라면
			if (!isPrefix[i][j])
				cnt++;
		}

		// 현재 단어가 다른 모든 단어의 접두사가 아닌 경우
		if (cnt == N - 1)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}