#include <string>
#include <vector>

using namespace std;

int pow(int x, int y) {
	if (y == 0)
		return 1;

	return x * pow(x, y - 1);
}

string decimalToReverseTripartite(int decimal) {
	string ret = "";

	while (decimal >= 3) {
		int q = decimal / 3;
		int r = decimal % 3;

		ret += to_string(r);
		decimal = q;
	}

	ret += to_string(decimal);

	return ret;
}

int tripartiteToDecimal(string tripartite) {
	int ret = 0;

	for (int i = 0; i < tripartite.size(); i++)
		ret += ((int)(tripartite[i] - '0')*pow(3, tripartite.size() - i - 1));

	return ret;
}

int solution(int n) {
	string reversedTripartite = decimalToReverseTripartite(n);
	int answer = tripartiteToDecimal(reversedTripartite);

	return answer;
}