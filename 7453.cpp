#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
const int MAX = 4001;
const int DOUBLE_MAX = MAX * MAX;

vector<ll> AB;
vector<ll> CD;
long A[MAX], B[MAX], C[MAX], D[MAX];

int main() {
	int N;
	cin >> N;

	AB.resize(N*N);
	CD.resize(N*N);

	for (int i = 0; i < N; i++)
		cin >> A[i] >> B[i] >> C[i] >> D[i];

	// AB, CD 배열 만들기 
	int idx = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			AB[idx] = A[i] + B[j];
			CD[idx] = C[i] + D[j];
			idx += 1;
		}
	}
	// 이분 탐색으로 찾을 기준 배열만 정렬
	sort(CD.begin(), CD.end());

	ll cnt = 0;
	
	for (int i = 0; i < N*N; i++) {
		int num = AB[i];
		int target = (-1)*num;

		long lower = lower_bound(CD.begin(), CD.end(), target) - CD.begin();
		long upper = upper_bound(CD.begin(), CD.end(), target) - CD.begin();

		cnt += (upper - lower);
	}

	cout << cnt << '\n';

	return 0;
}