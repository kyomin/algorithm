#include <iostream>
#include <vector>

using namespace std;

int main() {
	vector<int> arr;
	int N, M;
	cin >> N >> M;

	arr.resize(N);

	for (int i = 0; i < N; i++)
		arr[i] = i + 1;

	for (int m = 0; m < M; m++) {
		int start, end;
		cin >> start >> end;

		// 인덱스를 맞춰주기 위함
		--start;
		--end;

		vector<int> tmp;

		for (int i = 0; i < start; i++)
			tmp.push_back(arr[i]);

		for (int i = end; i >= start; i--)
			tmp.push_back(arr[i]);

		for (int i = end + 1; i < N; i++)
			tmp.push_back(arr[i]);

		arr = tmp;
	}

	for (int i = 0; i < N; i++)
		cout << arr[i] << ' ';

	cout << '\n';

	return 0;
}