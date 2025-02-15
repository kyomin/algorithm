#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> flowerpots;

bool checkFirstDeath() {
	int len = flowerpots.size();
	bool flag = false;

	for (int i = 0; i < len; i++) {
		if (flowerpots[i] == 0) {
			flag = true;
			break;
		}
	}

	return flag;
}

void decreaseWater() {
	for (int i = 0; i < flowerpots.size(); i++)
		flowerpots[i]--;
}

int main() {
	int day = 1;
	int N, K, A, B;
	cin >> N >> K >> A >> B;
	flowerpots.resize(N);

	// 초기 수분으로 초기화
	for (int i = 0; i < N; i++)
		flowerpots[i] = K;

	while (true) {
		sort(flowerpots.begin(), flowerpots.end());
		decreaseWater();

		for (int i = 0; i < A; i++)
			flowerpots[i] += B;

		if (checkFirstDeath())
			break;

		day++;
	}

	cout << day << endl;

	return 0;
}