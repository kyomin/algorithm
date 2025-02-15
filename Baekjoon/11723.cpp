#include <iostream>
#include <string>

using namespace std;

int M, num, bit;
string input;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> M;

	for (int i = 0; i < M; i++) {
		input.clear();
		cin >> input;

		if (input == "add") {
			cin >> num;
			bit |= (1 << num);		// 해당 자리의 숫자에 or 연산을 적용해 있든 없든 처리가 된다.
		} 
		else if (input == "remove") {
			cin >> num;
			bit &= ~(1 << num);		// 해당 자리의 숫자만 0으로 만들어 제거한다. 나머지는 반전되어 1이므로 그대로 유지
		}
		else if (input == "check") {
			cin >> num;
			
			if (bit&(1 << num))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		else if (input == "toggle") {
			cin >> num;
			bit ^= (1 << num);		// xor 연산을 통해 해당 부분만 토글한다.
		}
		else if (input == "all") {
			bit = (1 << 21) - 1;	// 20자리의 비트를 1로 바꾼다.
		}
		else if (input == "empty") {
			bit = 0;
		}
	}

	return 0;
}