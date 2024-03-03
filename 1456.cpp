#include <iostream>
#include <vector>
#include <cmath>

#define MAX 10000001	// �ִ� ũ���� 10^14�� �����ٱ����� �Ҽ��� ����

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long min, max;
	cin >> min >> max;

	// �Ҽ� ���ϱ�
	vector<long> primes(MAX, 0);

	for (int i = 2; i < MAX; i++)
		primes[i] = i;

	for (int i = 2; i <= sqrt(MAX); i++) {
		// �Ҽ��� �ƴϸ� skip
		if (primes[i] == 0)
			continue;


		// �Ҽ��̸� ����� �����ش�
		for (int j = i + i; j < MAX; j += i)
			primes[j] = 0;
	}

	// ���� �Ҽ� ���ϱ�
	int count = 0;

	for (int i = 2; i < MAX; i++) {
		if (primes[i] != 0) {
			long temp = primes[i];

			// a^k <= b  =>  a <= ( b / a^(k-1) ) �÷� ����� �����÷ο� ����
			while ((double)primes[i] <= (double)max / (double)temp) {
				if ((double)primes[i] >= (double)min / (double)temp) 
					count++;
				
				temp *= primes[i];
			}
		}
	}

	cout << count << endl;

	return 0;
}