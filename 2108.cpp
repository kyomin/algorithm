#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

bool com(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.second < p2.second)
		return true;
	else if (p1.second == p2.second) {
		if (p1.first < p2.first)
			return true;
		else
			return false;
	}
	else
		return false;
}

bool com1(const pair<int, int> &p1, const pair<int, int> &p2) {
	if (p1.first < p2.first)
		return true;
	else
		return false;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int *A = new int[N];
	map<int, int> m;
	vector<pair<int, int>> v;

	double avg;
	int middle;
	int freq;
	int range;
	int sum = 0;

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;

		if (m.find(n) == m.end())
			m[n] = 1;
		else
			m.find(n)->second += 1;

		A[i] = n;

		sum += n;
	}

	avg = (double)sum / N;
	avg = round(avg);

	copy(m.begin(), m.end(), back_inserter(v));

	sort(v.begin(), v.end(), com);
	sort(A, A + N);

	middle = A[N / 2];

	int len = v.size();

	if (N == 1)
		freq = v[0].first;
	else if (N == 2)
		freq = v[1].first;

	int max_fre = v[len - 1].second;

	vector<pair<int, int>> v_fre;
	v_fre.push_back(v[len - 1]);

	for (int i = len - 2; i >= 0; i--) {
		if (v[i].second == max_fre)
			v_fre.push_back(v[i]);
		else
			break;
	}

	sort(v_fre.begin(), v_fre.end(), com1);

	if (v_fre.size() == 1)
		freq = v_fre[0].first;
	else
		freq = v_fre[1].first;

	range = A[N - 1] - A[0];

	cout << avg << '\n';
	cout << middle << '\n';
	cout << freq << '\n';
	cout << range << '\n';

	return 0;
}