#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool comp(const pair<int, string> &p1, const pair<int, string> &p2) {
	if (p1.first > p2.first)
		return true;
	else if (p1.first == p2.first) {
		if (p1.second < p2.second)
			return true;
		else
			return false;
	}
	else
		return false;
}

int calcProbability(int L, int O, int V, int E) {
	return (((L + O)*(L + V)*(L + E)*(O + V)*(O + E)*(V + E)) % 100);
}

int main() {
	int me_L = 0;
	int me_O = 0;
	int me_V = 0;
	int me_E = 0;
	string me;
	cin >> me;

	int len = me.length();
	for (int i = 0; i < len; i++) {
		char ch = me[i];

		if (ch == 'L')
			me_L++;
		else if (ch == 'O')
			me_O++;
		else if (ch == 'V')
			me_V++;
		else if (ch == 'E')
			me_E++;
	}

	vector<pair<int, string>> womans;
	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int num_L = 0;
		int num_O = 0;
		int num_V = 0;
		int num_E = 0;
		string woman;
		cin >> woman;

		len = woman.length();
		for (int i = 0; i < len; i++) {
			char ch = woman[i];

			if (ch == 'L')
				num_L++;
			else if (ch == 'O')
				num_O++;
			else if (ch == 'V')
				num_V++;
			else if (ch == 'E')
				num_E++;
		}

		int probability = calcProbability(me_L + num_L, me_O + num_O, me_V + num_V, me_E + num_E);
		womans.push_back(make_pair(probability, woman));
	}

	sort(womans.begin(), womans.end(), comp);

	cout << womans[0].second << endl;

	return 0;
}