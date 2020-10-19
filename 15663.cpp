#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int arr[10];
bool check[10];
vector<int> print_v;

void go() {
	if (print_v.size() == M) {
		for (auto i : print_v)
			cout << i << ' ';

		cout << '\n';

		return;
	}

	bool used[10001] = { false, };

	for (int i = 0; i < N; i++) {
		if (!used[arr[i]] && !check[i]) {
			check[i] = true;
			used[arr[i]] = true;
			print_v.push_back(arr[i]);

			go();

			print_v.pop_back();
			check[i] = false;
		}
	}
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++)
		cin >> arr[i];

	sort(arr, arr + N);

	go();

	return 0;
}