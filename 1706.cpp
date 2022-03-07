#include <iostream>
#include <vector>
#include <string>
#include <set>
using namespace std;

int main() {
	set<string> words;
	vector<string> board;
	int R, C;
	cin >> R >> C;

	board.resize(R);

	for (int r = 0; r < R; r++)
		cin >> board[r];

	// 가로 낱말
	for (int r = 0; r < R; r++) {
		string word = "";

		for (int c = 0; c < C; c++) {
			if (board[r][c] != '#') {
				word += board[r][c];
			}
			else {
				if (word.length() > 1)
					words.insert(word);

				word = "";
			}
		}

		if(word.length() > 1)
			words.insert(word);
	}

	// 세로 낱말
	for (int c = 0; c < C; c++) {
		string word = "";

		for (int r = 0; r < R; r++) {
			if (board[r][c] != '#') {
				word += board[r][c];
			}
			else {
				if (word.length() > 1)
					words.insert(word);

				word = "";
			}
		}

		if (word.length() > 1)
			words.insert(word);
	}

	// 첫 번째 원소 출력
	set<string>::iterator it = words.begin();
	cout << *it << endl;

	return 0;
}