#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool comp(int a, int b) {
	if (a > b)
		return true;
	else
		return false;
}

int main() {
	vector<int> scores;
	int N, k;
	cin >> N >> k;

	scores.resize(N);

	for (int i = 0; i < N; i++)
		cin >> scores[i];

	sort(scores.begin(), scores.end(), comp);

	cout << scores[k - 1] << endl;

	return 0;
}