#include <iostream>
#include <string>

using namespace std;

int main() {
	string str1, str2, str3, str4;
	cin >> str1 >> str2 >> str3 >> str4;

	string num1 = str1 + str2;
	string num2 = str3 + str4;

	long long n1 = stoll(num1);
	long long n2 = stoll(num2);

	cout << n1 + n2 << endl;

	return 0;
}