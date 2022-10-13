#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	vector<long long> cards;
	int N, M;
	cin >> N >> M;
	cards.resize(N);
	for (int i = 0; i < N; i++)
		cin >> cards[i];

	long long ans = 0;
	while (M--) {
		sort(cards.begin(), cards.end());
		long long sum = cards[0] + cards[1];
		cards[0] = sum;
		cards[1] = sum;
	}

	for (int i = 0; i < N; i++)
		ans += cards[i];

	cout << ans << endl;

	return 0;
}