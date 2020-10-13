#include <iostream>
#include <vector>

using namespace std;

int main() {
	while (true) {
		vector<int> v;
		int sum = 1;
		int N;
		cin >> N;
		v.push_back(1);

		if (N == -1)
			break;
		
		for (int i = 2; i <= N / 2; i++) {
			if (N%i == 0) {
				sum += i;
				v.push_back(i);
			}
		}

		if (sum == N) {
			cout << N << " = ";
			
			for (int k = 0; k < v.size(); k++){
				if (k == v.size() - 1)
					cout << v[k] << endl;
				else
					cout << v[k] << " + ";
			}
		}
		else
			cout << N << " is NOT perfect." << endl;
	}

	return 0;
}