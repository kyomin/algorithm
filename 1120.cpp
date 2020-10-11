#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	int len1 = s1.size();
	int len2 = s2.size();
	int dif = len2 - len1;
	int min = 0;

	for (int i = 0; i < dif + 1; i++) {
		int count = 0;

		for (int j = 0; j < len1; j++)
			if (s1[j] != s2[j + i])
				count++;

		// 처음이라면 일단 다른 횟수로 초기화!
		if (i == 0)
			min = count;

		if (min >= count)
			min = count;
	}

	cout << min << endl;

	return 0;
}