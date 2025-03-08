#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// N: 학생의 수
	// M: 과목의 수
	int N, M;
	cin >> N >> M;

	vector<int> subjects(M + 1);

	for (int i = 1; i <= M; i++)
		cin >> subjects[i];

	vector<vector<int>> students(N + 1);
	vector<vector<int>> carts(M + 1);

	// 1차 수강신청 시작
	for (int i = 1; i <= N; i++) {		
		while (true) {
			int subject;
			cin >> subject;

			if (subject == -1)
				break;

			carts[subject].push_back(i);
		}
	}

	for (int i = 1; i <= M; i++) {
		vector<int> cart = carts[i];

		int cart_size = cart.size();
		int L = subjects[i];

		if (cart_size > L)
			continue;

		// 장바구니에 들어간 학생 순회
		for (int student : cart) {
			students[student].push_back(i);
		}
	}

	// 1차 수강 장바구니에 넣은만큼 제한 인원을 빼준다.
	for (int i = 1; i <= M; i++) {
		int num = carts[i].size();
		carts[i].clear();	// 1차 장바구니 비우기

		subjects[i] -= num;
	}

	// 2차 수강신청 시작
	for (int i = 1; i <= N; i++) {
		while (true) {
			int subject;
			cin >> subject;

			if (subject == -1)
				break;

			carts[subject].push_back(i);
		}
	}

	for (int i = 1; i <= M; i++) {
		vector<int> cart = carts[i];

		int cart_size = cart.size();
		int L = subjects[i];

		if (cart_size > L)
			continue;

		// 장바구니에 들어간 학생 순회
		for (int student : cart) {
			students[student].push_back(i);
		}
	}

	// 출력
	for (int i = 1; i <= N; i++) {
		vector<int> student = students[i];

		if (!student.size()) {
			cout << "망했어요" << endl;

			continue;
		}

		// 오름차순 정렬
		sort(student.begin(), student.end());

		for (int j = 0; j < student.size(); j++) {
			cout << student[j] << ' ';
		}

		cout << endl;
	}

	return 0;
}