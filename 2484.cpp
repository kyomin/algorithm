#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin >> N;

	int ans = 0;

	for (int n = 0; n < N; n++) {
		int dice[7] = { 0, };
		int prize = 0;

		for (int i = 0; i < 4; i++) {
			int noon;
			cin >> noon;

			dice[noon] += 1;
		}
	
		int same4 = 0, same3 = 0, same2 = 0, same1 = 0;
		vector<int> idx4, idx3, idx2, idx1;		// 각 나온 횟수에 해당하는 눈

		// 같은 눈의 개수 세기
		for (int i = 1; i <= 6; i++) {
			if (dice[i] == 4) {
				same4++;
				idx4.push_back(i);
			}
			else if (dice[i] == 3) {
				same3++;
				idx3.push_back(i);
			}
			else if (dice[i] == 2) {
				same2++;
				idx2.push_back(i);
			}
			else if (dice[i] == 1) {
				same1++;
				idx1.push_back(i);
			}
		}

		// 경우의 수를 판단한다.
		if (same4 == 1) {
			prize = 50000 + (idx4[0] * 5000);
		}
		else if (same3 == 1) {
			prize = 10000 + (idx3[0] * 1000);
		}
		else if (same2 == 2) {
			prize = 2000 + (idx2[0] * 500) + (idx2[1] * 500);
		} 
		else if (same2 == 1) {
			prize = 1000 + (idx2[0] * 100);
		} 
		else {
			prize = idx1[3] * 100;
		}

		ans = max(ans, prize);
	}

	cout << ans << endl;

	return 0;
}