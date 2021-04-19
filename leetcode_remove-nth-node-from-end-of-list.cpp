#include <vector>
#include <algorithm>

using namespace std;

// Definition for singly-linked list.
// ���ڵ� �󿡼� �̹� ���ǵ� �ִٴ� ������ �����Ƿ� ���� �ÿ��� �� struct ����� ����!
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		vector<int> lists;
		ListNode* cur = head;

		// lists�� front�� ���� ����Ʈ�� ���� �����Ѵ�.
		while (cur != nullptr) {
			vector<int>::iterator it;
			it = lists.begin();
			lists.insert(it, cur->val);
			cur = cur->next;
		}

		// �ڿ������� n��°�� ���� �����ȴ�.
		vector<int>::iterator it = (lists.begin() + (n - 1));
		lists.erase(it);

		// �ٽ� ����� ���� �����´�.
		reverse(lists.begin(), lists.end());

		// ����� ���� ����Ʈ�� �����ϴ� �۾��� �����Ѵ�.
		ListNode* ret = nullptr;

		// ���Ұ� �ϳ��� �� ������ �� ��츦 �����Ѵ�.
		if (lists.size() >= 1) {
			// cur�� �ű�� �����ϱ� ������, ret�� ù ��° head�� �������� ����Ű�� �ȴ�.
			ret = new ListNode();
			cur = ret;

			for (int i = 0; i < lists.size(); i++) {
				cur->val = lists[i];

				// �� ������ ���ҿ����� ���� ��带 ���� �ʿ䰡 ����.
				if (i < lists.size() - 1) {
					cur->next = new ListNode();
					cur = cur->next;
				}
			}
		}

		return ret;
	}
};