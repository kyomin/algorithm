// Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode *next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
	ListNode* swapPairs(ListNode* head) {
		// 원소가 없는 경우
		if (head == nullptr)
			return head;

		ListNode* prev = head;
		ListNode* next = head->next;

		// 원소가 하나인 경우
		if (next == nullptr)
			return head;

		while (prev != nullptr && next != nullptr) {
			int temp = next->val;
			next->val = prev->val;
			prev->val = temp;

			prev = next->next;

			if (prev != nullptr)
				next = prev->next;
		}

		return head;
	}
};