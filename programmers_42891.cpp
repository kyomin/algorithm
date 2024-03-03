#include <string>
#include <vector>
#include <algorithm>

#define ULL unsigned long long

using namespace std;

bool comp(const pair<int, int>& p1, const pair<int, int>& p2) {
	return p1.second < p2.second;
}

/*
	@param food_times		�� ������ ��� �Դµ� �ʿ��� �ð��� ��� �迭
	@param k		��Ʈ��ũ ��ְ� �߻��� �ð� k��

	@return					�� �� ���ĺ��� �ٽ� �����ϸ� �Ǵ��� ���� ��ȣ
*/
int solution(vector<int> food_times, long long k) {
	vector<pair<int, int>> foods;	// first: �ð�, second: ���� ��ȣ

	int len = food_times.size();

	for (int i = 0; i < len; i++)
		foods.push_back(make_pair(food_times.at(i), i + 1));

	sort(foods.begin(), foods.end());

	int pretime = 0;
	for (auto iter = foods.begin(); iter != foods.end(); iter++, len--) {
		ULL spend = (ULL)(iter->first - pretime)*len;

		// �ռ� ���İ� ���̰� ���� ��� skip
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