#include <iostream>
#include <vector>

using namespace std;

vector<int> children;

// ��� ������ �����Ѱ�?
bool isAllEquity() {
	bool flag = true;
	int n = children[0];

	for (int i = 1; i < children.size(); i++) {
		if (n != children[i]) {
			flag = false;
			break;
		}
	}

	return flag;
}

// ¦���� ����
void supplyWithEvenNumber() {
	for (int i = 0; i < children.size(); i++)
		if (children[i] % 2 == 1)
			children[i] += 1;
}

// ���ݾ� �����ֱ�
void giveHalf() {
	vector<int> halfNums;

	for (int i = 0; i < children.size(); i++)
		halfNums.push_back(children[i] / 2);

	vector<int> copyHalfNums = halfNums;
	
	for (int i = 0; i < halfNums.size(); i++) {
		if (i == 0) {
			halfNums[i] += copyHalfNums[copyHalfNums.size() - 1];
			continue;
		}

		halfNums[i] += copyHalfNums[i - 1];
	}

	children = halfNums;
}

int main() {
	int T;
	cin >> T;

	for (int t = 0; t < T; t++) {
		children.clear();
		
		int N;
		cin >> N;

		children.resize(N);

		for (int i = 0; i < N; i++)
			cin >> children[i];

		// �� ó�� ¦���� ����
		supplyWithEvenNumber();

		int cnt = 0;
		while (!isAllEquity()) {
			giveHalf();
			supplyWithEvenNumber();
			cnt++;
		}

		cout << cnt << endl;
	}

	return 0;
}