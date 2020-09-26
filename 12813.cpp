#include <iostream>
#include <string>

using namespace std;

string andOper(string str1, string str2) {
	int len = str1.size();
	
	string result = "";

	for (int i = 0; i < len; i++) {
		if (str1[i] == '1' && str2[i] == '1')
			result += "1";
		else
			result += "0";
	}

	return result;
}

string orOper(string str1, string str2) {
	int len = str1.size();

	string result = "";

	for (int i = 0; i < len; i++) {
		if (str1[i] == '0' && str2[i] == '0')
			result += "0";
		else
			result += "1";
	}

	return result;
}

string xorOper(string str1, string str2) {
	int len = str1.size();

	string result = "";

	for (int i = 0; i < len; i++) {
		if (str1[i] != str2[i])
			result += "1";
		else
			result += "0";
	}

	return result;
}

string notOper(string str) {
	int len = str.size();

	string result = "";
	
	for (int i = 0; i < len; i++) {
		if (str[i] == '1')
			result += "0";
		else
			result += "1";
	}

	return result;
}

int main() {
	string A, B;

	cin >> A >> B;

	cout << andOper(A, B) << '\n';
	cout << orOper(A, B) << '\n';
	cout << xorOper(A, B) << '\n';
	cout << notOper(A) << '\n';
	cout << notOper(B) << '\n';

	return 0;
}