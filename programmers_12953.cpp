#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

int solution(vector<int> arr) {
	int len = arr.size();

	if (len == 1)
		return arr[0];

	int g = gcd(arr[0], arr[1]);
	int l = (arr[0] * arr[1]) / g;

	for (int i = 2; i < len; i++) {
		int n = arr[i];
		g = gcd(n, l);
		l = (l*n) / g;
	}

	return l;
}