#include <cstdio>
#include <vector>

using namespace std;

int calcPow(int n) {
	if (n == 1)
		return 2;

	return 2 * calcPow(n - 1);
}

int main() {
	vector<int> v;
	int L, R;
	scanf("%d %d", &L, &R);

	while (true) {
		L = (L*R) / 100;

		if (L > 5)
			v.push_back(L);
		else
			break;
	}

	int len = v.size(), result = 0;

	if (len == 0) {
		printf("%d\n");
		return 0;
	}

	for (int i = 0; i < len; i++)
		result += v[i] * calcPow(i + 1);

	printf("%d\n", result);

	return 0;
}