#include <iostream>
#include <string>

using namespace std;

int ans = 0;

void judge369(string str) {
	int len = str.size();

	for (int i = 0; i < len; i++)
		if (str[i] == '3' || str[i] == '6' || str[i] == '9')
			ans++;
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i <= N; i++)
		judge369(to_string(i));

	cout << ans << '\n';

	return 0;
}