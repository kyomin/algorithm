#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> numbers) {
	int len = numbers.size();
	
	sort(numbers.begin(), numbers.end());

	return max((numbers[0] * numbers[1]), (numbers[len - 2] * numbers[len - 1]));
}