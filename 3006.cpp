#include <iostream>

using namespace std;

int steps[100001];
int arr[100001];

int main() {
	int N;
	cin >> N;

	int step = 1, first = 1, last = N;

	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}

	while (step <= N) {
		// Ȧ�� �ܰ� => ���� ����
		if (step % 2 == 1) {
			int curIdx;		// Ÿ�� �߰� ���� �ε���
			int cnt = 0;	// �̵� Ƚ���� �� ���̴�.

			for (int i = 1; i <= N; i++) {
				if (arr[i] == first) {
					curIdx = i;
					break;
				}
			}

			// �� �������� �Ǵ� ��Ȳ
			if (first == curIdx)
				steps[step] = cnt;

			// �������� �̵�!
			for (int i = curIdx; i > first; i--) {
				// swap !!
				int temp = arr[i-1];
				arr[i - 1] = arr[i];
				arr[i] = temp;
				cnt++;
			}

			steps[step] = cnt;
			first++;
			step++;
		}
		else {		// ¦�� �ܰ� => ū ����
			int curIdx;		// Ÿ�� �߰� ���� �ε���
			int cnt = 0;	// �̵� Ƚ���� �� ���̴�.

			for (int i = 1; i <= N; i++) {
				if (arr[i] == last) {
					curIdx = i;
					break;
				}
			}

			// �� �������� �Ǵ� ��Ȳ
			if (first == curIdx)
				steps[step] = cnt;

			// ���������� �̵�!
			for (int i = curIdx; i < last; i++) {
				// swap !!
				int temp = arr[i + 1];
				arr[i + 1] = arr[i];
				arr[i] = temp;
				cnt++;
			}

			steps[step] = cnt;
			last--;
			step++;
		}
	}

	for (int i = 1; i <= N; i++) {
		cout << steps[i] << '\n';
	}

	return 0;
}