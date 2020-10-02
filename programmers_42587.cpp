#include <string>
#include <vector>

using namespace std;

int solution(vector<int> priorities, int location) {
	int answer = 0;
	vector<pair<int, int>> v;

	int len = priorities.size();

	// first : ��, second : �ε���
	for (int i = 0; i < len; i++)
		v.push_back(make_pair(priorities[i], i));

	while (true) {
		int len = v.size();
		bool judge = false;

		// ������ �ϳ��� ���� ���̶��
		if (len == 1) {
			answer += 1;
			break;
		}

		// �ϳ� �̻��� ���� ���̶��
		for (int i = 1; i < len; i++) {
			if (v[0].first < v[i].first) {
				judge = true;
				break;
			}
		}

		// ���� ��⿭ �ڿ� �ڱ⺸�� ū ���� �ִٸ�
		if (judge) {

			// �� �� ���� �� �ڷ� ������
			v.push_back(v[0]);

			// front pop!
			vector<pair<int, int>>::iterator iter = v.begin();

			v.erase(iter);
		} else {
			vector<pair<int, int>>::iterator iter = v.begin();

			if (v[0].second == location) {
				answer += 1;
				break;
			} else {
				answer += 1;
				v.erase(iter);
			}
		}
	}

	return answer;
}