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

	// �� �ֻ����� ���� ���ڰ� ��� �ٸ� ���
	if (count1 == 4) {
		for (int i = 1; i <= 6; i++) {
			if (dice[i] == 1) {
				answer = i;
				break;
			}
		}
	}
	// �� �ֻ������� ���� ���ڰ� ��� p�� ���� ���
	else if (count4 == 1) {
		for (int i = 1; i <= 6; i++) {
			if (dice[i] == 4) {
				answer = i * 1111;
				break;
			}
		}
	}
	// �� �ֻ������� ���� ���ڰ� p�� ����, ������ �ϳ��� q�� ���
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
	// �ֻ����� �� ���� ���� ���� ������, ���� �� ���ڰ� p, q�� ���
	else if (count2 == 2) {
		bool flag = false;
		int p, q;
		
		for (int i = 1; i <= 6; i++) {			
			if (dice[i] == 2) {
				// p�� ���� ����
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
	// �������� ���.
	else {
		bool flag = false;
		int p, q;

		for (int i = 1; i <= 6; i++) {
			if (dice[i] == 1) {
				// p�� ���� ����
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