#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>

using namespace std;

// 각 알파벳에 대응하는 값을 넣을 것이다.
int alphaNum[26];

// 문자와 각 문자의 자릿수
vector<pair<char, int>> pairOfCharAndDigit;

vector<char> alpha;

// 중복을 제거한 문자만 담는다
set<char> s;

// 치환될 수
int num = 9;

// 최종 해답
int ans = 0;

// 내림차순 정렬
bool cmp(const pair<char, int> &p1, const pair<char, int> &p2) {
	if (p1.second > p2.second)
		return true;
	else
		return false;
}

// 정수형 pow 정의 (a^b)
int pow(int a, int b) {
	if (b == 0)
		return 1;

	return a * pow(a, b - 1);
}

// 순열을 이용해 최댓값 찾기!
int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	// 알파벳과 그 알파벳이 가지는 자릿수 입력 과정
	for (int n = 0; n < N; n++) {
		string str;
		cin >> str;

		int len = str.size();

		for (int i = 0; i < len; i++) {
			pairOfCharAndDigit.push_back(make_pair(str[i], len - i));
			s.insert(str[i]);
		}
	}

	// 알파벳을 벡터에 저장
	for (auto i = s.begin(); i != s.end(); i++) {
		char c = *i;
		alpha.push_back(c);
	}

	// 벡터들 정렬!
	sort(alpha.begin(), alpha.end());
	sort(pairOfCharAndDigit.begin(), pairOfCharAndDigit.end(), cmp);

	do {
		// 앞에서부터 하나씩 진행, 모든 가능한 점수 부여
		for (int i = 0, j = 9; i < alpha.size(); i++, j--) {
			alphaNum[(int)(alpha[i] - 65)] = j;
		}

		int sum = 0;

		int len = pairOfCharAndDigit.size();

		// 계산을 진행한다.
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