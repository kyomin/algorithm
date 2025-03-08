#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// N: �л��� ��
	// M: ������ ��
	int N, M;
	cin >> N >> M;

	vector<int> subjects(M + 1);

	for (int i = 1; i <= M; i++)
		cin >> subjects[i];

	vector<vector<int>> students(N + 1);
	vector<vector<int>> carts(M + 1);

	// 1�� ������û ����
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

		// ��ٱ��Ͽ� �� �л� ��ȸ
		for (int student : cart) {
			students[student].push_back(i);
		}
	}

	// 1�� ���� ��ٱ��Ͽ� ������ŭ ���� �ο��� ���ش�.
	for (int i = 1; i <= M; i++) {
		int num = carts[i].size();
		carts[i].clear();	// 1�� ��ٱ��� ����

		subjects[i] -= num;
	}

	// 2�� ������û ����
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

		// ��ٱ��Ͽ� �� �л� ��ȸ
		for (int student : cart) {
			students[student].push_back(i);
		}
	}

	// ���
	for (int i = 1; i <= N; i++) {
		vector<int> student = students[i];

		if (!student.size()) {
			cout << "���߾��" << endl;

			continue;
		}

		// �������� ����
		sort(student.begin(), student.end());

		for (int j = 0; j < student.size(); j++) {
			cout << student[j] << ' ';
		}

		cout << endl;
	}

	return 0;
}