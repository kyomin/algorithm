#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	vector<int> v;
	string str1, str2;
	cin >> str1 >> str2;

	// 번갈아 이름을 붙여서 저장하기 위한 변수
	string result = "";

	int len = str1.size();

	for (int i = 0; i < len; i++) {
		result += str1[i];
		result += str2[i];
	}

	len = result.size();

	for (int i = 0; i < len; i++) {
		int n = (int)(result[i] - '0');
		v.push_back(n);
	}

	// 최종적으로 더해나가는 연산에서는 마지막에 2개만 남으므로 길이가 2가 아닐 때까지!
	while (len != 2) {
		// 더하는 작업을 해준다.
		for (int i = 0; i < len - 1; i++) {
			v[i] += v[i + 1];

			if (v[i] >= 10)
				v[i] %= 10;
		}

		// 처음 길이를 담은 변수 감소시키기!
		len--;
	}

	// 최종적으로 v[0]과 v[1]에 담긴다. 이때, 10보다 크거나 같으면!
	if (v[0] >= 10)
		v[0] %= 10;

	cout << v[0] << v[1] << '\n';

	return 0;
}