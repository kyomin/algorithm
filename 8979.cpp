#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 각 나라의 메달 정보와 해당 국가 번호를 담기 위한 구조체
typedef struct info {
	int countryNum;
	int gold;
	int silver;
	int bronze;
}Info;

// 주어진 문제의 기준대로 정렬
bool comp(const Info &info1, const Info &info2) {
	if (info1.gold > info2.gold)
		return true;
	else if (info1.gold == info2.gold) {
		if (info1.silver > info2.silver)
			return true;
		else if (info1.silver == info2.silver) {
			if (info1.bronze > info2.bronze)
				return true;
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main() {
	int N, K;
	vector<Info> countries;

	cin >> N >> K;

	// 입력!
	for (int i = 0; i < N; i++) {
		int countryNum, gold, silver, bronze;
		cin >> countryNum >> gold >> silver >> bronze;
		
		Info info;
		info.countryNum = countryNum;
		info.gold = gold;
		info.silver = silver;
		info.bronze = bronze;

		countries.push_back(info);
	}

	// 정렬!
	sort(countries.begin(), countries.end(), comp);

	int targetIdx;

	// 등수를 구하고자 하는 타켓 나라를 찾는다.
	for (int i = 0; i < N; i++) {
		if (countries[i].countryNum == K) {
			targetIdx = i;
			break;
		}
	}

	int ans = targetIdx + 1;

	// 등수가 같은 나라가 있는지 확인하며 정답 갱신
	for (int i = targetIdx; i > 0; i--) {
		if (countries[targetIdx].gold == countries[i - 1].gold
			&& countries[targetIdx].silver == countries[i - 1].silver
			&& countries[targetIdx].bronze == countries[i - 1].bronze) {
			continue;
		}
		else {
			ans = i + 1;
			break;
		}
	}

	cout << ans << '\n';

	return 0;
}