#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter))
		internal.push_back(temp);

	return internal;
}

int solution(vector<string> friends, vector<string> gifts) {
	int answer = 0;
	int N = friends.size();

	map<string, int> friendNumber;	// 친구들을 숫자로 관리
	for (int i = 0; i < N; i++) {
		string f = friends[i];

		friendNumber.insert(make_pair(f, i));
	}

	vector<vector<int>> board(N, vector<int>(N));	// 주고 받은 선물 표
	for (string gift : gifts) {
		vector<string> names = split(gift, ' ');

		string f1 = names[0];
		string f2 = names[1];

		int index1 = friendNumber.find(f1)->second;
		int index2 = friendNumber.find(f2)->second;

		board[index1][index2] += 1;
	}

	vector<int> giftIndex(N);	// 선물 지수
	for (int i = 0; i < N; i++) {
		int give = 0;	// 준 개수
		int take = 0;	// 받은 개수

		for (int j = 0; j < N; j++) {
			give += board[i][j];
			take += board[j][i];
		}

		giftIndex[i] = give - take;
	}

	vector<int> giveAmount(N);	// 선물 받는 양
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;

			// 주고 받은 선물이 같은 경우
			if (board[i][j] == board[j][i]) {
				// 내 선물 지수가 더 높은 경우
				if (giftIndex[i] > giftIndex[j])
					giveAmount[i] += 1;

				continue;
			}

			// 내가 더 많은 선물을 준 경우
			if(board[i][j] > board[j][i])
				giveAmount[i] += 1;
		}
	}

	for (int i = 0; i < N; i++)
		answer = max(answer, giveAmount[i]);

	return answer;
}