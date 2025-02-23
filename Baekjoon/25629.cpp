#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<int> arr(N);

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	vector<int> even;
	vector<int> odd;

	for (int i = 0; i < N; i++) {
		int num = arr[i];

		if (num % 2 == 0)
			even.push_back(num);
		else
			odd.push_back(num);
	}

	int even_len = even.size();
	int odd_len = odd.size();
	int ans = 0;

	if (N % 2 == 0) {
		if (even_len == odd_len)
			ans = 1;
	}
	else {
		if (even_len == odd_len - 1)
			ans = 1;
	}

	cout << ans << endl;

	return 0;
}