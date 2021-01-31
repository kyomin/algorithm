#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

// first : 점수, second : 빈도 
bool comp(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.second > p2.second)
		return true;
	else if (p1.second == p2.second) {
		if (p1.first > p2.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main(int argc, char** argv) {
	int test_case;
	int T;
	
	cin >> T;
	
	for (test_case = 1; test_case <= T; ++test_case) {
		// first : 점수, second : 빈도 
		map<int, int> m;
		vector<pair<int, int>> v;

		// 테스트 케이스의 번호를 입력 받는다.
		int N;
		cin >> N;
		
		// 1000명의 학생 점수를 받는다.
		for (int i = 0; i < 1000; i++) {
			int score;
			cin >> score;

			// 해당 점수의 key를 못 찾았다면 새로이 셋팅하고 빈도 1
			if (m.find(score) == m.end())
				m[score] = 1;
			// 해당 점수의 key를 찾았다면 빈도 증가!
			else
				m.find(score)->second += 1;
		}

		// map 자료형 변수 m에 1000명 학생의 점수와 빈도가 다 담겼다.
		// 이를 pair형 벡터에 담는다.
		copy(m.begin(), m.end(), back_inserter(v));

		sort(v.begin(), v.end(), comp);

		cout << '#' << N << ' ' << v[0].first << '\n';
	}

	return 0;
}