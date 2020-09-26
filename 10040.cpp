#include <iostream>

using namespace std;

int A[1001];
int B[1001];
int voted[1001];

int main() {
	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) {
		cin >> A[i];
	}

	for (int i = 1; i <= M; i++) {
		cin >> B[i];
	}

	for (int i = 1; i <= M; i++) {
		for (int j = 1; j <= N; j++) {
			if (A[j] <= B[i]) {
				voted[j] += 1;
				break;
			}
		}
	}

	// �켱 ù ��°�� ����
	int maxVoted = 1;
	int maxValue = voted[1];

	for (int i = 2; i <= N; i++) {
		// ��ǥ�� �������� ����
		if (maxValue < voted[i]) {
			maxVoted = i;
			maxValue = voted[i];
		}
	}

	cout << maxVoted << '\n';

	return 0;
}