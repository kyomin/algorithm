#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int arr[100001];
const int INF = numeric_limits<int>::max();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, S;
	int length = INF;
	int low = 0;
	int high = 0;
	int sum = 0;

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	sum = arr[0];

	while (low <= high && high < N) {
		/* 
			현재 sum이 S보다 작은 경우 high를 +1 한다. 
		*/
		if (sum < S) {
			high += 1;
			sum += arr[high];
		}
		/* 
			현재 sum이 S와 같은 경우, 
			현재 length 값과 high-low+1 값을 비교해
			min을 length로 지정 후 
			high를 +1 한다.
		*/
		else if (sum == S) {
			length = min(length, (high - low + 1));
			high += 1;
			sum += arr[high];
		}
		/*
			현재 sum이 S보다 큰 경우,
			현재 length 값과 high-low+1 값을 비교해
			min을 length로 지정 후
			low를 +1 한다.
		*/
		else if (sum > S) {
			length = min(length, (high - low + 1));
			sum -= arr[low];
			low += 1;
		}
	}

	if (length == INF) cout << 0 << '\n';
	else cout << length << '\n';

	return 0;
}