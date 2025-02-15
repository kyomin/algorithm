#include <iostream>

using namespace std;

int examinee[1000001];

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		cin >> examinee[i];

	int generalSupervisor, deputySupervisor;

	cin >> generalSupervisor >> deputySupervisor;

	unsigned long long ans = 0;

	// 응시생이 모두 감독되는 시험장 개수를 센다.
	int zeroCount = 0;

	// 우선 총감독관이 감독하는 경우를 계산한다.
	for (int i = 1; i <= N; i++) {
		examinee[i] -= generalSupervisor;
		
		if (examinee[i] <= 0) 
			zeroCount++;

		ans++;
	}

	// 총감독관에 의해 모든 시험장이 통제되면
	if (zeroCount == N) {
		cout << ans << '\n';
		return 0;
	}

	// 부감독관이 감독하는 경우를 계산한다.
	for (int i = 1; i <= N; i++) {
		if (examinee[i] <= 0)
			continue;

		if (examinee[i] % deputySupervisor == 0) {
			ans += (examinee[i] / deputySupervisor);
			examinee[i] -= (examinee[i] / deputySupervisor);
		}
		else {
			ans += ( (examinee[i] / deputySupervisor) + 1);
			examinee[i] -= ((examinee[i] / deputySupervisor) + 1);
		}
	}
	
	cout << ans << '\n';
	return 0;
}