#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

typedef struct person {
	int age;
	string name;
	int order;
}Person;

bool com(const Person &p1, const Person &p2) {
	if (p1.age < p2.age)
		return true;
	else if (p1.age == p2.age) {
		if (p1.order < p2.order)
			return true;
		else
			return false;
	}
	else
		return false;
}

int main() {
	vector<Person> v;
	int count = 1;
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		int n;
		string str;

		cin >> n >> str;

		Person p;
		p.age = n;
		p.name = str;
		p.order = count;

		v.push_back(p);

		count++;
	}

	sort(v.begin(), v.end(), com);

	for (int i = 0; i < N; i++)
		cout << v[i].age << ' ' << v[i].name << '\n';

	return 0;
}