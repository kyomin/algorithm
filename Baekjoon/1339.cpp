#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

// �� ���ĺ��� �����ϴ� ���� ���� ���̴�.
int alphaNum[26];

// ���ڿ� �� ������ �ڸ���
vector<pair<char, int>> pairOfCharAndDigit;

vector<char> alpha;

// �ߺ��� ������ ���ڸ� ��´�
set<char> s;

// ġȯ�� ��
int num = 9;

// ���� �ش�
int ans = 0;

// �������� ����
bool cmp(const pair<char, int> &p1, const pair<char, int> &p2) {
	if (p1.second > p2.second)
		return true;
	else
		return false;
}

// ������ pow ���� (a^b)
int pow(int a, int b) {
	if (b == 0)
		return 1;

	return a * pow(a, b - 1);
}

// ������ �̿��� �ִ� ã��!
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	// ���ĺ��� �� ���ĺ��� ������ �ڸ��� �Է� ����
	for (int n = 0; n < N; n++) {
		string str;
		cin >> str;

		int len = str.size();

		for (int i = 0; i < len; i++) {
			pairOfCharAndDigit.push_back(make_pair(str[i], len - i));
			s.insert(str[i]);
		}
	}

	// ���ĺ��� ���Ϳ� ����
	for (auto i = s.begin(); i != s.end(); i++) {
		char c = *i;
		alpha.push_back(c);
	}

	// ���͵� ����!
	sort(alpha.begin(), alpha.end());
	sort(pairOfCharAndDigit.begin(), pairOfCharAndDigit.end(), cmp);

	do {
		// �տ������� �ϳ��� ����, ��� ������ ���� �ο�
		for (int i = 0, j = 9; i < alpha.size(); i++, j--) {
			alphaNum[(int)(alpha[i] - 65)] = j;
		}

		int sum = 0;

		int len = pairOfCharAndDigit.size();

		// ����� �����Ѵ�.
		for (int i = 0; i < len; i++) {
			char c = pairOfCharAndDigit[i].first;
			int digit = pairOfCharAndDigit[i].second;

			int idx = (int)(c - 65);

			sum += alphaNum[idx] * pow(10, digit - 1);
		}

		ans = max(ans, sum);
	} while (next_permutation(alpha.begin(), alpha.end()));

	cout << ans << '\n';

	return 0;
}