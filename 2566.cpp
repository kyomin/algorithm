#include <iostream>
#include <queue>

using namespace std;

struct A {
	int value;
	int row;
	int col;
};

struct cmp {
	bool operator()(A t, A u) {
		return t.value < u.value;
	}
};

priority_queue< A, vector<A>, cmp > pq;

int main() {
	for (int row = 1; row <= 9; row++) {
		for (int col = 1; col <= 9; col++) {
			int num;
			cin >> num;
			
			A a;
			a.row = row;
			a.col = col;
			a.value = num;

			pq.push(a);
		}
	}

	A result = pq.top();

	cout << result.value << '\n';

	cout << result.row << ' ' << result.col << '\n';

	return 0;
}