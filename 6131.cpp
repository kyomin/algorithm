#include <iostream>

using namespace std;

int main() {
	int ans = 0;
	int n;
	cin >> n;
	for (int i = 1; i <= 500; i++)
		for (int j = i; j <= 500; j++)
			if (j*j == i * i + n)
				ans++;

	cout << ans << '\n';
}