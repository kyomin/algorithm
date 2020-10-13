#include <iostream>
#include <cstdlib>

using namespace std;

double roundf(double val) {
	val *= 1000;
	int judge = val - (int)val;  // 정수부가 떨어져 나가고 소수부만 남게 된다.

	if (judge >= 0.5)
		val += 1;

	return val / 1000;
}

int main() {
	int C;   // 테스트 케이스의 수
	cin >> C;

	double * dptr = new double[C]; // 각 테스트마다의 평균 이상의 학생 비율을 담기 위한 배열.

	for (int i = 0; i < C; i++) {
		int N;   // 각 케이스 마다 학생의 수
		int count = 0; // 평균을 넘는 학생 수를 세기 위한 변수
		double sum = 0;
		double avrg;  // 평균 담기!
		cin >> N;

		int * ptr = new int[N];   // 학생의 수만큼 동적할당

		for (int j = 0; j < N; j++)
			cin >> ptr[j];  // 그만큼 성적 입력

		for (int k = 0; k < N; k++)
			sum += ptr[k];

		avrg = sum / N;  // 평균 계산

		for (int d = 0; d < N; d++)
			if (ptr[d] > avrg)   // 평균을 넘는 점수가 발견되면
				count++;        // 수를 센다!

		dptr[i] = ((double)count / N) * 100;   // 백분율 계산
	}

	for (int i = 0; i < C; i++)
		printf("%.3f%\n", roundf(dptr[i] * 1000) / 1000);

	return 0;
}