#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int>& a, const pair<int, int>& b) {
	if (a.second > b.second)
		return true;
	else
		return false;
}

int solution(int k, vector<int> tangerine) {
	int answer = 0;
	map<int, int> save;
	vector<pair<int, int>> v;

	for (int num : tangerine) {
		if (save.find(num) != save.end()) {
			// 기존에 등록된 크기라면 빈도수 증가
			save[num] += 1;
		}
		else {
			// 신규 등록
			save.insert(pair<int, int>(num, 1));
		}
	}

	// map to vector
	copy(save.begin(), save.end(), back_inserter(v));

	// 정렬
	sort(v.begin(), v.end(), comp);

	// 개수가 많은 것부터 선택(서로 다른 크기 종류를 최소화 하기 위함)
	int index = 0;
	while (k > 0) {
		if (k <= v[index].second) {
			answer += 1;
			break;
		}
		else {
			answer += 1;
			k -= v[index].second;
		}

		index += 1;
	}

	return answer;
}