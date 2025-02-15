#include <string>
#include <vector>
#include <set>

using namespace std;

vector<int> primes;
bool visit[7];

bool isPrime(int num) {
	if (num < 2)
		return false;

	for (int i = 2; i*i <= num; i++)
		if (num%i == 0)
			return false;
	
	return true;
}

void dfs(string numbers, int M, string vc) {
	if (vc.size() == M) {
		if (isPrime(atoi(vc.c_str())))
			primes.push_back(atoi(vc.c_str()));

		return;
	}

	for (int i = 0; i < numbers.size(); i++) {
		if (!visit[i]) {
			visit[i] = true;
			vc += numbers[i];

			dfs(numbers, M, vc);

			vc = vc.substr(0, vc.size() - 1);
			visit[i] = false;
		}
	}
}

int solution(string numbers) {
	int answer = 0;

	for (int i = 1; i <= numbers.size(); i++)
		dfs(numbers, i, "");

	set<int> s(primes.begin(), primes.end());
	answer = s.size();

	return answer;
}