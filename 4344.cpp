#include <iostream>
#include <cstdlib>

using namespace std;

double roundf(double val) {
	val *= 1000;
	int judge = val - (int)val;  // �����ΰ� ������ ������ �Ҽ��θ� ���� �ȴ�.

	if (judge >= 0.5)
		val += 1;

	return val / 1000;
}

int main() {
	int C;   // �׽�Ʈ ���̽��� ��
	cin >> C;

	double * dptr = new double[C]; // �� �׽�Ʈ������ ��� �̻��� �л� ������ ��� ���� �迭.

	for (int i = 0; i < C; i++) {
		int N;   // �� ���̽� ���� �л��� ��
		int count = 0; // ����� �Ѵ� �л� ���� ���� ���� ����
		double sum = 0;
		double avrg;  // ��� ���!
		cin >> N;

		int * ptr = new int[N];   // �л��� ����ŭ �����Ҵ�

		for (int j = 0; j < N; j++)
			cin >> ptr[j];  // �׸�ŭ ���� �Է�

		for (int k = 0; k < N; k++)
			sum += ptr[k];

		avrg = sum / N;  // ��� ���

		for (int d = 0; d < N; d++)
			if (ptr[d] > avrg)   // ����� �Ѵ� ������ �߰ߵǸ�
				count++;        // ���� ����!

		dptr[i] = ((double)count / N) * 100;   // ����� ���
	}

	for (int i = 0; i < C; i++)
		printf("%.3f%\n", roundf(dptr[i] * 1000) / 1000);

	return 0;
}