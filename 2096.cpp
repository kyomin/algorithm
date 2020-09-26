#include <iostream>
#include <algorithm>

using namespace std;

int **dp;
int **arr;
int N;

// 동적 배열 할당!
void allocateArray() {
	dp = new int*[N];
	arr = new int*[N];

	for (int i = 0; i < N; i++) {
		dp[i] = new int[N];
		arr[i] = new int[N];
	}
}

// 최대 점수를 얻는 계산
int maxSolution(int y, int x) {
	// 끝 라인이라면
	if (y == N-1)
		return arr[y][x];

	dp[y][x] = arr[y][x];

	// 일단 다음 행으로!
	int nextY = y + 1;

	// 3가지 경우
	int case1=0, case2=0, case3=0;

	// 바로 다음 라인으로 넘어가는 경우
	case1 = maxSolution(nextY, x);
	

	// 왼쪽으로 1칸 이동 후 다음 라인으로 넘어가는 경우
	if (x - 1 >= 0) {
		case2 = maxSolution(nextY, x-1);
	}

	// 오른쪽으로 1칸 이동 후 다음 라인으로 넘어가는 경우
	if (x + 1 < N) {
		case3 = maxSolution(nextY, x+1);
	}

	dp[y][x] += max(max(case1, case2), case3);
	
	
	return dp[y][x];
}


// 최소 점수를 얻는 계산
int minSolution(int y, int x) {
	// 끝 라인이라면
	if (y == N - 1)
		return arr[y][x];

	dp[y][x] = arr[y][x];

	// 일단 다음 행으로!
	int nextY = y + 1;

	// 3가지 경우
	int case1 = 900000, case2 = 900000, case3 = 900000;

	// 바로 다음 라인으로 넘어가는 경우
	case1 = minSolution(nextY, x);


	// 왼쪽으로 1칸 이동 후 다음 라인으로 넘어가는 경우
	if (x - 1 >= 0) {
		case2 = minSolution(nextY, x - 1);
	}

	// 오른쪽으로 1칸 이동 후 다음 라인으로 넘어가는 경우
	if (x + 1 < N) {
		case3 = minSolution(nextY, x + 1);
	}

	dp[y][x] += min(min(case1, case2), case3);


	return dp[y][x];
}


int main() {
	cin >> N;

	// 입력받은 N 크기만큼 동적 배열 할당!
	allocateArray();

	// 배열에 값 입력!
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}

	/*		최대 구하기		*/	
	for (int i = 0; i < N; i++)
		maxSolution(0, i);

	int maxResult = 0;

	for (int i = 0; i < N; i++)
		maxResult = max(maxResult, dp[0][i]);

	/*		최소 구하기		*/
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