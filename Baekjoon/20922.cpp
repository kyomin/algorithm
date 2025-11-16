#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int freq[100001];

int main() {
	int N, K;
	cin >> N >> K;

	vector<int> arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int left = 0;
	int right = 0;
	int max_length = 0;

	for (int right = 0; right < N; right++) {
		int value = arr[right];
		
		freq[value]++;

		while (freq[value] > K) {
			freq[arr[left]]--;
			left++;
		}

		max_length = max(max_length, right - left + 1);
	}

	cout << max_length << endl;

	return 0;
}