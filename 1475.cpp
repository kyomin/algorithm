#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int arr[10];

int main() {
	string N;
	cin >> N;

	int len = N.size();

	// ������ ���� ������ ����Ѵ�.
	for (int i = 0; i < len; i++) {
		int num = (int)(N[i] - '0');
		arr[num] += 1;
	}

	int ans = 0;

	// 6�� 9 �̿��� ���ڸ� ������� �ִ븦 ���� ���Ѵ�.
	for (int i = 0; i < 10; i++) 
		if (i != 6 && i != 9)
			ans = max(ans, arr[i]);

	// 6�� 9�� ������� �ʿ��� ��Ʈ�� ���Ѵ�.
	ans = max(ans, (arr[6] + arr[9] + 1) / 2);

	cout << ans << endl;

	return 0;
}