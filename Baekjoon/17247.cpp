#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	vector<pair<int, int>> dots;
	int N, M;
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			int num;
			cin >> num;

			if (num == 1) {
				dots.push_back(make_pair(i, j));
			}
		}
	}
	
	int x1 = dots[0].first;
	int y1 = dots[0].second;
	int x2 = dots[1].first;
	int y2 = dots[1].second;
	
	cout << abs(x1 - x2) + abs(y1 - y2) << endl;

	return 0;
}