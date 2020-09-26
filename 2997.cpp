#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int nums[3];
	int num;

	for (int i = 0; i < 3; i++)
		cin >> nums[i];

	sort(nums, nums + 3);

	if ((nums[1] - nums[0]) == (nums[2] - nums[1]))
		num = nums[2] + (nums[1] - nums[0]);
	else if ((nums[1] - nums[0]) < (nums[2] - nums[1]))
		num = nums[1] + ((nums[1] - nums[0]));
	else
		num = nums[0] + (nums[2] - nums[1]);

	cout << num << endl;

	return 0;
}