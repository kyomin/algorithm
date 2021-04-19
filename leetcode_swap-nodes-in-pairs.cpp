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
		// ���Ұ� ���� ���
		if (head == nullptr)
			return head;

		ListNode* prev = head;
		ListNode* next = head->next;

		// ���Ұ� �ϳ��� ���
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