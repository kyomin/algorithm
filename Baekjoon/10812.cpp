#include <iostream>
#include <vector>
using namespace std;

int main() {
	vector<int> originArr;
	int N, M;
	cin >> N >> M;

	originArr.resize(N);
	for (int i = 0; i < N; i++)
		originArr[i] = i + 1;

	for (int m = 0; m < M; m++) {
		vector<int> copyArr = originArr;
		int start, end, mid;
		cin >> start >> end >> mid;

		// 인덱스를 맞춰주기 위함
		start -= 1;
		end -= 1;
		mid -= 1;

		for (int i = start; i < start + (end - mid + 1); i++)
			copyArr[i] = originArr[mid + (i - start)];

		int startIndex = start + (end - mid + 1);
		for (int i = startIndex; i <= end; i++)
			copyArr[i] = originArr[start + (i - startIndex)];

		originArr = copyArr;
	}

	for (int i = 0; i < N - 1; i++)
		cout << originArr[i] << ' ';

	cout << originArr[N - 1] << endl;

	return 0;
}