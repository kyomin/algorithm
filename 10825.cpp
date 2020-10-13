#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef struct student {
	string name;
	int korean;
	int english;
	int math;

}Student;

bool com(const Student &s1, const Student &s2) {
	if (s1.korean > s2.korean)
		return true;
	else if (s1.korean == s2.korean) {
		if (s1.english < s2.english)
			return true;
		else if (s1.english == s2.english) {
			if (s1.math > s2.math)
				return true;
			else if (s1.math == s2.math) {
				if (s1.name < s2.name)
					return true;
				else
					return false;
			}
			else
				return false;
		}
		else
			return false;
	}
	else
		return false;
}

int main() {
	int N;
	vector<Student> v;

	cin >> N;

	for (int i = 0; i < N; i++) {
		string str;
		int k, e, m;

		cin >> str >> k >> e >> m;

		Student s;
		s.name = str;
		s.korean = k;
		s.english = e;
		s.math = m;

		v.push_back(s);
	}

	sort(v.begin(), v.end(), com);

	for (int i = 0; i < N; i++)
		cout << v[i].name << '\n';

	return 0;
}