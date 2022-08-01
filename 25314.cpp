#include <iostream>
#include <string>
using namespace std;

int main() {
	string result = "";
	int N;
	cin >> N;

	int cnt = N / 4;

	for (int i = 0; i < cnt; i++) 
		result += "long ";
	
	result += "int";

	cout << result << endl;

	return 0;
}