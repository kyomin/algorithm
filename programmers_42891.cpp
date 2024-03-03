#include <string>
#include <vector>
#include <algorithm>

#define ULL unsigned long long

using namespace std;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.second < p2.second;
}

/*
	@param food_times		각 음식을 모두 먹는데 필요한 시간이 담긴 배열
	@param k		네트워크 장애가 발생한 시간 k초

	@return					몇 번 음식부터 다시 섭취하면 되는지 음식 번호
*/
int solution(vector<int> food_times, long long k) {
	vector<pair<int, int>> foods;	// first: 시간, second: 음식 번호

	int len = food_times.size();

	for (int i = 0; i < len; i++)
		foods.push_back(make_pair(food_times.at(i), i + 1));

	sort(foods.begin(), foods.end());

	int pretime = 0;
	for (auto iter = foods.begin(); iter != foods.end(); iter++, len--) {
		ULL spend = (ULL)(iter->first - pretime)*len;

		// 앞선 음식과 차이가 없을 경우 skip
		if (spend == 0)
			continue;

		if (spend <= k) {
			k -= spend;
			pretime = iter->first;
		}
		else {
			k %= len;
			sort(iter, foods.end(), comp);
			
			return (iter + k)->second;
		}
	}

	return -1;
}