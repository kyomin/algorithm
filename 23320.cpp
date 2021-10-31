#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	int X, Y;
	vector<int> scores;
	cin >> N;
	scores.resize(N);

	for (int n = 0; n < N; n++)
		cin >> scores[n];

	cin >> X >> Y;

	int relative_num = N * ((float)X / 100);
	int absolute_num = 0;

	for (int n = 0; n < N; n++)
		if (scores[n] >= Y)
			absolute_num++;
	
	cout << relative_num << ' ' << absolute_num << endl;

	return 0;
}