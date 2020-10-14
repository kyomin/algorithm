#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

struct a {
	int val;	// 원래 값
	int absolute;	// 절대 값
};

struct cmp {
	bool operator()(a t, a u) {
		if (t.absolute != u.absolute)
			return t.absolute > u.absolute;
		else
			return t.val > u.val;
	}
};

priority_queue<a, vector<a>, cmp> pq;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (n == 0) {
			if (pq.size() == 0)
				cout << 0 << '\n';
			else {
				cout << pq.top().val << '\n';
				pq.pop();
			}
		}
		else {
			a temp = { n, abs(n) };
			pq.push(temp);
		}
	}

	return 0;
}