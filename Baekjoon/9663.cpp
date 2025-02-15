#include <iostream>

using namespace std;

int N;
int col[15];
int result = 0;

bool promising(int i) {
	for (int j = 0; j < i; j++)
		/*
			새로운 퀸과 기존의 퀸이 같은 '열'에 있거나
			대각선에 있을 경우
		*/
		if (col[i] == col[j] || abs(col[i] - col[j]) == (i - j))
			return false;	// 놓을 수 없음

	return true;
}

void N_Queen(int i) {
	if (i == N)	// 체스판 끝에 놓여졌다면
		result += 1;
	else {
		for (int j = 0; j < N; j++) {
			col[i] = j;	// 현재 행의 j칸에 놓아본다.

			// i행의 j열에 놓은 것이 괜찮다면
			if (promising(i))
				// 다음으로 진행
				N_Queen(i + 1);
		}
	}
}

int main() {
	cin >> N;

	N_Queen(0);

	cout << result << endl;

	return 0;
}