#include <iostream>
#include <vector>
#include <string>

using namespace std;

// result : 만들고자 하는 문자열, temp : 만들어나가는 과정을 담기 위한 문자열
string result, temp="";
vector<string> A;
int N, answer=0;

// str : 새롭게 더하고자 하는 문자열
bool promising(string str) {
	int len_of_temp = temp.size();
	int len_of_result = result.size();
	int len_of_str = str.size();

	// 길이를 초과하는 경우 유망하지 않다.
	if (len_of_temp + len_of_str > len_of_result) {
		return false;
	}

	// 더하려는 문자열의 첫 글자가 일치하는지 검사한다.
	if (result[len_of_temp] != str[0]) {
		return false;
	}

	// 위의 2가지 경우를 통과한다면 유망하다.
	return true;
}

void dfs() {
	// 해답을 발견한 순간
	if (temp == result) {
		answer = 1;
		return;
	}

	// 중복 단어도 허용하므로 중복 체크 하지 않는다.
	for (int i = 0; i < N; i++) {
		if (promising(A[i])) {
			temp += A[i];
			dfs();

			if (answer == 1) {
				return;
			}

			// temp를 유망한 문자열과 더하기 전 상태로 되돌리기
			int prevLen = temp.size() - A[i].size();
			temp = temp.substr(0, prevLen);
		}
	}

	// for문을 돌며 더할 단어가 없다면 끝이다.
	return;
}

int main() {
	cin >> result;
	cin >> N;

	A.resize(N);

	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	dfs();

	cout << answer << '\n';

	return 0;
}