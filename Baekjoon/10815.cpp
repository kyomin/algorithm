#include <iostream>
#include <vector>
#include <list>

using namespace std;

bool com(int n1, int n2) {
	if (n1 < n2)
		return true;
	else
		return false;
}

// Binary Search function
bool BSearch(int *ptr, int len, int target) {
	int first = 0;
	int last = len - 1;
	int mid = 0;

	while (first <= last) {
		mid = (first + last) / 2;
		
		if (ptr[mid] == target)
			return true;
		else {
			if (ptr[mid] > target)
				last = mid - 1;
			else
				first = mid + 1;
		}
	}

	return false;
}

int main() {
	int N;
	vector<int> v;
	list<int> l;

	cin >> N;

	int *A = new int[N];

	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		l.push_back(n);
	}

	l.sort(com);

	list<int>::iterator iter = l.begin();

	for (int i = 0; i < N; i++) {
		A[i] = *iter;
		iter++;
	}

	int M;
	cin >> M;

	int *B = new int[M];

	for (int i = 0; i < M; i++) {
		int n;
		cin >> n;
		B[i] = n;
	}

	for (int i = 0; i < M; i++) {
		// if find target
		if (BSearch(A, N, B[i]))
			v.push_back(1);
		else
			v.push_back(0);
	}

	int len = v.size();

	for (int i = 0; i < len; i++)
		cout << v[i] << ' ';

	cout << endl;

	return 0;
}