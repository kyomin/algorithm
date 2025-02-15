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
			bit |= (1 << num);		// �ش� �ڸ��� ���ڿ� or ������ ������ �ֵ� ���� ó���� �ȴ�.
		} 
		else if (input == "remove") {
			cin >> num;
			bit &= ~(1 << num);		// �ش� �ڸ��� ���ڸ� 0���� ����� �����Ѵ�. �������� �����Ǿ� 1�̹Ƿ� �״�� ����
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
			bit ^= (1 << num);		// xor ������ ���� �ش� �κи� ����Ѵ�.
		}
		else if (input == "all") {
			bit = (1 << 21) - 1;	// 20�ڸ��� ��Ʈ�� 1�� �ٲ۴�.
		}
		else if (input == "empty") {
			bit = 0;
		}
	}

	return 0;
}