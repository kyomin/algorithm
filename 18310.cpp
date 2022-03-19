#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	vector<int> house;

	cin >> N;
	house.resize(N);

	for (int i = 0; i < N; i++)
		cin >> house[i];

	sort(house.begin(), house.end());

	if (N % 2 == 1)
		cout << house[N / 2] << endl;
	else
		cout << house[(N / 2) - 1] << endl;

	return 0;
}