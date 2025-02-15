#include <iostream>
#include <vector>
#include <string>
#include <sstream>
using namespace std;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter)) {
		internal.push_back(temp);
	}

	return internal;
}

int main() {
	string birthday;
	string standard;

	getline(cin, birthday);
	getline(cin, standard);

	vector<string> birthdayInfos = split(birthday, ' ');
	vector<string> standardInfos = split(standard, ' ');

	int birthdayYear = atoi(birthdayInfos[0].c_str());
	int birthdayMonth = atoi(birthdayInfos[1].c_str());
	int birthdayDay = atoi(birthdayInfos[2].c_str());

	int standardYear = atoi(standardInfos[0].c_str());
	int standardMonth = atoi(standardInfos[1].c_str());
	int standardDay = atoi(standardInfos[2].c_str());

	int age1 = standardYear == birthdayYear ? 0 : standardYear - birthdayYear;	// �� ����
	int age2 = standardYear - birthdayYear + 1;	// ���� ����
	int age3 = standardYear - birthdayYear;	// �� ����

	if (age1) {
		// �� ������ ��� ������ �������� ���� �Ǵ��ϱ�
		if (standardMonth < birthdayMonth || (birthdayMonth == standardMonth && standardDay < birthdayDay))
			age1 -= 1;			
	}

	cout << age1 << endl;
	cout << age2 << endl;
	cout << age3 << endl;

	return 0;
}