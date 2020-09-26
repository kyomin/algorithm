#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct StudentInfo {
	int contry;
	int student_no;
	int score;
};

vector<StudentInfo> studentInfo;
pair<int, int> ans[3];		// 금 은 동 정보 담기
int contries[101];
int N;

bool comp(const StudentInfo &studentInfo1, const StudentInfo &studentInfo2) {
	if (studentInfo1.score > studentInfo2.score)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int n = 0; n < N; n++) {
		int contry;
		int student_no;
		int score;

		cin >> contry >> student_no >> score;

		studentInfo.push_back({ contry, student_no, score });
	}

	sort(studentInfo.begin(), studentInfo.end(), comp);

	int idx = 0;

	for (int i = 0; i < N; i++) {
		// 금 은 동 정보 3개가 다 모였다면
		if (idx == 3) break;

		int contry = studentInfo[i].contry;
		int student_no = studentInfo[i].student_no;

		if (contries[contry] < 2) {
			contries[contry] += 1;
			ans[idx] = { contry, student_no };
			idx++;
		}
	}

	for (int i = 0; i < 3; i++)
		cout << ans[i].first << ' ' << ans[i].second << '\n';

	return 0;
}