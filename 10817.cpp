#include <iostream>
#include <list>
#include <vector>

using namespace std;

int main() {
	int arr[3];
	list<int> l;
	vector<int> v;

	for (int i = 0; i < 3; i++)
		cin >> arr[i];

	for (int i = 0; i < 3; i++)
		l.push_back(arr[i]);

	l.sort();

	for (auto iter = l.begin(); iter != l.end(); iter++)
		v.push_back(*iter);

	cout << v[1] << endl;

	return 0;
}