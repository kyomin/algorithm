#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string decimalToBinary(int decimal, int n) {
	string binaryString = "";

	// 10진수를 2진수로 변환
	while (decimal > 0) {
		binaryString += (decimal % 2) ? '1' : '0';
		decimal /= 2;
	}

	// 변환된 2진수를 뒤집어야 실제 2진수 순서가 됨
	reverse(binaryString.begin(), binaryString.end());

	// N 길이에 맞춰 앞에 0을 채워야 함
	if (binaryString.size() < n) {
		binaryString = std::string(n - binaryString.size(), '0') + binaryString;
	}
	
	return binaryString;
}


vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;

	vector<string> binaryArr1;
	vector<string> binaryArr2;

	for (int i = 0; i < n; i++) {
		binaryArr1.push_back(decimalToBinary(arr1[i], n));
		binaryArr2.push_back(decimalToBinary(arr2[i], n));
	}

	for (int r = 0; r < n; r++) {
		string binary1 = binaryArr1[r];
		string binary2 = binaryArr2[r];

		string answerRow = "";

		for (int c = 0; c < n; c++) {
			if (binary1[c] == '0' && binary2[c] == '0') {
				answerRow += ' ';
			}
			else {
				answerRow += '#';
			}
		}

		answer.push_back(answerRow);
	}

	return answer;
}