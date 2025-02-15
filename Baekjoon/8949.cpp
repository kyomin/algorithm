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
	int idx = 0;	int len_A = A.size();
	int len_B = B.size();
	int short_len = min(len_A, len_B);

	// ����� ���Ǹ� ���� ���� ���� ���ڿ��� �����´�.
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());

	while (idx < short_len) {
		int n1 = (int)(A[idx] - '0');
		int n2 = (int)(B[idx] - '0');
		int sum = n1 + n2;

		string num = to_string(sum);
		reverse(num.begin(), num.end());
		ans += num;

		idx++;
	}

	if (len_A > len_B)
		ans += A.substr(idx, len_A);


	if (len_A < len_B)
		ans += B.substr(idx, len_B);

	// ������ ����� ���ڿ� ����� �ٽ� ������ �ش�.
	reverse(ans.begin(), ans.end());

	cout << ans << '\n';

	return 0;
}