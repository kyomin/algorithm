#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int END = 32;

int dice[10];
vector<int> horse_array;	// 말 순열

/*
	이동 규칙이 복잡할 수 있으므로 look-up 테이블을 만든다.
	jump[idx][0] => 해당 판 점수
	jump[idx][1 ~ 5] => 해당 수의 주사위가 나오면 이동하는 위치
*/
int jump[33][6] = { 
	{0,1,2,3,4,5},			// 0번자리 (start)
	{2,2,3,4,5,9},			// 1번자리 
	{4,3,4,5,9,10},			// 2번자리 
	{6,4,5,9,10,11},		// 3번자리 
	{8,5,9,10,11,12},		// 4번자리 
	{10,6,7,8,20,29},		// 5번자리 
	{13,7,8,20,29,30},		// 6번자리 
	{16,8,20,29,30,31},		// 7번자리 
	{19,20,29,30,31,32},	// 8번자리 
	{12,10,11,12,13,14},	// 9번자리 
	{14,11,12,13,14,15},	// 10번자리 
	{16,12,13,14,15,16},	// 11번자리 
	{18,13,14,15,16,17},	// 12번자리 
	{20,18,19,20,29,30},	// 13번자리 
	{22,15,16,17,24,25},	// 14번자리 
	{24,16,17,24,25,26},	// 15번자리 
	{26,17,24,25,26,27},	// 16번자리 
	{28,24,25,26,27,28},	// 17번자리 
	{22,19,20,29,30,31},	// 18번자리 
	{24,20,29,30,31,32},	// 19번자리 
	{25,29,30,31,32,32},	// 20번자리 
	{26,20,29,30,31,32},	// 21번자리 
	{27,21,20,29,30,31},	// 22번자리 
	{28,22,21,20,29,30},	// 23번자리 
	{30,23,22,21,20,29},	// 24번자리 
	{32,26,27,28,31,32},	// 25번자리 
	{34,27,28,31,32,32},	// 26번자리 
	{36,28,31,32,32,32},	// 27번자리 
	{38,31,32,32,32,32},	// 28번자리 
	{30,30,31,32,32,32},	// 29번자리 
	{35,31,32,32,32,32},	// 30번자리 
	{40,32,32,32,32,32},	// 31번자리 
	{0,32,32,32,32,32}		// 32번자리 (end)
};

int ans = 0;

void simulation() {
	int score = 0;
	int occupation[33];		// 해당 칸(idx)에 말이 몇 마리 있는가?
	int pos[4];		// 각 말들의 현 위치

	memset(occupation, 0, sizeof(occupation));
	memset(pos, 0, sizeof(pos));	// 처음엔 0에서 시작

	// 첫 칸(start = 0)에는 4마리가 대기 중!
	occupation[0] = 4;

	for (int turn = 0; turn < 10; turn++) {
		// 이번에 옮길 말 (0 ~ 3)
		int horse = horse_array[turn];

		// 이동하는 거리
		int move = dice[turn];

		// 현재 위치
		int cur_pos = pos[horse];

		// 이동할 위치
		int next_pos = jump[cur_pos][move];

		// 이번 이동으로 얻을 점수
		int get_score = jump[next_pos][0];

		// 처음이나 끝 위치가 아닌데, 말이 겹치는 경우
		if (occupation[next_pos] > 0 && next_pos && next_pos != END)
			return;

		score += get_score;

		// 다음 칸에 말을 놓고
		occupation[next_pos]++;

		// 현재 칸을 떠난다
		occupation[cur_pos]--;

		// 해당 말의 위치를 변경 시킨다.
		pos[horse] = next_pos;
	}

	// 최댓값 갱신
	ans = max(ans, score);
}

void dfs() {
	// 말 순열이 만들어진 경우!
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