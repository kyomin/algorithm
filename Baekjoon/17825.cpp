#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int END = 32;

int dice[10];
vector<int> horse_array;	// �� ����

/*
	�̵� ��Ģ�� ������ �� �����Ƿ� look-up ���̺��� �����.
	jump[idx][0] => �ش� �� ����
	jump[idx][1 ~ 5] => �ش� ���� �ֻ����� ������ �̵��ϴ� ��ġ
*/
int jump[33][6] = { 
	{0,1,2,3,4,5},			// 0���ڸ� (start)
	{2,2,3,4,5,9},			// 1���ڸ� 
	{4,3,4,5,9,10},			// 2���ڸ� 
	{6,4,5,9,10,11},		// 3���ڸ� 
	{8,5,9,10,11,12},		// 4���ڸ� 
	{10,6,7,8,20,29},		// 5���ڸ� 
	{13,7,8,20,29,30},		// 6���ڸ� 
	{16,8,20,29,30,31},		// 7���ڸ� 
	{19,20,29,30,31,32},	// 8���ڸ� 
	{12,10,11,12,13,14},	// 9���ڸ� 
	{14,11,12,13,14,15},	// 10���ڸ� 
	{16,12,13,14,15,16},	// 11���ڸ� 
	{18,13,14,15,16,17},	// 12���ڸ� 
	{20,18,19,20,29,30},	// 13���ڸ� 
	{22,15,16,17,24,25},	// 14���ڸ� 
	{24,16,17,24,25,26},	// 15���ڸ� 
	{26,17,24,25,26,27},	// 16���ڸ� 
	{28,24,25,26,27,28},	// 17���ڸ� 
	{22,19,20,29,30,31},	// 18���ڸ� 
	{24,20,29,30,31,32},	// 19���ڸ� 
	{25,29,30,31,32,32},	// 20���ڸ� 
	{26,20,29,30,31,32},	// 21���ڸ� 
	{27,21,20,29,30,31},	// 22���ڸ� 
	{28,22,21,20,29,30},	// 23���ڸ� 
	{30,23,22,21,20,29},	// 24���ڸ� 
	{32,26,27,28,31,32},	// 25���ڸ� 
	{34,27,28,31,32,32},	// 26���ڸ� 
	{36,28,31,32,32,32},	// 27���ڸ� 
	{38,31,32,32,32,32},	// 28���ڸ� 
	{30,30,31,32,32,32},	// 29���ڸ� 
	{35,31,32,32,32,32},	// 30���ڸ� 
	{40,32,32,32,32,32},	// 31���ڸ� 
	{0,32,32,32,32,32}		// 32���ڸ� (end)
};

int ans = 0;

void simulation() {
	int score = 0;
	int occupation[33];		// �ش� ĭ(idx)�� ���� �� ���� �ִ°�?
	int pos[4];		// �� ������ �� ��ġ

	memset(occupation, 0, sizeof(occupation));
	memset(pos, 0, sizeof(pos));	// ó���� 0���� ����

	// ù ĭ(start = 0)���� 4������ ��� ��!
	occupation[0] = 4;

	for (int turn = 0; turn < 10; turn++) {
		// �̹��� �ű� �� (0 ~ 3)
		int horse = horse_array[turn];

		// �̵��ϴ� �Ÿ�
		int move = dice[turn];

		// ���� ��ġ
		int cur_pos = pos[horse];

		// �̵��� ��ġ
		int next_pos = jump[cur_pos][move];

		// �̹� �̵����� ���� ����
		int get_score = jump[next_pos][0];

		// ó���̳� �� ��ġ�� �ƴѵ�, ���� ��ġ�� ���
		if (occupation[next_pos] > 0 && next_pos && next_pos != END)
			return;

		score += get_score;

		// ���� ĭ�� ���� ����
		occupation[next_pos]++;

		// ���� ĭ�� ������
		occupation[cur_pos]--;

		// �ش� ���� ��ġ�� ���� ��Ų��.
		pos[horse] = next_pos;
	}

	// �ִ� ����
	ans = max(ans, score);
}

void dfs() {
	// �� ������ ������� ���!
	if (horse_array.size() == 10) {
		simulation();
		return;
	}

	for (int horse = 0; horse < 4; horse++) {
		horse_array.push_back(horse);

		dfs();

		horse_array.pop_back();
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 10; i++)
		cin >> dice[i];

	dfs();

	cout << ans << '\n';

	return 0;
}