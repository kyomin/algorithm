#include <iostream>
#include <map>
#include <cstring>
#include <queue>

using namespace std;

bool isParked[101];
int parkingFee[101];
int carWeight[101];

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int n, m;
		cin >> n >> m;

		memset(isParked, false, sizeof(isParked));
		memset(parkingFee, 0, sizeof(parkingFee));

		// 현재 주차된 차량 대수
		int parkedNum = 0;

		// 해답
		int ans = 0;

		// first : 차 번호, second : 주차된 곳
		map<int, int> parkedCarInfo;

		// 차량 대기열
		queue<int> q;

		// 각 주차장 요금 입력
		for (int i = 1; i <= n; i++) {
			cin >> parkingFee[i];
		}

		// 각 차량 무게 입력
		for (int i = 1; i <= m; i++) {
			cin >> carWeight[i];
		}
		
		for (int i = 0; i < (2 * m); i++) {
			int car;
			cin >> car;

			// 양수 : 해당 차량이 들어온 것이라면
			if (car > 0) {
				// 주차장이 꽉 차 있다면 대기열에 넣는다.
				if (parkedNum == n) {
					q.push(car);
					continue;
				}

				for (int park = 1; park <= n; park++) {
					if (!isParked[park]) {
						ans += parkingFee[park] * carWeight[car];
						
						isParked[park] = true;
						
						parkedCarInfo.insert(make_pair(car, park));
						
						parkedNum++;

						break;
					}
				}
			}
			else {	// 해당 차량을 꺼낸다면
				car *= (-1);

				int parkingNum = parkedCarInfo.find(car)->second;

				parkedCarInfo.erase(car);

				isParked[parkingNum] = false;

				parkedNum--;

				// 대기중인 차량이 존재한다면
				if (!q.empty()) {
					// 가장 작은 주차 칸 번호에 넣는다.
					for (int park = 1; park <= n; park++) {
						if (!isParked[park]) {
							car = q.front();
							q.pop();

							ans += parkingFee[park] * carWeight[car];

							isParked[park] = true;

							parkedCarInfo.insert(make_pair(car, park));

							parkedNum++;

							break;
						}
					}
				}
			}
		}

		cout << '#' << t << ' ' << ans << '\n';
	}

	return 0;
}