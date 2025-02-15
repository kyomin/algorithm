#include <string>
#include <vector>
#include <cmath>
using namespace std;

bool isPrime(long long num) {
	if (num == 2) return true;
	if (num == 1 || num % 2 == 0) return false;
	
	for (long long i = 3; i < (long long)sqrt(num) + 1; i += 1) {
		if (num % i == 0)
			return false;
	}

	return true;
}

string convert(int num, int base) {
	int q = num / base;
	int r = num % base;

	if (q)
		return convert(q, base) + to_string(r);
	else
		return to_string(r);	// base case
}

int solution(int n, int k) {
	string number = k == 10 ? to_string(n) : convert(n, k);
	int answer = 0;
	int len = number.length();
	string value = "";

	for (int i = 0; i < len; i++) {
		char ch = number[i];
		if (ch != '0') {
			value += ch;
			continue;
		}

		if (value.length() == 0)
			continue;

		if (isPrime(stol(value)))
			answer++;

		value = "";
	}

	if (value.length() != 0 && isPrime(stol(value)))
		answer++;
		
	return answer;
}