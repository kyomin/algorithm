#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	string A, B;
	cin >> A >> B;

	string ans = "";
	int idx = 0;
	int carry = 0;
	int len_A = A.size();
	int len_B = B.size();
	int short_len = min(len_A, len_B);

	// 계산의 편의를 위해 각각 숫자 문자열을 뒤집는다.
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	for (int i = 0; i < short_len; i++) {
		int a = (int)(A[i] - '0');
		int b = (int)(B[i] - '0');
		int sum = a + b + carry;
		int r = sum % 10;

		ans += to_string(r);
		carry = sum / 10;
	}

	// 아직 길이가 더 길어 덧셈 작업이 남은 문자열 처리를 해준다.
	if (len_A > len_B) {
		for (int i = short_len; i < len_A; i++) {
			int a = (int)(A[i] - '0');
			int sum = a + carry;
			int r = sum % 10;

			ans += to_string(r);
			carry = sum / 10;
		}
	}

	if (len_A < len_B) {
		for (int i = short_len; i < len_B; i++) {
			int b = (int)(B[i] - '0');
			int sum = b + carry;
			int r = sum % 10;

			ans += to_string(r);
			carry = sum / 10;
		}
	}

	if (carry == 1)
		ans += "1";

	reverse(ans.begin(), ans.end());

	cout << ans << '\n';

	return 0;
}