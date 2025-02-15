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

	map<string, int> friendNumber;	// ģ������ ���ڷ� ����
	for (int i = 0; i < N; i++) {
		string f = friends[i];

		friendNumber.insert(make_pair(f, i));
	}

	vector<vector<int>> board(N, vector<int>(N));	// �ְ� ���� ���� ǥ
	for (string gift : gifts) {
		vector<string> names = split(gift, ' ');

		string f1 = names[0];
		string f2 = names[1];

		int index1 = friendNumber.find(f1)->second;
		int index2 = friendNumber.find(f2)->second;

		board[index1][index2] += 1;
	}

	vector<int> giftIndex(N);	// ���� ����
	for (int i = 0; i < N; i++) {
		int give = 0;	// �� ����
		int take = 0;	// ���� ����

		for (int j = 0; j < N; j++) {
			give += board[i][j];
			take += board[j][i];
		}

		giftIndex[i] = give - take;
	}

	vector<int> giveAmount(N);	// ���� �޴� ��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j)
				continue;

			// �ְ� ���� ������ ���� ���
			if (board[i][j] == board[j][i]) {
				// �� ���� ������ �� ���� ���
				if (giftIndex[i] > giftIndex[j])
					giveAmount[i] += 1;

				continue;
			}

			// ���� �� ���� ������ �� ���
			if(board[i][j] > board[j][i])
				giveAmount[i] += 1;
		}
	}

	for (int i = 0; i < N; i++)
		answer = max(answer, giveAmount[i]);

	return answer;
}