#include <iostream>
#include <string>

using namespace std;

int main() {
	int ans;
	int N;
	cin >> N;

	for (int i = 4; i <= N; i++) {
		string str = to_string(i);
		int len = str.size();
		int judge = 0;

		for (int j = 0; j < len; j++) {
			if (str[j] != '4' && str[j] != '7') {
				judge = 1;
				break;
			}
		}

		if (judge == 0)
			ans = i;
	}

	cout << ans << endl;

	return 0;
}