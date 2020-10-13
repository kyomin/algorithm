#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> v;
	int N, X;
	cin >> N >> X;

	int * ptr = new int[N];

	for (int i = 0; i < N; i++)
		cin >> ptr[i];

	for (int i = 0; i < N; i++)
		if (ptr[i] < X)
			v.push_back(ptr[i]);

	for (int i = 0; i < v.size(); i++)
		cout << v.at(i) << " ";

	cout << endl;

	return 0;
}