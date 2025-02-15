#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	vector<int> v;
	vector<int> result;
	unsigned long sum = 0;
	int A, B, m;
	cin >> A >> B >> m;

	// 각 자릿수에 대해 입력
	for (int i = 0; i < m; i++) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	// A 진법을 10진수로 바꾸는 작업!
	for (int i = 0; i < m; i++) {
		int x = m - i - 1;
		sum += v[i] * (int)pow(A, x);
	}

	// 10진수를 B진법으로 바꾸는 작업
	while (sum >= B) {
		int r = sum % B;
		sum /= B;
		result.push_back(r);
	}

	result.push_back(sum);
	int len = result.size();

	for (int i = len - 1; i >= 0; i--)
		cout << result[i] << " ";

	cout << endl;

	return 0;
}