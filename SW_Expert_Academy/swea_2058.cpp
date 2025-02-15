#include <iostream>
#include <string>

using namespace std;

int main() {
	int N;
	cin >> N;

	string num = to_string(N);
	int len = num.size();
	int sum = 0;

	for (int i = 0; i < len; i++)
		sum += (int)(num[i] - '0');

	cout << sum << '\n';

	return 0;
}