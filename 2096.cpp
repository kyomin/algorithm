#include <iostream>
#include <algorithm>

using namespace std;

int **dp;
int **arr;
int N;

// ���� �迭 �Ҵ�!
void allocateArray() {
	dp = new int*[N];
	arr = new int*[N];

	for (int i = 0; i < N; i++) {
		dp[i] = new int[N];
		arr[i] = new int[N];
	}
}

// �ִ� ������ ��� ���
int maxSolution(int y, int x) {
	// �� �����̶��
	if (y == N-1)
		return arr[y][x];

	dp[y][x] = arr[y][x];

	// �ϴ� ���� ������!
	int nextY = y + 1;

	// 3���� ���
	int case1=0, case2=0, case3=0;

	// �ٷ� ���� �������� �Ѿ�� ���
	case1 = maxSolution(nextY, x);
	

	// �������� 1ĭ �̵� �� ���� �������� �Ѿ�� ���
	if (x - 1 >= 0) {
		case2 = maxSolution(nextY, x-1);
	}

	// ���������� 1ĭ �̵� �� ���� �������� �Ѿ�� ���
	if (x + 1 < N) {
		case3 = maxSolution(nextY, x+1);
	}

	dp[y][x] += max(max(case1, case2), case3);
	
	
	return dp[y][x];
}


// �ּ� ������ ��� ���
int minSolution(int y, int x) {
	// �� �����̶��
	if (y == N - 1)
		return arr[y][x];

	dp[y][x] = arr[y][x];

	// �ϴ� ���� ������!
	int nextY = y + 1;

	// 3���� ���
	int case1 = 900000, case2 = 900000, case3 = 900000;

	// �ٷ� ���� �������� �Ѿ�� ���
	case1 = minSolution(nextY, x);


	// �������� 1ĭ �̵� �� ���� �������� �Ѿ�� ���
	if (x - 1 >= 0) {
		case2 = minSolution(nextY, x - 1);
	}

	// ���������� 1ĭ �̵� �� ���� �������� �Ѿ�� ���
	if (x + 1 < N) {
		case3 = minSolution(nextY, x + 1);
	}

	dp[y][x] += min(min(case1, case2), case3);


	return dp[y][x];
}


int main() {
	cin >> N;

	// �Է¹��� N ũ�⸸ŭ ���� �迭 �Ҵ�!
	allocateArray();

	// �迭�� �� �Է�!
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	/*		�ִ� ���ϱ�		*/	
	for (int i = 0; i < N; i++)
		maxSolution(0, i);

	int maxResult = 0;

	for (int i = 0; i < N; i++)
		maxResult = max(maxResult, dp[0][i]);

	/*		�ּ� ���ϱ�		*/
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			dp[i][j] = 0;

	for (int i = 0; i < N; i++)
		minSolution(0, i);

	int minResult = 900000;

	for (int i = 0; i < N; i++)
		minResult = min(minResult, dp[0][i]);

	cout << maxResult << ' ' << minResult << '\n';

	return 0;
}