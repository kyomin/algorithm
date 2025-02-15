#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct point {
	int x;
	int y;
}Point;

bool com(const Point &p1, const Point &p2) {
	if (p1.x < p2.x)
		return true;
	else if (p1.x == p2.x)
		return (p1.y < p2.y);
	else
		return false;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<Point> v;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		Point p;
		int n1, n2;
		cin >> n1 >> n2;

		p.x = n1;
		p.y = n2;

		v.push_back(p);
	}

	sort(v.begin(), v.end(), com);

	int len = v.size();

	for (int i = 0; i < len; i++)
		cout << v[i].x << ' ' << v[i].y << '\n';

	return 0;
}