#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
int result;	// 결과를 담기 위한 변수
vector<int> v;	// 카드들을 담는 벡터

// params : 인덱스, 현재까지 선택한 카드 갯수, 그 합
void sumOfCards(int idx, int cnt, int sum) {
	// 조건을 만족할 경우
	if (cnt == 3 && sum <= M) {
		// 기존 result에 담긴 값과 비교 후 큰 것을 담기
		result = max(result, sum);
		return;
	}

	// 기저 사례(탈출 사례)
	if (idx >= N || cnt > 3 || sum > M)
		return;

	// 해당 카드를 선택
	sumOfCards(idx + 1, cnt + 1, sum + v[idx]);

	// 해당 카드 선택 X
	sumOfCards(idx + 1, cnt, sum);
}

int main() {
	result = 0;
	cin >> N >> M;

	// 카드 담기
	v.resize(N);	// 벡터 크기 설정
	for (int i = 0; i < N; i++)
		cin >> v[i];

	// 브루트 포스 시작!
	sumOfCards(0, 0, 0);

	cout << result << '\n';

	return 0;
}