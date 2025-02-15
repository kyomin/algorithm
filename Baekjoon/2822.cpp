#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef struct score {
	int score;
	int index;
}Score;

bool com1(const Score &s1, const Score &s2) {
	if (s1.score > s2.score)
		return true;
	else
		return false;
}

bool com2(const Score &s1, const Score &s2) {
	if (s1.index < s2.index)
		return true;
	else
		return false;
}

int main() {
	vector<Score> v;

	for (int i = 1; i <= 8; i++) {
		int n;
		cin >> n;

		Score s;
		s.score = n;
		s.index = i;

		v.push_back(s);
	}

	sort(v.begin(), v.end(), com1);

	int sum = 0;

	for (int i = 0; i < 5; i++)
		sum += v[i].score;

	for (auto iter = v.begin() + 5; iter != v.end();)
		iter = v.erase(iter);

	sort(v.begin(), v.end(), com2);

	cout << sum << endl;

	for (int i = 0; i < 5; i++)
		cout << v[i].index << ' ';

	cout << endl;

	return 0;
}