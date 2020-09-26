#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int A[2][2];
int copy[2][2];

// first : 분자와 분모, second : 돌린 횟수
vector<pair<pair<int, int>, int>> v;

bool cmp(const pair<pair<int, int>, int> &p1, const pair<pair<int, int>, int> &p2) {
	if (p1.first.first > p2.first.first) {
		return true;
	} else if (p1.first.first == p2.first.first) {
		if (p1.second < p2.second) {
			return true;
		} else {
			return false;
		}
	} else {
		return false;
	}
}

void rightRotation() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			::copy[i][j] = A[j][1 - i];
		}
	}

	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			A[i][j] = ::copy[i][j];
		}
	}
}

int main() {
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 2; j++) {
			cin >> A[i][j];
		}
	}

	for (int i = 0; i < 4; i++) {
		// 분모
		int mother = A[1][0] * A[1][1];

		// 분자
		int son = A[0][0] * A[1][1] + A[0][1] * A[1][0];

		v.push_back(make_pair(make_pair(son, mother), i));

		rightRotation();
	}

	// 분자 통일
	for (int cur = 0; cur < 4; cur++) {
		for (int i = 0; i < 4; i++) {
			if (i == cur)
				continue;

			v[cur].first.first *= v[i].first.second;
		}
	}

	sort(v.begin(), v.end(), cmp);

	cout << v[0].second << '\n';

	return 0;
}