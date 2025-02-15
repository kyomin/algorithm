#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<string> result;
	set<string> s1;
	set<string> s2;

	int sum = N + M;

	for (int i = 0; i < sum; i++) {
		string str;
		cin >> str;

		if (i < N)
			s1.insert(str);
		else
			s2.insert(str);
	}

	set_intersection(s1.begin(), s1.end(), s2.begin(), s2.end(), back_inserter(result));

	int len = result.size();
	cout << len << '\n';

	for (int i = 0; i < len; i++)
		cout << result[i] << '\n';

	return 0;
}