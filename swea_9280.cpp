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

		// ���� ������ ���� ���
		int parkedNum = 0;

		// �ش�
		int ans = 0;

		// first : �� ��ȣ, second : ������ ��
		map<int, int> parkedCarInfo;

		// ���� ��⿭
		queue<int> q;

		// �� ������ ��� �Է�
		for (int i = 1; i <= n; i++) {
			cin >> parkingFee[i];
		}

		// �� ���� ���� �Է�
		for (int i = 1; i <= m; i++) {
			cin >> carWeight[i];
		}
		
		for (int i = 0; i < (2 * m); i++) {
			int car;
			cin >> car;

			// ��� : �ش� ������ ���� ���̶��
			if (car > 0) {
				// �������� �� �� �ִٸ� ��⿭�� �ִ´�.
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
			else {	// �ش� ������ �����ٸ�
				car *= (-1);

				int parkingNum = parkedCarInfo.find(car)->second;

				parkedCarInfo.erase(car);

				isParked[parkingNum] = false;

				parkedNum--;

				// ������� ������ �����Ѵٸ�
				if (!q.empty()) {
					// ���� ���� ���� ĭ ��ȣ�� �ִ´�.
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