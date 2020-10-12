#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<int> arr;
int N, K;
string str;

vector<string> split(string str, char delimiter) {
	vector<string> internal;
	stringstream ss(str);
	string temp;

	while (getline(ss, temp, delimiter))
		internal.push_back(temp);

	return internal;
}

void solution() {
	for (int i = 0; i < K; i++) {
		vector<int> temp;

		for (int j = 1; j < N; j++)
			temp.push_back(arr[j] - arr[j - 1]);

		arr = temp;
		N -= 1;
	}
}

int main() {
	cin >> N >> K;
	cin >> str;

	vector<string> temp;
	temp = split(str, ',');

	for (int i = 0; i < temp.size(); i++)
		arr.push_back(atoi(temp[i].c_str()));

	solution();

	for (int i = 0; i < N; i++) {
		cout << arr[i];

		if (i != N - 1)
			cout << ',';
	}

	cout << '\n';

	return 0;
}