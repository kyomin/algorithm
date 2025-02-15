#include <iostream>
#include <string>

using namespace std;

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		string num;
		cin >> num;

		int end_num = (int)(num[num.size() - 1] - '0');

		if (end_num % 2 == 0)
			cout << "even" << endl;
		else
			cout << "odd" << endl;
	}

	return 0;
}