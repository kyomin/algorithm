#include <iostream>
#include <algorithm>
#include <map>
#include <vector>

using namespace std;

// first : ����, second : �� 
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
		// first : ����, second : �� 
		map<int, int> m;
		vector<pair<int, int>> v;

		// �׽�Ʈ ���̽��� ��ȣ�� �Է� �޴´�.
		int N;
		cin >> N;
		
		// 1000���� �л� ������ �޴´�.
		for (int i = 0; i < 1000; i++) {
			int score;
			cin >> score;

			// �ش� ������ key�� �� ã�Ҵٸ� ������ �����ϰ� �� 1
			if (m.find(score) == m.end())
				m[score] = 1;
			// �ش� ������ key�� ã�Ҵٸ� �� ����!
			else
				m.find(score)->second += 1;
		}

		// map �ڷ��� ���� m�� 1000�� �л��� ������ �󵵰� �� ����.
		// �̸� pair�� ���Ϳ� ��´�.
		copy(m.begin(), m.end(), back_inserter(v));

		sort(v.begin(), v.end(), comp);

		cout << '#' << N << ' ' << v[0].first << '\n';
	}

	return 0;
}