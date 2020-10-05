#include <string>
#include <vector>

using namespace std;

int gcd(int a, int b) {
	while (b != 0) {
		int r = a % b;
		a = b;
		b = r;
	}

	return a;
}

vector<int> solution(int n, int m) {
	vector<int> answer;
	int G = gcd(n, m);
	int L = (n*m) / G;

	answer.push_back(G);
	answer.push_back(L);

	return answer;
}