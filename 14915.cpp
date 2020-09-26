#include <iostream>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

int main() {
	map<int, string> m;

	m[10] = "A";
	m[11] = "B";
	m[12] = "C";
	m[13] = "D";
	m[14] = "E";
	m[15] = "F";

	string result = "";

	int M, N;
	cin >> M >> N;

	while (M >= N) {
		if (M % N < 10)
			result += to_string(M%N);
		else
			result += m.find(M%N)->second;

		M /= N;
	}

	if (M < 10)
		result += to_string(M);
	else
		result += m.find(M)->second;

	reverse(result.begin(), result.end());

	cout << result << '\n';

	return 0;
}