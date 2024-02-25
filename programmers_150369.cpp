#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
	��ް� ���Ÿ� ��ģ ���� ���� ���¸� ������Ʈ �Ѵ�

	@param list		������Ʈ �� ����
	@param cap		Ʈ���� ���� �� �ִ� ��Ȱ�� �ù� ������ �ִ� ����
*/
void update(vector<int>& list, int cap) {
	while (list.size()) {
		if (cap < list.back()) {
			list.back() -= cap;
			break;
		}
		else {
			cap -= list.back();
			list.pop_back();
		}
	}
}

/*
	@param cap			Ʈ���� ���� �� �ִ� ��Ȱ�� �ù� ������ �ִ� ����
	@param n			����� ���� ����
	@param deliveries	�� ���� ����� ��Ȱ�� �ù� ������ ������ ���� 1���� ���� �迭
	@param pickups		�� ������ ������ �� ��Ȱ�� �ù� ������ ������ ���� 1���� ���� �迭
	
	@return				Ʈ�� �ϳ��� ��� ��ް� ���Ÿ� ��ġ�� ����â����� ���ƿ� �� �ִ� �ּ� �̵��Ÿ�
*/
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	long long answer = 0;

	while (deliveries.size() || pickups.size()) {
		while (deliveries.size() && deliveries.back() == 0)
			deliveries.pop_back();

		while (pickups.size() && pickups.back() == 0)
			pickups.pop_back();

		// �� �Ͽ����� �պ� �Ÿ�
		answer += max(deliveries.size(), pickups.size()) * 2;

		update(deliveries, cap);
		update(pickups, cap);
	}

	return answer;
}