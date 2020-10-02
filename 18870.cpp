#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	set<int> s;
	vector<int> origin_arr;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		origin_arr.push_back(n);
		s.insert(n);
	}

	vector<int> arr(s.begin(), s.end());	// set을 이용한 벡터 중복 제거 !

	for (int i = 0; i < N; i++) {
		int n = origin_arr[i];
		cout << lower_bound(arr.begin(), arr.end(), n) - arr.begin() << ' ';
	}

	cout << '\n';

	return 0;
}