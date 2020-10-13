#include <iostream>
#include <string>
#include <sstream>

using namespace std;

// int -> string convert function
string intToString(int n) {
	stringstream s;
	s << n;
	return s.str();
}

int d(string str) {
	int len = str.size();
	int sum = 0;

	for (int i = 0; i < len; i++)
		sum += (int)(str[i] - '0');

	sum += atoi(str.c_str());

	return sum;
}

int main() {
	// 빠른 입출력을 위한 선언!
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// 인덱스 10000까지의 배열 동적할당!
	int *A = new int[10001];

	// 배열의 값을 모두 1로 초기화!
	for (int i = 1; i <= 10000; i++)
		A[i] = 1;

	for (int i = 1; i <= 10000; i++) {
		string s = intToString(i);

		// 셀프넘버가 아닌 값이 리턴되므로
		int idx = d(s);

		// 인덱스 범위 내에 있으면
		if (idx <= 10000)
			// 0(false)로 바꿔준다.
			A[idx] = 0;
	}

	// 위의 작업이 다 끝났으면 셀프 넘버인 것을 출력!
	for (int i = 1; i <= 10000; i++)
		if (A[i] == 1)
			cout << i << '\n';

	return 0;
}