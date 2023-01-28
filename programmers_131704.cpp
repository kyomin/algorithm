#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<int> order) {
	stack<int> container;
	int now = 0;
	int index = 1;
	int size = order.size();

	while (index != size + 1) {
		container.push(index);

		while (container.top() == order[now]) {
			now += 1;
			container.pop();

			if (container.empty())
				break;
		}

		index += 1;
	}

	return now;
}