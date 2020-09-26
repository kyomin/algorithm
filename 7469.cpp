#include <iostream>
#include <queue>

using namespace std;

int arr[100001];
int n, m;

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		cin >> arr[i];

	for (int t = 0; t < m; t++) {
		int i, j, k;
		priority_queue<int, vector<int>, less<int>> pq;

		cin >> i >> j >> k;
		
		for (int idx = i; idx <= j; idx++) {
			if((idx-i+1)<=k)
				pq.push(arr[idx]);
			else {
				pq.push(arr[idx]);
				pq.pop();
			}
		}

		cout << pq.top() << '\n';
	}

	return 0;
}