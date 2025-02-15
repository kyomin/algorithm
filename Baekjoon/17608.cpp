#include <iostream>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	int N;
	cin >> N;
	
	v.resize(N);

	for (int n = 0; n < N; n++)
		cin >> v[n];

	int ans = 1;	// 맨 마지막 막대기는 항상 보이므로
	int cur_pole_size = v[N - 1];

	for (int i = N - 2; i >= 0; i--) {
		int pole_size = v[i];

		if (pole_size > cur_pole_size) {
			ans++;
			cur_pole_size = pole_size;
		}
	}

	cout << ans << '\n';

	return 0;
}