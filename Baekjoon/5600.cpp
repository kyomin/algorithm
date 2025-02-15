#include <iostream>
#include <cstring>

using namespace std;

int componenets[301];
int query[1000][4];		// 검사 결과 저장

void init(int len) {
	for (int i = 1; i <= len; i++)
		componenets[i] = 2;
}

int main() {
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int a, b, c;
	cin >> a >> b >> c;

	// 전체 부품의 길이
	int len = a + b + c;

	init(len);

	int N;
	cin >> N;

	for (int n = 0; n < N; n++) {
		int i, j, k, r;
		cin >> i >> j >> k >> r;

		// r이 1일 경우에만 모두가 정상이므로
		if (r == 1) {
			componenets[i] = 1;
			componenets[j] = 1;
			componenets[k] = 1;
		}

		// 일단 검사 식 저장
		query[n][0] = i;
		query[n][1] = j;
		query[n][2] = k;
		query[n][3] = r;
	}

	for (int n = 0; n < N; n++) {
		// 이미 판단한 식이므로
		if (query[n][3] == 1)
			continue;

		// 결과가 불합격이라면
		int i, j, k;
		i = query[n][0];
		j = query[n][1];
		k = query[n][2];

		// 확실하게 하나가 불량이라고 말할 수 있는 상황에서만
		if (componenets[i] == 1 && componenets[j] == 1)
			componenets[k] = 0;
		else if (componenets[i] == 1 && componenets[k] == 1)
			componenets[j] = 0;
		else if (componenets[j] == 1 && componenets[k] == 1)
			componenets[i] = 0;
	}

	for (int i = 1; i <= len; i++)
		cout << componenets[i] << '\n';

	return 0;
}