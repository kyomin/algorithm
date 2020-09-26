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
		// ���� ���� �ܾ�
		string curWord = words[i];

		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;

			// �� ���
			string compareWord = words[j];

			// ���̰� ��� ���λ簡 �� �� �����Ƿ�
			if (curWord.size() > compareWord.size())
				continue;

			int len = curWord.size();

			// ���λ簡 �Ǵ� ���
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

			// ���λ簡 �ƴ϶��
			if (!isPrefix[i][j])
				cnt++;
		}

		// ���� �ܾ �ٸ� ��� �ܾ��� ���λ簡 �ƴ� ���
		if (cnt == N - 1)
			ans++;
	}

	cout << ans << '\n';

	return 0;
}