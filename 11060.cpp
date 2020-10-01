#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321;

int arr[1000];
int dp[1000];
int N;

int minJump(int start) {
	// 목적지에 도달한 경우
	if (start == N - 1)
		return 0;

	// 목적지에 도달 못하는 경우
	if (start >= N)
		return INF;

	// 메모제이션을 통한 중복 방지
	int &result = dp[start];

	// 이미 방문이 된 곳이어서 해답이 메모되었다면
	if (result != -1)
		return result;

	result = INF;

	for (int i = 1; i <= arr[start]; i++) 
		result = min(result, 1 + minJump(start + i));
	

	return result;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	memset(dp, -1, sizeof(dp));

	int result = minJump(0);

	if (result == INF)
		cout << -1 << '\n';
	else
		cout << result << '\n';

	return 0;
}