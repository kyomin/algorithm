#include <string>
#include <vector>
#include <map>
using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
	int answer = 0;
	int wantLen = want.size();
	int len = discount.size();

	for (int i = 0; i + 10 <= len; i++) {
		map<string, int> m;

		for (int j = i; j < i + 10; j++) {
			string product = discount[j];

			// �ش� Ű�� �� ã�Ҵٸ�
			if (m.find(product) == m.end())
				m[product] = 1;
			// �ش� Ű�� ã�Ҵٸ�
			else
				m.find(product)->second += 1;	// ���� ����
		}

		bool flag = true;

		for (int j = 0; j < wantLen; j++) {
			string product = want[j];

			// �����ϴ� ���� ���� ���
			if (m.find(product) == m.end()) {
				flag = false;
				break;
			}

			// ���ϴ� ��ǰ�� ������ ��ġ���� �ʴ� ���
			if (m.find(product)->second < number[j]) {
				flag = false;
				break;
			}
		}

		if (flag)
			answer++;
	}

	return answer;
}