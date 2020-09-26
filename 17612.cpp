#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct info {
	int id;			// 회원 id
	int weight;		// 상품 무게
	int checkStand;	// 현재 계산대
}Info;

bool comp(const Info &i1, const Info &i2) {
	if (i1.weight < i2.weight) {
		return true;
	}
	else if (i1.weight == i2.weight) {
		if (i1.checkStand > i2.checkStand)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main() {
	int N, k;
	// 결과 id들을 담을 벡터
	vector<int> result;

	// 고객 정보들
	vector<Info> customers;

	// 계산대
	vector<Info> checkStand;

	// 비어있는 계산대
	vector<int> emptyCheckStand;

	// 다음 대기 중인 고객을 가리킨다.
	int curPos = 0;

	cin >> N >> k;

	for (int i = 0; i < N; i++) {
		Info info;

		cin >> info.id;
		cin >> info.weight;

		customers.push_back(info);
	}

	// 일단 초기 고객들 다 밀어넣기
	for (int i = 1; i <= k; i++) {
		customers[curPos].checkStand = i;
		checkStand.push_back(customers[curPos]);
		curPos++;
	}

	while (curPos < N) {
		// 비어있는 계산대가 없다면
		if (emptyCheckStand.size() == 0) {
			// 기준대로 정렬해주고
			sort(checkStand.begin(), checkStand.end(), comp);

			// 맨 앞 요소의 weight이 현재 최소 weight이다.
			int minWeight = checkStand[0].weight;

			for (int i = 0; i < checkStand.size(); i++) {
				if (checkStand[i].weight == minWeight) {
					// 현재 빠져나가야 하는 최소 무게라면 비어있다고 표시한다.
					emptyCheckStand.push_back(checkStand[i].checkStand);
					
					checkStand[i].weight -= minWeight;

					// 그리고 결과 id에 순서대로 추가!
					result.push_back(checkStand[i].id);
				}
				else {
					checkStand[i].weight -= minWeight;
				}
			}
		}
		else {		// 비어있는 계산대가 있다면
			sort(emptyCheckStand.begin(), emptyCheckStand.end());

			for (int i = 0; i < emptyCheckStand.size(); i++) {
				if (curPos >= N)
					break;
				
				// 현재 빈 계산대 정보 넣어주고
				customers[curPos].checkStand = emptyCheckStand[i];
				
				// 고객을 계산대로 밀어넣고(인덱스 맞춰주기 위함)
				checkStand[i] = customers[curPos];

				// 다음 고객으로 포인터 이동!
				curPos++;
			}

			emptyCheckStand.clear();
		}
	}

	/* 최종 고객이 다 계산대에 들어갔더라도 아직 계산대에 남아있는 고객들 핸들링! */
	
	// 기준대로 정렬해주고
	sort(checkStand.begin(), checkStand.end(), comp);

	for (int i = 0; i < checkStand.size(); i++) {
		if(checkStand[i].weight != 0)
			result.push_back(checkStand[i].id);
	}

	unsigned long long ans = 0;

	for (int i = 0; i < result.size(); i++) {
		ans += result[i] * (i + 1);
	}

	cout << ans << '\n';
	
	return 0;
}