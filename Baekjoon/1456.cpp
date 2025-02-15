#include <iostream>
#include <vector>
#include <cmath>

#define MAX 10000001	// 최대 크기인 10^14의 제곱근까지만 소수를 구함

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	long min, max;
	cin >> min >> max;

	// 소수 구하기
	vector<long> primes(MAX, 0);

	for (int i = 2; i < MAX; i++)
		primes[i] = i;

	for (int i = 2; i <= sqrt(MAX); i++) {
		// 소수가 아니면 skip
		if (primes[i] == 0)
			continue;


		// 소수이면 배수를 지워준다
		for (int j = i + i; j < MAX; j += i)
			primes[j] = 0;
	}

	// 거의 소수 구하기
	int count = 0;

	for (int i = 2; i < MAX; i++) {
		if (primes[i] != 0) {
			long temp = primes[i];

			// a^k <= b  =>  a <= ( b / a^(k-1) ) 꼴로 만들어 오버플로우 방지
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