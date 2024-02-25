#include <string>
#include <vector>
#include <algorithm>
using namespace std;

/*
	배달과 수거를 마친 후의 벡터 상태를 업데이트 한다

	@param list		업데이트 할 벡터
	@param cap		트럭에 실을 수 있는 재활용 택배 상자의 최대 개수
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
	@param cap			트럭에 실을 수 있는 재활용 택배 상자의 최대 개수
	@param n			배달할 집의 개수
	@param deliveries	각 집에 배달할 재활용 택배 상자의 개수를 담은 1차원 정수 배열
	@param pickups		각 집에서 수거할 빈 재활용 택배 상자의 개수를 담은 1차원 정수 배열
	
	@return				트럭 하나로 모든 배달과 수거를 마치고 물류창고까지 돌아올 수 있는 최소 이동거리
*/
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
	long long answer = 0;

	while (deliveries.size() || pickups.size()) {
		while (deliveries.size() && deliveries.back() == 0)
			deliveries.pop_back();

		while (pickups.size() && pickups.back() == 0)
			pickups.pop_back();

		// 각 턴에서의 왕복 거리
		answer += max(deliveries.size(), pickups.size()) * 2;

		update(deliveries, cap);
		update(pickups, cap);
	}

	return answer;
}