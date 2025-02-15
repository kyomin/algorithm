#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

using namespace std;

// �������� ����
bool comp(const int &n1, const int &n2) {
	if (n1 > n2)
		return true;
	else
		return false;
}

// 16���� ���ڸ� 10������
int hexCharToDec(char ch) {
	if (ch == 'A')
		return 10;

	if (ch == 'B')
		return 11;

	if (ch == 'C')
		return 12;

	if (ch == 'D')
		return 13;

	if (ch == 'E')
		return 14;

	if (ch == 'F')
		return 15;

	// ���ڰ� �ƴ� ���ڶ��
	return (int)(ch - '0');
}

int pow(int x, int y) {
	if (y == 0)
		return 1;

	return x * pow(x, y - 1);
}

int hexToDec(string hex) {
	int len = hex.size();
	int sum = 0;

	for (int i = 0; i < len; i++)
		sum += (hexCharToDec(hex[i])*pow(16, len - i - 1));


	return sum;
}

// 16���� ���ڿ��� 4������� ���� �����Ѵ�.
vector<string> sliceHexString(string hex, int slice_unit) {
	vector<string> ret;
	int len = hex.size();

	for (int i = 0; i < len; i += slice_unit)
		ret.push_back(hex.substr(i, slice_unit));

	return ret;
}

int main() {
	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		set<int> s;
		string hex;
		int N, K;
		cin >> N >> K;
		cin >> hex;

		int slice_unit = N / 4;
		int len = hex.size();

		// ���⼭ �Է¹��� hex ���ڿ��� rotate �ϸ鼭 ������� ��´�!
		for (int i = 0; i < len; i++) {
			char temp = hex[len - 1];

			for (int j = len - 1; j >= 1; j--)
				hex[j] = hex[j - 1];

			hex[0] = temp;

			vector<string> v = sliceHexString(hex, slice_unit);

			for (int j = 0; j < v.size(); j++)
				s.insert(hexToDec(v[j]));
		}

		vector<int> nums;
		for (auto iter = s.begin(); iter != s.end(); iter++)
			nums.push_back(*iter);

		sort(nums.begin(), nums.end(), comp);

		cout << '#' << t << ' ' << nums[K - 1] << '\n';
	}

	return 0;
}