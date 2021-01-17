#include <iostream>
#include <string>

using namespace std;

int n;
bool stop = false;

bool isSatisfy(string s) {
	int len = s.size();
	int loop = len / 2;		// 비교할 수 있는 횟수와 기준은 길이의 절반이다.

	// 길이 1 ~ (len/2)까지 부분 문자열 비교를 차차 해 나간다
	for (int num = 1; num <= loop; num++) {
		for (int i = 0; i < len; i++) {
			if (i + num >= len)
				break;

			if (i + num + num - 1 >= len)
				break;

			string left = s.substr(i, num);
			string right = s.substr(i + num, num);

			// 같은 것이 발견되는 순간, 조건 만족을 하지 못하는 것이다.
			if (left == right)
				return false;
		}
	}

	// 위의 for문을 통과했다면, 좋은 수열이다.
	return true;
}

void dfs(int len, string s) {
	if (stop)
		return;

	if (n == len) {
		stop = true;
		cout << s << '\n';
	}
	else {
		for(int i=1; i<=3; i++)
			if(isSatisfy(s + to_string(i)))
				dfs(len+1, s + to_string(i));
	}
}

int main() {
	cin >> n;

	dfs(1, "1");

	return 0;
}