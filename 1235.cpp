#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main() {
	vector<string> students;
	int ans;
	int N;
	cin >> N;
	students.resize(N);

	for (int i = 0; i < N; i++)
		cin >> students[i];

	// 편의를 위해 뒤집는다.
	for (int i = 0; i < N; i++)
		reverse(students[i].begin(), students[i].end());

	int length = students[0].length();
	for (int len = 1; len <= length; len++) {
		set<string> s;

		for (int i = 0; i < N; i++) {
			string student = students[i];
			s.insert(student.substr(0, len));
		}

		if (s.size() == N) {
			ans = len;
			break;
		}
	}

	cout << ans << endl;

	return 0;
}