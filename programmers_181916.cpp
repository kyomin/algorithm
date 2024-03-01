#include <string>
#include <vector>
#include <cmath>
using namespace std;

int dice[7] = { 0 };

int solution(int a, int b, int c, int d) {
	int answer = 0;

	int count4 = 0;
	int count3 = 0;
	int count2 = 0;
	int count1 = 0;

	dice[a]++;
	dice[b]++;
	dice[c]++;
	dice[d]++;

	for (int i = 1; i <= 6; i++) {
		int count = dice[i];

		if (count == 0)
			continue;

		switch (count) {
			case 4: {
				count4++;
				break;
			}
			case 3: {
				count3++;
				break;
			}
			case 2: {
				count2++;
				break;
			}
			default: {
				count1++;
			}
		}
	}

	// 네 주사위에 적힌 숫자가 모두 다른 경우
	if (count1 == 4) {
		for (int i = 1; i <= 6; i++) {
			if (dice[i] == 1) {
				answer = i;
				break;
			}
		}
	}
	// 네 주사위에서 나온 숫자가 모두 p로 같은 경우
	else if (count4 == 1) {
		for (int i = 1; i <= 6; i++) {
			if (dice[i] == 4) {
				answer = i * 1111;
				break;
			}
		}
	}
	// 세 주사위에서 나온 숫자가 p로 같고, 나머지 하나가 q인 경우
	else if (count3 == 1) {
		int p, q;

		for (int i = 1; i <= 6; i++) {
			if (dice[i] == 3)
				p = i;

			if (dice[i] == 1)
				q = i;
		}

		answer = pow(((10 * p) + q), 2);
	}
	// 주사위가 두 개씩 같은 값이 나오고, 나온 각 숫자가 p, q인 경우
	else if (count2 == 2) {
		bool flag = false;
		int p, q;
		
		for (int i = 1; i <= 6; i++) {			
			if (dice[i] == 2) {
				// p를 먼저 세팅
				if (!flag) {
					p = i;
					flag = true;
				}
				else {
					q = i;
				}
			}
		}

		answer = ((p + q)*abs(p - q));
	}
	// 나머지의 경우.
	else {
		bool flag = false;
		int p, q;

		for (int i = 1; i <= 6; i++) {
			if (dice[i] == 1) {
				// p를 먼저 세팅
				if (!flag) {
					p = i;
					flag = true;
				}
				else {
					q = i;
				}
			}
		}

		answer = p * q;
	}

	return answer;
}