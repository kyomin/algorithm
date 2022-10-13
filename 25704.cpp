#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int ans = 987654321;
	int stamp;
	int cost;
	cin >> stamp >> cost;

	int temp;
	int discount;
	if (stamp >= 20) {		
		// 1. 5���� ���
		temp = cost - 500;
		temp = temp < 0 ? 0 : temp;
		ans = min(ans, temp);

		// 2. 10���� ���
		discount = (int)(cost*0.1);
		temp = cost - discount;
		temp = temp < 0 ? 0 : temp;
		ans = min(ans, temp);

		// 3. 15���� ���
		temp = cost - 2000;
		temp = temp < 0 ? 0 : temp;
		ans = min(ans, temp);

		// 4. 20���� ���
		discount = (int)(cost*0.25);
		temp = cost - discount;
		temp = temp < 0 ? 0 : temp;
		ans = min(ans, temp);
	}
	else if (stamp >= 15) {
		// 1. 5���� ���
		temp = cost - 500;
		temp = temp < 0 ? 0 : temp;
		ans = min(ans, temp);

		// 2. 10���� ���
		discount = (int)(cost*0.1);
		temp = cost - discount;
		temp = temp < 0 ? 0 : temp;
		ans = min(ans, temp);

		// 3. 15���� ���
		temp = cost - 2000;
		temp = temp < 0 ? 0 : temp;
		ans = min(ans, temp);
	}
	else if (stamp >= 10) {
		// 1. 5���� ���
		temp = cost - 500;
		temp = temp < 0 ? 0 : temp;
		ans = min(ans, temp);

		// 2. 10���� ���
		discount = (int)(cost*0.1);
		temp = cost - discount;
		temp = temp < 0 ? 0 : temp;
		ans = min(ans, temp);
	}
	else if (stamp >= 5) {
		// 1. 5���� ���
		temp = cost - 500;
		temp = temp < 0 ? 0 : temp;
		ans = min(ans, temp);
	}
	else {
		// ���� ����
		ans = min(ans, cost);
	}

	cout << ans << endl;

	return 0;
}