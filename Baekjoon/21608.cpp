#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;

struct Candidate {
	int r;
	int c;
	int empty_cnt;
	int like_student_cnt;
};

const int dr[] = { 0, 0, 1, -1 };
const int dc[] = { 1, -1, 0, 0 };

int N;
int class_room[20][20];
int satisfication[5] = { 0, 1, 10, 100, 1000 };
map<int, vector<int>> m;

// first : �л� ��ȣ, second : �ش� �л��� �����ϴ� �л�
vector<pair<int, vector<int>>> students_info;

// ���� ���� �ִ°�?
bool isInside(int r, int c) {
	if (0 <= r && r < N && 0 <= c && c < N)
		return true;

	return false;
}

// Ư�� ��ǥ���� ������ �� ĭ�� ������ ����.
int countEmpty(int r, int c) {
	int cnt = 0;

	for (int k = 0; k < 4; k++) {
		int nr = r + dr[k];
		int nc = c + dc[k];

		if (!isInside(nr, nc))
			continue;

		if (class_room[nr][nc] == 0)
			cnt++;
	}

	return cnt;
}

// �ش� ��ȣ�� ���� �����ϴ� �л� ����Ʈ �ȿ� �ִ°�?
bool isMyLikeStudent(int student_num, vector<int> like_studnet_list) {
	for (int i = 0; i < like_studnet_list.size(); i++)
		if (student_num == like_studnet_list[i])
			return true;

	return false;
}

// Ư�� ��ǥ���� ������ ĭ�� �����ϴ� �л��� ���� ����
int countLikeStudent(int r, int c, vector<int> like_studnet_list) {
	int cnt = 0;

	for (int k = 0; k < 4; k++) {
		int nr = r + dr[k];
		int nc = c + dc[k];

		if (!isInside(nr, nc))
			continue;

		// �������� �ɾ��ִ�.
		if (class_room[nr][nc] != 0)
			if (isMyLikeStudent(class_room[nr][nc], like_studnet_list))
				cnt++;
	}

	return cnt;
}

// r, c, like_student_cnt, empty_cnt => ���� => ��ȸ�� ������ ���� => ù ��° ���Ұ� ���� �켱������ ���� �ĺ��� => ���� �л��� ������.
bool comp(Candidate candidate1, Candidate candidate2) {
	if (candidate1.like_student_cnt > candidate2.like_student_cnt)
		return true;
	else if (candidate1.like_student_cnt == candidate2.like_student_cnt) {
		if (candidate1.empty_cnt > candidate2.empty_cnt)
			return true;
		else if (candidate1.empty_cnt == candidate2.empty_cnt) {
			if (candidate1.r < candidate2.r)
				return true;
			else if (candidate1.r == candidate2.r) {
				if (candidate1.c < candidate2.c)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main() {
	int ans = 0;

	cin >> N;

	for (int i = 0; i < N*N; i++) {
		int student;
		vector<int> like_students;
		like_students.resize(4);

		cin >> student;

		for (int k = 0; k < 4; k++)
			cin >> like_students[k];

		students_info.push_back(make_pair(student, like_students));

		// key: �л� ��ȣ, value: like list
		m[student] = like_students;
	}

	for (int i = 0; i < students_info.size(); i++) {
		int student = students_info[i].first;
		vector<int> like_students = students_info[i].second;
		vector<Candidate> candidates;

		for (int row = 0; row < N; row++) {
			for (int col = 0; col < N; col++) {
				if (class_room[row][col] != 0)
					continue;

				int empty_cnt = countEmpty(row, col);
				int like_cnt = countLikeStudent(row, col, like_students);

				Candidate candidate;
				candidate.r = row;
				candidate.c = col;
				candidate.empty_cnt = empty_cnt;
				candidate.like_student_cnt = like_cnt;

				candidates.push_back(candidate);
			}
		}

		// �켱������ ���� �����߱� ������, ���� ù ���Ұ� �л��� �ɾƾ� �ϴ� �ڸ��� �ȴ�.
		sort(candidates.begin(), candidates.end(), comp);
		
		Candidate priority_cadidate = candidates[0];
		class_room[priority_cadidate.r][priority_cadidate.c] = student;
	}

	for (int r = 0; r < N; r++) {
		for (int c = 0; c < N; c++) {
			int student = class_room[r][c];
			vector<int> like_list = m.find(student)->second;
			int like_cnt = countLikeStudent(r, c, like_list);

			ans += satisfication[like_cnt];
		}
	}

	cout << ans << '\n';

	return 0;
}