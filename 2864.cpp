#include <iostream>
#include <string>

using namespace std;

int main() {
	string s1, s2;
	cin >> s1 >> s2;

	// find max
	string t1 = s1;
	string t2 = s2;

	int len1 = s1.size();
	int len2 = s2.size();

	for (int i = 0; i < len1; i++)
		if (t1[i] == '5')
			t1[i] = '6';

	for (int i = 0; i < len2; i++)
		if (t2[i] == '5')
			t2[i] = '6';

	int max = atoi(t1.c_str()) + atoi(t2.c_str());

	// initialize t1, t2 again
	t1 = s1;
	t2 = s2;

	// find min
	for (int i = 0; i < len1; i++)
		if (t1[i] == '6')
			t1[i] = '5';

	for (int i = 0; i < len2; i++)
		if (t2[i] == '6')
			t2[i] = '5';

	int min = atoi(t1.c_str()) + atoi(t2.c_str());

	cout << min << ' ' << max << '\n';

	return 0;
}