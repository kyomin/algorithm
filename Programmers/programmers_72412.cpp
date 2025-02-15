#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>

using namespace std;

map<string, int> m;
vector<int> table[4][3][3][3];

vector<int> solution(vector<string> info, vector<string> query) {
	m["-"] = 0;

	// for language
	m["cpp"] = 1;
	m["java"] = 2;
	m["python"] = 3;

	// for job
	m["backend"] = 1;
	m["frontend"] = 2;

	// for career
	m["junior"] = 1;
	m["senior"] = 2;

	// for sould food
	m["chicken"] = 1;
	m["pizza"] = 2;

	for (auto str : info) {
		// ������ �����ڷ� ���� ��´�.
		stringstream ss(str);
		string a, b, c, d;
		int score;
		ss >> a >> b >> c >> d >> score;	

		// ������ �ְ�, ������ ����� ���� 2^4=16���� ó��
		int arr[4] = { m.find(a)->second, m.find(b)->second, m.find(c)->second, m.find(d)->second };

		for (int i = 0; i < (1 << 4); i++) {	// i: 0 ~ 15
			int idx[4] = { 0 };

			// i�� ���� ���� ���� ���� ���� �ε����� �ִ´�.
			for (int j = 0; j < 4; j++) {
				if (i&(1 << j)) {
					idx[j] = arr[j];
				}
			}

			table[idx[0]][idx[1]][idx[2]][idx[3]].push_back(score);
		}
	}

	// �̺� Ž���� ���� ���� ����
	for (int a = 0; a < 4; a++)
		for (int b = 0; b < 3; b++)
			for (int c = 0; c < 3; c++)
				for (int d = 0; d < 3; d++)
					sort(table[a][b][c][d].begin(), table[a][b][c][d].end());

	vector<int> answer;

	for (auto str : query) {
		stringstream ss(str);
		string a, b, c, d, temp;	// temp�� and�� �����ϱ� ����
		int score;

		ss >> a >> temp >> b >> temp >> c >> temp >> d >> score;

		auto& score_list = table[m.find(a)->second][m.find(b)->second][m.find(c)->second][m.find(d)->second];

		vector<int>::iterator low = lower_bound(score_list.begin(), score_list.end(), score);
		answer.push_back(score_list.end() - low);
	}

	return answer;
}