#include <iostream>
#include <string>

using namespace std;

typedef unsigned long long ll;

int nums[10];

int main() {
	ll A, B, C;
	cin >> A >> B >> C;

	ll mul = (A * B * C);

	string mul_str = to_string(mul);
	int len = mul_str.length();

	for (int i = 0; i < len; i++) {
		int idx = (int)(mul_str[i] - '0');

		nums[idx]++;
	}

	for (int i = 0; i < 10; i++)
		cout << nums[i] << endl;

	return 0;
}