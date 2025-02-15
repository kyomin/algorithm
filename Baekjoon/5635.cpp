#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

struct Student {
	string name;
	int birth;
};

bool comp(const Student& s1, const Student& s2) {
	if (s1.birth < s2.birth)
		return true;
	else
		return false;
}

int main() {
	vector<Student> students;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		string name, day, month, year;
		cin >> name >> day >> month >> year;

		if (month.length() == 1)
			month = "0" + month;

		if (day.length() == 1)
			day = "0" + day;

		string birth = year + month + day;

		Student student;
		student.name = name;
		student.birth = atoi(birth.c_str());
		students.push_back(student);
	}

	sort(students.begin(), students.end(), comp);

	Student yongest = students[students.size() - 1];
	Student oldest = students[0];

	cout << yongest.name << endl;
	cout << oldest.name << endl;

	return 0;
}