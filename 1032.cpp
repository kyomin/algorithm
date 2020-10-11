#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	string result = "";
	vector<string> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}

	// 파일 이름의 길이는 모두 같다는 가정이므로
	int len = v[0].size();

	// 파일 이름 하나만 입력한 경우
	if (N == 1) {
		cout << v[0] << endl;
		return 0;
	}

	// 각 자릿수의 문자를 비교하며
	for (int i = 0; i < len; i++) {
		char c = v[0][i];

		// 같은 것의 개수를 셀 것이다.
		int count = 0;

		for (int j = 1; j < N; j++)
			if (c == v[j][i])
				count++;

		// 해당 자릿수의 모든 문자가 일치하면
		if (count == (N - 1))
			result += c;

		else
			result += '?';
	}

	cout << result << endl;

	return 0;
}