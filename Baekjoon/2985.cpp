#include <iostream>

using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;

	if (a + b == c)
		printf("%d+%d=%d\n", a, b, c);
	else if (a - b == c)
		printf("%d-%d=%d\n", a, b, c);
	else if (a*b == c)
		printf("%d*%d=%d\n", a, b, c);
	else if (a / b == c)
		printf("%d/%d=%d\n", a, b, c);
	else if (a == b + c)
		printf("%d=%d+%d", a, b, c);
	else if (a == b - c)
		printf("%d=%d-%d", a, b, c);
	else if (a == b * c)
		printf("%d=%d*%d", a, b, c);
	else if (a == b / c)
		printf("%d=%d/%d", a, b, c);
	else if (a == b && b == c)
		printf("%d=%d=%d", a, b, c);

	return 0;
}