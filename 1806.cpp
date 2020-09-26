#include <iostream>
#include <algorithm>
#include <limits>

using namespace std;

int arr[100001];
const int INF = numeric_limits<int>::max();

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, S;
	int length = INF;
	int low = 0;
	int high = 0;
	int sum = 0;

	cin >> N >> S;

	for (int i = 0; i < N; i++)
		cin >> arr[i];
	
	sum = arr[0];

	while (low <= high && high < N) {
		/* 
			���� sum�� S���� ���� ��� high�� +1 �Ѵ�. 
		*/
		if (sum < S) {
			high += 1;
			sum += arr[high];
		}
		/* 
			���� sum�� S�� ���� ���, 
			���� length ���� high-low+1 ���� ����
			min�� length�� ���� �� 
			high�� +1 �Ѵ�.
		*/
		else if (sum == S) {
			length = min(length, (high - low + 1));
			high += 1;
			sum += arr[high];
		}
		/*
			���� sum�� S���� ū ���,
			���� length ���� high-low+1 ���� ����
			min�� length�� ���� ��
			low�� +1 �Ѵ�.
		*/
		else if (sum > S) {
			length = min(length, (high - low + 1));
			sum -= arr[low];
			low += 1;
		}
	}

	if (length == INF) cout << 0 << '\n';
	else cout << length << '\n';

	return 0;
}