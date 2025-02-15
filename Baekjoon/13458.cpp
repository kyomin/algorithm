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

	// ���û��� ��� �����Ǵ� ������ ������ ����.
	int zeroCount = 0;

	// �켱 �Ѱ������� �����ϴ� ��츦 ����Ѵ�.
	for (int i = 1; i <= N; i++) {
		examinee[i] -= generalSupervisor;
		
		if (examinee[i] <= 0) 
			zeroCount++;

		ans++;
	}

	// �Ѱ������� ���� ��� �������� �����Ǹ�
	if (zeroCount == N) {
		cout << ans << '\n';
		return 0;
	}

	// �ΰ������� �����ϴ� ��츦 ����Ѵ�.
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