#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
	int reverse(int x) {
		bool isNegative = false;
		int low = pow(2, 31)*(-1);
		int high = pow(2, 31) - 1;

		// �ڷ����� �����÷ο츦 �����ϱ� ���� long long���� ����!
		long long ans = x;

		if (ans < 0) {
			isNegative = true;
			ans *= (-1);
		}

		string str_x = to_string(ans);
		string reversed_x = "";

		for (int i = str_x.size() - 1; i >= 0; i--)
			reversed_x += str_x[i];

		ans = atoll(reversed_x.c_str());

		if (isNegative)
			ans *= (-1);

		if (ans<low || ans>high)
			return 0;

		return (int)ans;
	}
};