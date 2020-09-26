#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int solution(string init, string target, int len) {
	int case1 = 0;	// ���� ���� �ٸ��� init�� W�� ���
	int case2 = 0;	// ���� ���� �ٸ��� init�� B�� ���

	for (int i = 0; i < len; i++) {
		if (init[i] == target[i])
			continue;

		if (init[i] == 'W')
			case1++;
		else
			case2++;
	}

	return max(case1, case2);
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		int len;
		string init, target;
		cin >> len;
		cin >> init >> target;

		cout << solution(init, target, len) << '\n';
	}

	return 0;
}